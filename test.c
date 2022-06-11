#include <stdio.h>
#include <math.h>
#include <libft.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <Carbon/Carbon.h>
#include <mlx.h>
#define MLX_ERROR 1
#define WIN_ERROR 2
#define PURPLE 0x00FFFFFF
#define IMG_W 500
#define IMG_H 500
#define GAMMA 0.43

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_vars {
	t_data	data;
	t_img	img;
}	t_vars;

//since mlx_pixel_put works slowly but fast enough to cause tearing
//we make our own function to put data in the image unidimetional array
//and then use mlx_put_image_to_window to push image to the window
//if (img->endian != 0)
//big endian, MSB is the leftmost bit
//else
//little endian, LSB is the leftmost bit
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bits_per_pixel - 8;
    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}

//instead of doing any math it pushes the values to their positions
//		int t = 00000000 00000000 000000000 aaaaaaaa
//		int r = 00000000 00000000 000000000 00rrrrrr
//		int g = 00000000 00000000 000000000 gggggggg
//		int b = 00000000 00000000 000000000 000000bb
//		t<<24 = aaaaaaaa 00000000 000000000 00000000
//		r<<16 = 00000000 00rrrrrr 000000000 00000000
//      g<<8  = 00000000 00000000 ggggggggg 00000000
//	  t|r|g|b = aaaaaaaa 00rrrrrr ggggggggg 000000bb
//
//the x = x & 0xFF; caps x value to a max of 255 so it doesnt overflow
int	create_trgb(int t, int r, int g, int b)
{
	r = r & 0xFF;
	g = g & 0xFF;
	b = b & 0xFF;
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

//for keypresses macOS uses Carbon.HIToolbox.Events.h
//and in Linux it uses X11's X11/keysymdef.h
//Note that for example "5" and "ESC"
//create the same value in X11 or Cocoa
//So using something like
//keysym == kVK_Escape || keysym == XK_Escape
//is not a good idea
int	keypress(int keysym, t_data *data)
{
	ft_printf("%#010X\n", keysym);
	if (keysym == kVK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

/**
 * @brief Closes window and frees memory
 * 
 * @param data Data struct used in this program
 * @param error 0 if successfull 
 * @return int 
 */
int quit(t_data *data, int error)
{
	ft_printf("%d", error);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(error);
}


//Convert color from 0..255 to 0..1
//Inverse Srgb Companding for 
//Red, Green, and Blue
double	*InverseSrgbCompanding(int c)
{
    double  *r = malloc(4 * sizeof(double));

	r[0] = (double) get_t(c);
    r[1] = ChannelInvCompanding(get_r(c));
    r[2] = ChannelInvCompanding(get_g(c));
    r[3] = ChannelInvCompanding(get_b(c));

    return (r);
}

//Returns a linear value in the range [0,1]
//for sRGB input in [0,255].
double ChannelInvCompanding(int c)
{
	double y;

	c = c & 0xFF;
	c /= 255.0;
    if (c <= 0.04045)
        y = c / 12.92;
    else
        y = pow(((c + 0.055) / 1.055), 2.4);
    return (y);
}

//return new color. Convert 0..1 back into 0..255
//Srgb Companding for Red, Green, and Blue
int SrgbCompanding(double *c)
{
    int t;
	int	r;
	int	g;
	int	b;

	t = (int)c[0];
    r = (int)(ChannelCompanding(c[1]) * 255);
    g = (int)(ChannelCompanding(c[2]) * 255);
    b = (int)(ChannelCompanding(c[3]) * 255);
    free(c);
    return (create_trgb(t, r, g, b));
}

//Apply companding to Red, Green, and Blue
double ChannelCompanding(double c)
{
	double x;

	if (c <= 0.0031308)
		x = 12.92 * c; 
	else
		x = (1.055 * pow(c, (1/2.4))) - 0.055;
	return (x);
}

//sums channels
//does not include transperancy
double sumChannels(double *c)
{
    return (c[1] + c[2] + c[3]);
}

//Lerping see
//https://en.wikipedia.org/wiki/Linear_interpolation
//#Programming_language_support
double lerp_int(double c1, double c2, double t)
{
	return ((1 - t) * c1 + t * c2);
}

double	*lerp(double *c1, double *c2, double t)
{
	double  *r = malloc(4 * sizeof(double));

	r[1] = ((1 - t) * c1[1] + t * c2[1]);
    r[2] = ((1 - t) * c1[2] + t * c2[2]);
    r[3] = ((1 - t) * c1[3] + t * c2[3]);
	return (r);
}

void	fix(double *c, double intensity, int total)
{
    c[1] = (c[1] * intensity / total);
    c[2] = (c[2] * intensity / total);
    c[3] = (c[3] * intensity / total);
}

int sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

int	calculate_color_step()
{
	intensity = pow(lerp_int(bright1, bright2, step), (1 / GAMMA));
    clr = lerp(color1_lin, color2_lin, step);
	total = sumChannels(color);
    if (total != 0)
		fix(&color, intensity, total);
   	color = SrgbCompanding(clr);
}

typedef struct s_bresvars {
	int x; 
	int y;
	int dx; 
	int dy;
	int s1; 
	int s2;
	int swap;
	int temp;
	int d;
	int i;
}	t_bresvars;

typedef struct s_calcol {
	double	*color1_lin;
    double	bright1;
	double	*color2_lin;
    double	bright2;
	double	intensity;
	double	*clr;
	int color;
	int step;
	int total;
}	t_calcol;

void	bresenhams_alg(int x1, int y1, int x2, int y2, int scolor, int ecolor, t_vars *vars)
{
	t_bresvars v;
	t_calcol c;

    c.color1_lin = InverseSrgbCompanding(scolor);
    c.bright1 = pow(sumChannels(c.color1_lin), GAMMA);
    c.color2_lin = InverseSrgbCompanding(ecolor);
    c.bright2 = pow(sumChannels(c.color2_lin), GAMMA);

	v.x = x1; 
	v.y = y1;
	v.dx = abs(x2 - x1); 
	v.dy = abs(y2 - y1);
	v.s1 = sign(x2 - x1); 
	v.s2 = sign(y2 - y1);
	v.swap = 0;

	if (v.dy > v.dx) {
		v.temp = v.dx;
		v.dx = v.dy;
		v.dy = v.temp;
		v.swap = 1;
	}

	v.d = 2*v.dy - v.dx;
	c.step = 100 / v.dx;
	v.i = 0;
	while (v.i < v.dx)
	{
		c.color = calculate_color_step(c.step);
		my_mlx_pixel_put(&vars->img, v.x, v.y, c.color); 
		while (v.d >= 0)
		{ 
			v.d = v.d - 2 * v.dx;
			if (v.swap)
				v.x += v.s1;
			else
				v.y += v.s2;
		} 
		v.d = v.d + 2 * v.dy;
		if (v.swap)
			v.y += v.s2;
		else
			v.x += v.s1;
		v.i++;
	}
	free(c.color1_lin);
	free(c.color2_lin);
}

int render(t_vars *vars)
{
	if (vars->data.win_ptr != NULL)
		bresenhams_alg(0, 0, IMG_W, IMG_H, vars);
		bresenhams_alg(IMG_W, 0, 0, IMG_H, vars);
		bresenhams_alg(0, IMG_H / 2, IMG_W, IMG_H / 2, vars);
		bresenhams_alg(IMG_W / 2, 0, IMG_W / 2, IMG_H, vars);
		mlx_put_image_to_window(vars->data.mlx_ptr, vars->data.win_ptr, vars->img.img, 0, 0);
	return(0);
}

int	main(void)
{
	t_data	data;
	t_img	img;
	t_vars	vars;

	//initialize server and check
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(MLX_ERROR);
	//create new window and check; free mlx pointer on error
	data.win_ptr = mlx_new_window(data.mlx_ptr, IMG_W, IMG_H, "Hello world!");
	if (data.win_ptr == NULL)
		exit(WIN_ERROR);
	//create new image
	img.img = mlx_new_image(data.mlx_ptr, IMG_W, IMG_H);
	//get image parameters info
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	
	vars.data=data;
	vars.img=img;
	mlx_loop_hook(data.mlx_ptr, render, &vars);
	mlx_key_hook(data.win_ptr, keypress, &data);

	//close program on close window
	mlx_hook(data.win_ptr, 17, 0, quit, &data);

	mlx_loop(data.mlx_ptr);
	//close window and free server
	
}

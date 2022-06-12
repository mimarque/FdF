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

//Returns a linear value in the range [0,1]
//for sRGB input in [0,255].
double ChannelInvCompanding(int c)
{
	double y;

	c = c & 0xFF;
	y = c / 255.0;
    if (c <= 0.04045)
        y = y / 12.92;
    else
        y = pow(((c + 0.055) / 1.055), 2.4);
    return (y);
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

//sums channels
//does not include transperancy
double sumChannels(double *c)
{
	double x = c[1] + c[2] + c[3];
    return (x);
}

//Lerping see
//https://en.wikipedia.org/wiki/Linear_interpolation
//#Programming_language_support
double lerp_int(double c1, double c2, double t)
{
	return (c1 * (1 - t) + c2 * t);
	//return ((1 - t) * c1 + t * c2);
}

double	*lerp(double *c1, double *c2, double t)
{
	double  *r = malloc(4 * sizeof(double));

	//r[1] = ((1 - t) * c1[1] + t * c2[1]);
    //r[2] = ((1 - t) * c1[2] + t * c2[2]);
    //r[3] = ((1 - t) * c1[3] + t * c2[3]);
	r[1] = c1[1] * (1 - t) + c2[1] * t;
	r[2] = c1[2] * (1 - t) + c2[2] * t;
	r[3] = c1[3] * (1 - t) + c2[3] * t;
	return (r);
}

void	fix(double *c, double intensity, int total)
{
    c[1] = (c[1] * intensity / total);
    c[2] = (c[2] * intensity / total);
    c[3] = (c[3] * intensity / total);
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
	double	*color;
	double	step;
	int		total;
	int		clr;
}	t_calcol;

int sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

int	calculate_color_step(t_calcol *c, double step)
{
	c->intensity = pow(lerp_int(c->bright1, c->bright2, step), (1 / GAMMA));
    c->color = lerp(c->color1_lin, c->color2_lin, step);
	c->total = sumChannels(c->color);
    if (c->total != 0)
		fix(c->color, c->intensity, c->total);
   	return (SrgbCompanding(c->color));
}

void	bresenhams_alg(int x1, int y1, int x2, int y2, int scolor, int ecolor, t_vars *vars)
{
	t_bresvars v;
	t_calcol c;
	double step;

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
	c.step = (1.0 / v.dx);
	v.i = 0;
	step = 0;
	while (v.i < v.dx)
	{
		step = step + 0.2;
		c.clr = calculate_color_step(&c, step);
		my_mlx_pixel_put(&vars->img, v.x, v.y, c.clr); 
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
		bresenhams_alg(0, 0, IMG_W, IMG_H, 0xc3c3c3, 0xd97bd4, vars);
		bresenhams_alg(IMG_W, 0, 0, IMG_H, 0x0000ff, 0xd97bd4, vars);
		bresenhams_alg(0, IMG_H / 2, IMG_W, IMG_H / 2, 0xc3c3c3, 0xd97bd4, vars);
		bresenhams_alg(IMG_W / 2, 0, IMG_W / 2, IMG_H, 0xc3c3c3, 0xd97bd4, vars);
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

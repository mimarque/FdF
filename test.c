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

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

//since mlx_pixel_put is works slowly but fast enough to cause tearing
//we make our own function to put data in the image unidimetional array
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bits_per_pixel - 8;
    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
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

int	keypress(int keysym, t_data *data)
{
	//for keypresses macOS uses Carbon.HIToolbox.Events.h
	//and in Linux it uses X11's X11/keysymdef.h
	//Note that for example "5" and "ESC"
	//create the same value in X11 or Cocoa
	//So using something like
	//keysym == kVK_Escape || keysym == XK_Escape
	//is not a good idea
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

void bresenhams_alg(int x0, int y0, int x1, int y1, t_vars *vars)
{
	int dx;
	int dy;
	int sx = 1;
	int sy = 1;
	int err;
	int e2;

	dx = abs(x1-x0);
	dy = abs(y1-y0);
	if (x0 >= x1)
		sx = -1;
	if (y0 >= y1)
		sy = -1;
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
 
  while(true)
  {
	my_mlx_pixel_put(&vars->img, x0, y0, PURPLE);
	if (x0==x1 && y0==y1)
		break;
	e2 = err;
	if (e2 > -dx)
	{
		err -= dy;
		x0 += sx;
	}
	if (e2 < dy)
	{ 
		err += dx;
		y0 += sy; 
	}
  }
}

int render_rect(t_data *data, t_img *img, t_rect rect)
{
	int	i;
	int j;

	if (data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int render(t_vars *vars)
{
	if (vars->data.win_ptr != NULL)
		bresenhams_alg(0, 0, IMG_W, IMG_H, vars);
		bresenhams_alg(IMG_W, IMG_H, 0, 0, vars);
		//render_rect(&vars->data, &vars->img, (t_rect){0, 0, 100, 100, PURPLE});
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

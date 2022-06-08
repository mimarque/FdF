#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <libft.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <Carbon/Carbon.h>
#include <mlx.h>


#ifndef KEY_MACOS_H
# define KEY_MACOS_H

# define KEYPRESS 2
# define KEYRELEASE 3

/*
** # define KEYPRESSMASK (1L<<0)
** # define KEYRELEASEMASK (1L<<1)
*/

# define KEY_ESCAPE			53
# define KEY_F1 			122
# define KEY_F2				120
# define KEY_F3				99
# define KEY_F4				118
# define KEY_F5				96
# define KEY_F6				97
# define KEY_F7				98
# define KEY_F8				100
# define KEY_F9				101
# define KEY_F10			109
# define KEY_F11			103
# define KEY_F12			111
# define KEY_F13			105
# define KEY_F14			107
# define KEY_F15			113
# define KEY_F16			106
# define KEY_F17			64
# define KEY_F18			79
# define KEY_F19			80
# define KEY_TILDE			50
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define KEY_0				29
# define KEY_MINUS			27
# define KEY_EQUAL			24
# define KEY_BACKSPACE		51
# define KEY_TAB			48
# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_R				15
# define KEY_T				17
# define KEY_Y				16
# define KEY_U				32
# define KEY_I				34
# define KEY_O				31
# define KEY_P				35
# define KEY_OPEN_BRACKET	33
# define KEY_OPEN_BRACE		33
# define KEY_CLOSE_BRACKET	30
# define KEY_CLOSE_BRACE	30
# define KEY_BACKSLASH		42
# define KEY_PIPE			42
# define KEY_CAPSLOCK		272
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_F				3
# define KEY_G				5
# define KEY_H				4
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_COLON			41
# define KEY_SEMI_COLON		41
# define KEY_SIMPLE_QUOTE	39
# define KEY_DOUBLE_QUOTES	39
# define KEY_ENTER			36
# define KEY_SHIFT_LEFT		257
# define KEY_Z				6
# define KEY_X				7
# define KEY_C				8
# define KEY_V				9
# define KEY_B				11
# define KEY_N				45
# define KEY_M				46
# define KEY_LESS_THAN		43
# define KEY_COMMA			43
# define KEY_GREATER_THAN	47
# define KEY_DOT			47
# define KEY_SLASH			44
# define KEY_QUESTION_MARK	44
# define KEY_SHIFT_RIGHT	258
# define KEY_CTRL_LEFT		256
# define KEY_COMMAND_LEFT	259
# define KEY_OPTION_LEFT	261
# define KEY_ALT			261
# define KEY_SPACEBAR		49
# define KEY_COMMAND_RIGHT	260
# define KEY_ALT_GR			262
# define KEY_FN				279
# define KEY_CTRL_RIGHT		269
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DEL			117
# define KEY_HOME			115
# define KEY_END			119
# define KEY_PAGE_UP		116
# define KEY_PAGE_DOWN		121
# define KEY_CLEAR			71
# define KEY_PAD_1			83
# define KEY_PAD_2			84
# define KEY_PAD_3			85
# define KEY_PAD_4			86
# define KEY_PAD_5			87
# define KEY_PAD_6			88
# define KEY_PAD_7			89
# define KEY_PAD_8			91
# define KEY_PAD_9			92
# define KEY_PAD_0			82
# define KEY_PAD_EQUAL		81
# define KEY_PAD_DIVIDE		75
# define KEY_PAD_MULTIPLY	67
# define KEY_PAD_SUB		78
# define KEY_PAD_ADD		69
# define KEY_PAD_ENTER		76
# define KEY_PAD_DOT		65

/* Mouse button codes
** =============================================================================
*/

# define MB1				1
# define MB2				3
# define MB3				2
# define MB2_UP				4
# define MB2_DOWN			5
# define MB2_LEFT			6
# define MB2_RIGHT			7

#endif

# define SCRN_HEIGHT		1050
# define SCRN_WIDTH			1400
# define SUB_SCRN_WIDTH		330

# define CLR_TEXT			0xEAEAEA
# define CLR_MAIN_SCRN_BG	0x222222
# define CLR_SUB_SCRN_BG	0x1E1E1E
# define CLR_DISCO			0x9A1F6A
# define CLR_BRICK_RED		0xC2294E
# define CLR_FLAMINGO		0xEC4B27
# define CLR_JAFFA			0xEF8633
# define CLR_SAFFRON		0xF3AF3D

typedef struct s_node
{
	int				z;
	int				clr;
	struct s_node	*nxt;
}				t_node;

typedef struct s_map
{
	int				width;
	int				height;
	int				*arr_z;
	int				*arr_clr;
	int				z_min;
	int				z_max;
}				t_map;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				clr;
}				t_point;

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef struct s_camera
{
	t_projection	projection;
	double			alpha;
	double			beta;
	double			gamma;
	int				x_offset;
	int				y_offset;
	int				zoom;
	float			z_divisor;
}				t_camera;

typedef struct s_mouse
{
	bool			flag_mb1_pressed;
	bool			flag_mb2_pressed;
	bool			flag_mb3_pressed;
	int				cur_x;
	int				cur_y;
	int				prev_x;
	int				prev_y;
}				t_mouse;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bpp;
	int				size_line;
	int				endian;
	t_map			*map;
	t_camera		*camera;
	t_mouse			*mouse;
}				t_fdf;

/* init.c
** =============================================================================
*/
t_fdf		*init_fdf(t_map *map);
t_camera	*init_camera(t_fdf *fdf);
t_point		*init_point(int x, int y, t_map *map);

/* draw.c
** =============================================================================
*/
void		draw_fdf(t_map *map, t_fdf *fdf);

/* project.c
** =============================================================================
*/
t_point		*project_point(t_point *p, t_fdf *fdf);

/* color.c
** =============================================================================
*/
int			get_default_clr(int z, t_map *map);
int			get_clr(t_point cur, t_point *s, t_point *f, t_point delta);

/* mouse.c
** =============================================================================
*/
void		set_cntl(t_fdf *fdf);

/* key.c
** =============================================================================
*/
int			key_press(int key, void *param);
int			quit(void *param);

/* utils.c
** =============================================================================
*/
void		terminate(char *str);
void		push_node(t_node **stack, t_node *new_node);
t_node		*pop_node(t_node **stack);
void		print_controls(t_fdf *fdf);
void		print_status(t_fdf *fdf);

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf) * 1);
	if (fdf == NULL)
		terminate("fdf initialization error");
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		terminate("fdf initialization error");
	fdf->win = mlx_new_window(fdf->mlx, SCRN_WIDTH, SCRN_HEIGHT, "FdF");
	if (fdf->win == NULL)
		terminate("fdf initialization error");
	fdf->img = mlx_new_image(fdf->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	if (fdf->img == NULL)
		terminate("fdf initialization error");
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bpp),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse) * 1);
	if (fdf->mouse == NULL)
		terminate("fdf initialization error");
	return (fdf);
}

t_camera	*init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera) * 1);
	if (camera == NULL)
		terminate("camera initialization error");
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->zoom = \
			GET_LESS((SCRN_WIDTH - SUB_SCRN_WIDTH) / fdf->map->width / 2,
			SCRN_HEIGHT / fdf->map->height / 2);
	camera->z_divisor = 1;
	return (camera);
}

t_point	*init_point(int x, int y, t_map *map)
{
	t_point	*point;
	int		i;

	point = (t_point *)malloc(sizeof(t_point) * 1);
	if (point == NULL)
		terminate("point initialization error");
	point->x = x;
	point->y = y;
	i = y * map->width + x;
	point->z = (map->arr_z)[i];
	if ((map->arr_clr)[i] == -1)
		point->clr = get_default_clr(point->z, map);
	else
		point->clr = map->arr_clr[i];
	return (point);
}

static double	get_ratio(int s, int f, int cur)
{
	double	ratio;

	if (s == f)
		return (1.0);
	ratio = (double)(cur - s) / (f - s);
	return (ratio);
}

int	get_default_clr(int z, t_map *map)
{
	double	ratio;

	ratio = get_ratio(map->z_min, map->z_max, z);
	if (ratio < 0.2)
		return (CLR_DISCO);
	else if (ratio < 0.4)
		return (CLR_BRICK_RED);
	else if (ratio < 0.6)
		return (CLR_FLAMINGO);
	else if (ratio < 0.8)
		return (CLR_JAFFA);
	else
		return (CLR_SAFFRON);
}

static int	do_lerp(int s, int f, double ratio)
{
	return ((int)((ratio) * s + (1 - ratio) * f));
}

/*
** Quadrant 1, 4, 5, 8(delta.x > delta.y): sample by x
** Quadrant 2, 3, 6, 7(delta.x < delta.y): sample by y
*/

int	get_clr(t_point cur, t_point *s, t_point *f, t_point delta)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	if (cur.clr == f->clr)
		return (cur.clr);
	if (delta.x > delta.y)
		ratio = get_ratio(s->x, f->x, cur.x);
	else
		ratio = get_ratio(s->y, f->y, cur.y);
	red = do_lerp((f->clr >> 16) & 0xFF, (s->clr >> 16) & 0xFF, ratio);
	green = do_lerp((f->clr >> 8) & 0xFF, (s->clr >> 8) & 0xFF, ratio);
	blue = do_lerp(f->clr & 0xFF, s->clr & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

static void	draw_background(t_fdf *fdf)
{
	int	i;
	int	*img;

	i = 0;
	img = (int *)(fdf->data_addr);
	while (i < SCRN_HEIGHT * SCRN_WIDTH)
	{
		if (i % SCRN_WIDTH < SUB_SCRN_WIDTH)
			img[i] = CLR_SUB_SCRN_BG;
		else
			img[i] = CLR_MAIN_SCRN_BG;
		++i;
	}
}

/*
** bits per pixel: 32(4 bytes; int)
** size_line: 4000
*/

static void	put_pixel(t_fdf *fdf, int x, int y, int clr)
{
	int	i;

	if ((SUB_SCRN_WIDTH <= x && x < SCRN_WIDTH) && \
		(0 <= y && y < SCRN_HEIGHT))
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = clr;
		fdf->data_addr[++i] = clr >> 8;
		fdf->data_addr[++i] = clr >> 16;
	}
}

/*
** Optimized Bresenham's line drawing algorithm
**
** plotLine(int x0, int y0, int x1, int y1)
**     dx =  abs(x1-x0);
**     sx = x0<x1 ? 1 : -1;
**     dy = -abs(y1-y0);
**     sy = y0<y1 ? 1 : -1;
**     err = dx+dy;  // error value e_xy
**     while (true)   // loop
**         plot(x0, y0);
**         if (x0 == x1 && y0 == y1) break;
**         e2 = 2*err;
**         if (e2 >= dy) // e_xy+e_x > 0
**             err += dy;
**             x0 += sx;
**         end if
**         if (e2 <= dx) // e_xy+e_y < 0
**             err += dx;
**             y0 += sy;
**         end if
**     end while
*/

static void	init_delta_and_step(t_point *s, t_point *f, \
		t_point *delta, t_point *step)
{
	delta->x = GET_ABS(f->x - s->x);
	delta->y = GET_ABS(f->y - s->y);
	if (s->x < f->x)
		step->x = 1;
	else
		step->x = -1;
	if (s->y < f->y)
		step->y = 1;
	else
		step->y = -1;
}

static void	draw_line(t_point *s, t_point *f, t_fdf *fdf)
{
	t_point	delta;
	t_point	step;
	t_point	cur;
	int		err[2];

	init_delta_and_step(s, f, &delta, &step);
	err[0] = delta.x - delta.y;
	cur = *s;
	while (cur.x != f->x || cur.y != f->y)
	{
		put_pixel(fdf, cur.x, cur.y, get_clr(cur, s, f, delta));
		err[1] = err[0] * 2;
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += step.y;
		}
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += step.x;
		}
	}
	free(s);
	s = NULL;
	free(f);
	f = NULL;
}

void	draw_fdf(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < fdf->map->width - 1)
			{
				draw_line(project_point(init_point(x, y, map), fdf), \
						project_point(init_point(x + 1, y, map), fdf), fdf);
			}
			if (y < fdf->map->height - 1)
				draw_line(project_point(init_point(x, y, map), fdf), \
						project_point(init_point(x, y + 1, map), fdf), fdf);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_controls(fdf);
	print_status(fdf);
}

static void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_X)
		fdf->camera->alpha += 0.03;
	else if (key == KEY_Y)
		fdf->camera->beta += 0.03;
	else if (key == KEY_Z)
		fdf->camera->gamma += 0.03;
	draw_fdf(fdf->map, fdf);
}

static void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == KEY_I)
		fdf->camera->projection = ISOMETRIC;
	else if (key == KEY_P)
		fdf->camera->projection = PARALLEL;
	draw_fdf(fdf->map, fdf);
}

static void	flatten(int key, t_fdf *fdf)
{
	if (key == KEY_EQUAL)
		fdf->camera->z_divisor -= 0.1;
	else if (key == KEY_MINUS)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 7)
		fdf->camera->z_divisor = 7;
	draw_fdf(fdf->map, fdf);
}

/*
** <Controls>
** MB1 & Drag: Rotate
** MB2 & MB3 & Drag: Translate
** Scroll: Zoom in/out
** Key X/Y/Z: Rotate around x/y/z
** key I/P: Isometric/Parallel
** Key +/-: Flatten
*/

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_X || key == KEY_Y || key == KEY_Z)
		rotate(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	else if (key == KEY_EQUAL || key == KEY_MINUS)
		flatten(key, fdf);
	else if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}

/*
** <Controls>
** MB1 & Drag: Rotate
** MB2 & MB3 & Drag: Translate
** Scroll: Zoom in/out
** Key X/Y/Z: Rotate around x/y/z
** key I/P: Isometric/Parallel
** Key +/-: Flatten
*/

static void	zoom(int key, t_fdf *fdf)
{
	if (key == MB2_UP)
		++(fdf->camera->zoom);
	else if (key == MB2_DOWN)
		--(fdf->camera->zoom);
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw_fdf(fdf->map, fdf);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MB2_UP || button == MB2_DOWN)
		zoom(button, fdf);
	else if (button == MB1)
		fdf->mouse->flag_mb1_pressed = true;
	else if (button == MB2)
		fdf->mouse->flag_mb2_pressed = true;
	else if (button == MB3)
		fdf->mouse->flag_mb3_pressed = true;
	return (0);
}

static int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->flag_mb2_pressed = false;
	fdf->mouse->flag_mb3_pressed = false;
	return (0);
}

static int	mouse_move(int cur_x, int cur_y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->prev_x = fdf->mouse->cur_x;
	fdf->mouse->prev_y = fdf->mouse->cur_y;
	fdf->mouse->cur_x = cur_x;
	fdf->mouse->cur_y = cur_y;
	if (fdf->mouse->flag_mb2_pressed && fdf->mouse->flag_mb3_pressed)
	{
		fdf->camera->x_offset += (cur_x - fdf->mouse->prev_x);
		fdf->camera->y_offset += (cur_y - fdf->mouse->prev_y);
	}
	else if (fdf->mouse->flag_mb2_pressed)
	{
		fdf->camera->beta += (cur_x - fdf->mouse->prev_x) * 0.002;
		fdf->camera->alpha += (cur_y - fdf->mouse->prev_y) * 0.002;
	}
	draw_fdf(fdf->map, fdf);
	return (0);
}

/*
** X11 Events
** 02: keyPress
** 04: ButtonPress
** 05: ButtonRelease
** 06: MotionNotify
** 17: DestroyNotify
**
** x_mask is ignored on macOS
** https://stackoverflow.com/c/42network/questions/164
*/

void	set_cntl(t_fdf *fdf)
{
	mlx_hook(fdf->win, 4, 0L, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0L, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0L, mouse_move, fdf);
	mlx_hook(fdf->win, 2, 0L, key_press, fdf);
	mlx_hook(fdf->win, 17, 0L, quit, fdf);
}

int	quit(void *param)
{
	(void)param;
	exit(0);
}

static t_node	*create_node(char *splited_line)
{
	t_node	*new_node;
	char	**buf;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (new_node == NULL)
		terminate("Map reading error");
	buf = split_into_strs(splited_line, ',');
	if (buf == NULL)
		terminate("Map reading error");
	new_node->z = ft_atoi(buf[0]);
	if (buf[1])
		new_node->clr = atoi_base(buf[1], 16);
	else
		new_node->clr = -1;
	new_node->nxt = NULL;
	double_free(buf);
	return (new_node);
}

static void	init_stack(t_node **stack, t_map *map, char **splited_line)
{
	int	width;

	width = 0;
	while (*splited_line)
	{
		push_node(stack, create_node(*splited_line));
		++width;
		++splited_line;
	}
	if (map->height == 0)
		map->width = width;
}

static void	read_map(char **argv, t_node **stack, t_map *map)
{
	int		fd;
	int		ret_gnl;
	char	*line;
	char	**splited_line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || OPEN_MAX <= fd)
		terminate("Map reading error");
	ret_gnl = get_next_line(fd, &line);
	while (ret_gnl == 1)
	{
		splited_line = split_into_strs(line, ' ');
		if (splited_line == NULL)
			terminate("Map reading error");
		init_stack(stack, map, splited_line);
		double_free(splited_line);
		++(map->height);
		free(line);
		line = NULL;
		ret_gnl = get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	if (ret_gnl == -1)
		terminate("Map reading error");
}

static void	stack_to_arr(t_node **stack, t_map *map)
{
	int		i;
	t_node	*buf;

	map->arr_z = (int *)malloc(map->width * map->height * sizeof(int));
	if (map->arr_z == NULL)
		terminate("Conversion to array error");
	map->arr_clr = (int *)malloc(map->width * map->height * sizeof(int));
	if (map->arr_clr == NULL)
		terminate("Conversion to array error");
	i = map->width * map->height - 1;
	while (i >= 0)
	{
		buf = pop_node(stack);
		map->arr_z[i] = buf->z;
		map->arr_clr[i] = buf->clr;
		if (buf->z > map->z_max)
			map->z_max = buf->z;
		if (buf->z < map->z_min)
			map->z_min = buf->z;
		free(buf);
		buf = NULL;
		--i;
	}
}

static void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

/*
** 30deg × π/180 = 0.5236rad
*/

static void	conv_to_iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5236);
	*y = (prev_x + prev_y) * sin(0.5236) - z;
}

/*
** Project a point
** 1. Camera zoom transformation
** 2. Translation: world focus to world origin
** 3. Rotation transformation
** 4. Translation: world origin to screen center
** 5. Calibration: p.y += fdf->map->height * fdf->camera->zoom * 2 / 5
*/

t_point	*project_point(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->camera->zoom;
	p->y *= fdf->camera->zoom;
	p->z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p->x -= (fdf->map->width * fdf->camera->zoom) / 2;
	p->y -= (fdf->map->height * fdf->camera->zoom) / 2;
	rotate_x(&(p->y), &(p->z), fdf->camera->alpha);
	rotate_y(&(p->x), &(p->z), fdf->camera->beta);
	rotate_z(&(p->x), &(p->y), fdf->camera->gamma);
	if (fdf->camera->projection == ISOMETRIC)
		conv_to_iso(&(p->x), &(p->y), (p->z));
	p->x += (SCRN_WIDTH - SUB_SCRN_WIDTH) / 2 + SUB_SCRN_WIDTH + \
			fdf->camera->x_offset;
	p->y += SCRN_HEIGHT / 2 + fdf->camera->y_offset;
	p->y += fdf->map->height * fdf->camera->zoom * 2 / 5;
	return (p);
}

void	terminate(char *str)
{
	if (errno == 0)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror(str);
	exit(1);
}

void	push_node(t_node **stack, t_node *new_node)
{
	if (stack)
	{
		if (new_node)
			new_node->nxt = *stack;
		*stack = new_node;
	}
}

t_node	*pop_node(t_node **stack)
{
	t_node	*top;

	top = NULL;
	if (stack && *stack)
	{
		top = *stack;
		*stack = (*stack)->nxt;
	}
	return (top);
}

void	print_controls(t_fdf *fdf)
{
	int	y;

	y = 0;
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 20, CLR_TEXT, \
					"<Controls>");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"MB1 & Drag: Rotate");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"MB2 & MB3 & Drag: Translate");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"Scroll: Zoom in/out");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"Key X/Y/Z: Rotate around x/y/z");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"key I/P: Isometric/Parallel");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"Key +/-: Flatten");
}

void	print_status(t_fdf *fdf)
{
	int		y;
	char	buf[10];

	y = 200;
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 60, CLR_TEXT, "<Status>");
	sprintf(buf, "%f", fdf->camera->alpha);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "alpha: ");
	mlx_string_put(fdf->mlx, fdf->win, 85, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", fdf->camera->beta);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "beta: ");
	mlx_string_put(fdf->mlx, fdf->win, 75, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", fdf->camera->gamma);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "gamma: ");
	mlx_string_put(fdf->mlx, fdf->win, 85, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%d", fdf->camera->x_offset);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "x_offset: ");
	mlx_string_put(fdf->mlx, fdf->win, 115, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%d", fdf->camera->y_offset);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "y_offset: ");
	mlx_string_put(fdf->mlx, fdf->win, 115, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%d", fdf->camera->zoom);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "zoom: ");
	mlx_string_put(fdf->mlx, fdf->win, 75, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", fdf->camera->z_divisor);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "z_divisor: ");
	mlx_string_put(fdf->mlx, fdf->win, 125, y += 0, CLR_TEXT, buf);
}

int	main(int argc, char **argv)
{
	t_node	*stack;
	t_map	map;
	t_fdf	*fdf;

	errno = 0;
	if (argc != 2)
		terminate("Execution error\nUsage: ./fdf MAP_FILE");
	stack = NULL;
	map = (t_map){0, };
	read_map(argv, &stack, &map);
	stack_to_arr(&stack, &map);
	fdf = init_fdf(&map);
	fdf->camera = init_camera(fdf);
	draw_fdf(&map, fdf);
	set_cntl(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}


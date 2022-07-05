/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:08:24 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 00:02:11 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <math.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>

#ifndef KEY_MACOS_H
# define KEY_MACOS_H

# define KEYPRESS 2
# define KEYRELEASE 3


# define MB1				1
# define MB2				3
# define MB3				2
# define MB2_UP				4
# define MB2_DOWN			5
# define MB2_LEFT			6
# define MB2_RIGHT			7

#endif

#define MLX_ERROR 1
#define WIN_ERROR 2
#define PURPLE 0x00FFFFFF
#define IMG_W 1280
#define IMG_H 720
#define MENU_W 250
#define LTR_C 0x111111
#define GAMMA 0.43
#define BUFFER_SIZE 42
#define NUM_OF_FD 256

/*
** # define KEYPRESSMASK (1L<<0)
** # define KEYRELEASEMASK (1L<<1)
*/
/* MacRoman character codes*/
enum {
	kNullCharCode					= 0,
	kHomeCharCode					= 1,
	kEnterCharCode					= 3,
	kEndCharCode					= 4,
	kHelpCharCode					= 5,
	kBellCharCode					= 7,
	kBackspaceCharCode				= 8,
	kTabCharCode					= 9,
	kLineFeedCharCode				= 10,
	kVerticalTabCharCode			= 11,
	kPageUpCharCode					= 11,
	kFormFeedCharCode				= 12,
	kPageDownCharCode				= 12,
	kReturnCharCode					= 13,
	kFunctionKeyCharCode			= 16,
	kCommandCharCode				= 17,
	kCheckCharCode					= 18,
	kDiamondCharCode				= 19,
	kAppleLogoCharCode				= 20,
	kEscapeCharCode					= 27,
	kClearCharCode					= 27,
	kLeftArrowCharCode				= 28,
	kRightArrowCharCode				= 29,
	kUpArrowCharCode				= 30,
	kDownArrowCharCode				= 31,
	kSpaceCharCode					= 32,
	kDeleteCharCode					= 127,
	kBulletCharCode					= 165,
	kNonBreakingSpaceCharCode		= 202
};

/* useful Unicode code points*/
enum {
	kShiftUnicode					= 0x21E7,
	kControlUnicode					= 0x2303,
	kOptionUnicode					= 0x2325,
	kCommandUnicode					= 0x2318,
	kPencilUnicode					= 0x270E,
	kPencilLeftUnicode				= 0xF802,
	kCheckUnicode					= 0x2713,
	kDiamondUnicode					= 0x25C6,
	kBulletUnicode					= 0x2022,
	kAppleLogoUnicode				= 0xF8FF
};

/*
 *  Summary:
 *    Virtual keycodes
 *  
 *  Discussion:
 *    These constants are the virtual keycodes defined originally in
 *    Inside Mac Volume V, pg. V-191. They identify physical keys on a
 *    keyboard. Those constants with "ANSI" in the name are labeled
 *    according to the key position on an ANSI-standard US keyboard.
 *    For example, kVK_ANSI_A indicates the virtual keycode for the key
 *    with the letter 'A' in the US keyboard layout. Other keyboard
 *    layouts may have the 'A' key label on a different physical key;
 *    in this case, pressing 'A' will generate a different virtual
 *    keycode.
 */
enum {
	kVK_ANSI_A						= 0x00,
	kVK_ANSI_S						= 0x01,
	kVK_ANSI_D						= 0x02,
	kVK_ANSI_F						= 0x03,
	kVK_ANSI_H						= 0x04,
	kVK_ANSI_G						= 0x05,
	kVK_ANSI_Z						= 0x06,
	kVK_ANSI_X						= 0x07,
	kVK_ANSI_C						= 0x08,
	kVK_ANSI_V						= 0x09,
	kVK_ANSI_B						= 0x0B,
	kVK_ANSI_Q						= 0x0C,
	kVK_ANSI_W						= 0x0D,
	kVK_ANSI_E						= 0x0E,
	kVK_ANSI_R						= 0x0F,
	kVK_ANSI_Y						= 0x10,
	kVK_ANSI_T						= 0x11,
	kVK_ANSI_1						= 0x12,
	kVK_ANSI_2						= 0x13,
	kVK_ANSI_3						= 0x14,
	kVK_ANSI_4						= 0x15,
	kVK_ANSI_6						= 0x16,
	kVK_ANSI_5						= 0x17,
	kVK_ANSI_Equal					= 0x18,
	kVK_ANSI_9						= 0x19,
	kVK_ANSI_7						= 0x1A,
	kVK_ANSI_Minus					= 0x1B,
	kVK_ANSI_8						= 0x1C,
	kVK_ANSI_0						= 0x1D,
	kVK_ANSI_RightBracket			= 0x1E,
	kVK_ANSI_O						= 0x1F,
	kVK_ANSI_U						= 0x20,
	kVK_ANSI_LeftBracket			= 0x21,
	kVK_ANSI_I						= 0x22,
	kVK_ANSI_P						= 0x23,
	kVK_ANSI_L						= 0x25,
	kVK_ANSI_J						= 0x26,
	kVK_ANSI_Quote					= 0x27,
	kVK_ANSI_K						= 0x28,
	kVK_ANSI_Semicolon				= 0x29,
	kVK_ANSI_Backslash				= 0x2A,
	kVK_ANSI_Comma					= 0x2B,
	kVK_ANSI_Slash					= 0x2C,
	kVK_ANSI_N						= 0x2D,
	kVK_ANSI_M						= 0x2E,
	kVK_ANSI_Period					= 0x2F,
	kVK_ANSI_Grave					= 0x32,
	kVK_ANSI_KeypadDecimal			= 0x41,
	kVK_ANSI_KeypadMultiply			= 0x43,
	kVK_ANSI_KeypadPlus				= 0x45,
	kVK_ANSI_KeypadClear			= 0x47,
	kVK_ANSI_KeypadDivide			= 0x4B,
	kVK_ANSI_KeypadEnter			= 0x4C,
	kVK_ANSI_KeypadMinus			= 0x4E,
	kVK_ANSI_KeypadEquals			= 0x51,
	kVK_ANSI_Keypad0				= 0x52,
	kVK_ANSI_Keypad1				= 0x53,
	kVK_ANSI_Keypad2				= 0x54,
	kVK_ANSI_Keypad3				= 0x55,
	kVK_ANSI_Keypad4				= 0x56,
	kVK_ANSI_Keypad5				= 0x57,
	kVK_ANSI_Keypad6				= 0x58,
	kVK_ANSI_Keypad7				= 0x59,
	kVK_ANSI_Keypad8				= 0x5B,
	kVK_ANSI_Keypad9				= 0x5C
};

/* keycodes for keys that are independent of keyboard layout*/
enum {
	kVK_Return						= 0x24,
	kVK_Tab							= 0x30,
	kVK_Space						= 0x31,
	kVK_Delete						= 0x33,
	kVK_Escape						= 0x35,
	kVK_Command						= 0x37,
	kVK_Shift						= 0x38,
	kVK_CapsLock					= 0x39,
	kVK_Option						= 0x3A,
	kVK_Control						= 0x3B,
	kVK_RightShift					= 0x3C,
	kVK_RightOption					= 0x3D,
	kVK_RightControl				= 0x3E,
	kVK_Function					= 0x3F,
	kVK_F17							= 0x40,
	kVK_VolumeUp					= 0x48,
	kVK_VolumeDown					= 0x49,
	kVK_Mute						= 0x4A,
	kVK_F18							= 0x4F,
	kVK_F19							= 0x50,
	kVK_F20							= 0x5A,
	kVK_F5							= 0x60,
	kVK_F6							= 0x61,
	kVK_F7							= 0x62,
	kVK_F3							= 0x63,
	kVK_F8							= 0x64,
	kVK_F9							= 0x65,
	kVK_F11							= 0x67,
	kVK_F13							= 0x69,
	kVK_F16							= 0x6A,
	kVK_F14							= 0x6B,
	kVK_F10							= 0x6D,
	kVK_F12							= 0x6F,
	kVK_F15							= 0x71,
	kVK_Help						= 0x72,
	kVK_Home						= 0x73,
	kVK_PageUp						= 0x74,
	kVK_ForwardDelete				= 0x75,
	kVK_F4							= 0x76,
	kVK_End							= 0x77,
	kVK_F2							= 0x78,
	kVK_PageDown					= 0x79,
	kVK_F1							= 0x7A,
	kVK_LeftArrow					= 0x7B,
	kVK_RightArrow					= 0x7C,
	kVK_DownArrow					= 0x7D,
	kVK_UpArrow						= 0x7E
};

/* ISO keyboards only*/
enum {
	kVK_ISO_Section					= 0x0A
};

/* JIS keyboards only*/
enum {
	kVK_JIS_Yen						= 0x5D,
	kVK_JIS_Underscore				= 0x5E,
	kVK_JIS_KeypadComma				= 0x5F,
	kVK_JIS_Eisu					= 0x66,
	kVK_JIS_Kana					= 0x68
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

typedef struct s_bresvars {
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	s1;
	int	s2;
	int	swap;
	int	temp;
	int	d;
	int	i;
}	t_bresvars;

typedef struct s_calcol {
	float	*color1_lin;
	float	bright1;
	float	*color2_lin;
	float	bright2;
	float	intensity;
	float	*color;
	float	step_v;
	float	step;
	float	total;
	int		clr;
}	t_calcol;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		c;
}	t_point;

typedef struct s_pmatrix
{
	float	m[4][4];
}	t_pmatrix;

typedef struct s_coord
{
	int	x;
	int	y;
	int	c;
}	t_coord;

typedef struct s_allvars
{
	t_point		*i;
	t_point		*bt;
	t_point		*o;
	t_coord		*c;
	t_pmatrix	pm;
	t_pmatrix	wc;
	t_pmatrix	tw;
	char		mode;
	char		menu;
	float		fov;
	float		f;
	float		n;
	float		r;
	float		l;
	float		t;
	float		b;
	float		brange;
	float		zoom;
	float		scale;
	float		tlx;
	float		tly;
	float		tlz;
	float		rx;
	float		ry;
	float		rz;
	int			x;
	int			y;
	int			tx;
	int			ty;
	t_data		data;
	t_img		img;
}	t_allvars;

void	multiply_matrix_vector(t_point *i, t_point *o, t_pmatrix *m);
void	transform_matrix_vector(t_point *i, t_pmatrix *m);
void	make_matrix(t_allvars *a);

//since mlx_pixel_put works slowly but fast enough to cause tearing
//we make our own function to put data in the image unidimetional array
//and then use mlx_put_image_to_window to push image to the window
//if (img->endian != 0)
//big endian, MSB is the leftmost bit
//else
//little endian, LSB is the leftmost bit
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < IMG_W && y < IMG_H && x > 0 && y > 0)
	{
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
}

//instead of doing any math it pushes the values to their positions
//		int t = 00000000 00000000 000000000 aaaaaaaa
//		int r = 00000000 00000000 000000000 00rrrrrr
//		int g = 00000000 00000000 000000000 gggggggg
//		int b = 00000000 00000000 000000000 000000bb
//		t<<24 = aaaaaaaa 00000000 000000000 00000000
//		r<<16 = 00000000 00rrrrrr 000000000 00000000
//	  	g<<8  = 00000000 00000000 ggggggggg 00000000
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

/**
 * @brief Closes window and frees memory
 * 
 * @param data Data struct used in this program
 * @param error 0 if successfull 
 * @return int 
 */
int quit(t_allvars *a, int error)
{
	ft_printf("%d", error);
	if (error == 1)
		ft_printf("Wrong arguments.\nusage: ./FdF <map.fdf>");
	else if (error == 2)
		ft_printf("Error opening file");
	else if (error == 3)
		ft_printf("Error file improperly formated");
	else if (error == 4)
		ft_printf("Error allocating memory");
	else if (error == 5)
	{
		free(a->i);
		ft_printf("Error allocating memory");
	}
	else if (error == 6)
	{
		free(a->i);
		free(a->bt);
		ft_printf("Error allocating memory");
	}
	else if (error == 7)
	{
		free(a->i);
		free(a->bt);
		free(a->o);
		ft_printf("Error allocating memory");
	}
	else if (error >= 7 || error == 0)
	{
		free(a->i);
		free(a->bt);
		free(a->o);
		free(a->c);
		mlx_destroy_window(a->data.mlx_ptr, a->data.win_ptr);
		free(a->data.mlx_ptr);
	}
	exit(error);
}

//for keypresses macOS uses Carbon.HIToolbox.Events.h
//and in Linux it uses X11's X11/keysymdef.h
//Note that for example "5" and "ESC"
//create the same value in X11 or Cocoa
//So using something like
//keysym == kVK_Escape || keysym == XK_Escape
//is not a good idea
int	keypress(int key, t_allvars *a)
{
	if (key == kVK_Escape)
		quit(a, 0);
	if (key == kVK_ANSI_I)
		a->mode = 'i';
	if (key == kVK_ANSI_O)
		a->mode = 'o';
	if (key == kVK_ANSI_P)
		a->mode = 'p';
	if (key == kVK_ANSI_C)
		a->mode = 'c';
	if (key == kVK_ANSI_A)
		a->tlx -= 1;
	if (key == kVK_ANSI_D)
		a->tlx += 1;
	if (key == kVK_ANSI_S)
		a->tly -= 1;
	if (key == kVK_ANSI_W)
		a->tly += 1;
	if (key == kVK_ANSI_Z)
	{
		if (a->mode != 'p')
			a->zoom += 0.5;
		else
			a->fov -= 10;
	}
	if (key == kVK_ANSI_X)
	{
		if (a->mode != 'p')
			a->zoom -= 0.5;
		else
			a->fov += 10;
	}
	if (key == kVK_UpArrow)
		a->scale += 0.1;
	if (key == kVK_DownArrow)
		a->scale -= 0.1;
	if (key == kVK_LeftArrow)
		a->brange += 0.005;
	if (key == kVK_RightArrow)
		a->brange -= 0.005;
	if (key == kVK_ANSI_F)
		a->rz -= 5;
	if (key == kVK_ANSI_G)
		a->rz += 5;
	if (key == kVK_ANSI_H)
		a->ry -= 5;
	if (key == kVK_ANSI_J)
		a->ry += 5;
	if (key == kVK_ANSI_K)
		a->rx -= 5;
	if (key == kVK_ANSI_L)
		a->rx += 5;
	if (key == kVK_ANSI_M)
	{
		if (a->menu == 0)
			a->menu = 1;
		else
			a->menu = 0;
	}
	return (0);
}

//Returns a linear value in the range [0,1]
//for sRGB input in [0,255].
float ChannelInvCompanding(int c)
{
	float	y;

	c = c & 0xFF;
	y = (float) c;
	y = y / 255.0;
	if (c <= 0.04045)
		y = y / 12.92;
	else
		y = pow(((y + 0.055) / 1.055), 2.4);
	return (y);
}

//Convert color from 0..255 to 0..1
//Inverse Srgb Companding for 
//Red, Green, and Blue
float	*InverseSrgbCompanding(int c)
{
	float	*r;

	r = malloc(4 * sizeof(float));
	r[0] = (float) get_t(c);
	r[1] = ChannelInvCompanding(get_r(c));
	r[2] = ChannelInvCompanding(get_g(c));
	r[3] = ChannelInvCompanding(get_b(c));
	return (r);
}

//Apply companding to Red, Green, and Blue
float ChannelCompanding(float c)
{
	float	x;

	if (c <= 0.0031308)
		x = 12.92 * c;
	else
		x = (1.055 * pow(c, (1 / 2.4))) - 0.055;
	return (x);
}

//return new color. Convert 0..1 back into 0..255
//Srgb Companding for Red, Green, and Blue
int SrgbCompanding(float *c)
{
	int	t;
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
float sumChannels(float *c)
{
	float	x;

	x = c[1] + c[2] + c[3];
	return (x);
}

//Lerping see
//https://en.wikipedia.org/wiki/Linear_interpolation
//#Programming_language_support
float lerp_int(float c1, float c2, float t)
{
	return (c1 * (1 - t) + c2 * t);
}

float	*lerp(float *c1, float *c2, float t)
{
	float	*r;

	r = malloc(4 * sizeof(float));
	r[1] = (c1[1] * (1 - t)) + c2[1] * t;
	r[2] = (c1[2] * (1 - t)) + c2[2] * t;
	r[3] = (c1[3] * (1 - t)) + c2[3] * t;
	return (r);
}

void	fix(float *c, float intensity, float total)
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

int	calculate_color_step(t_calcol *c, float step)
{
	c->intensity = pow(lerp_int(c->bright1, c->bright2, step), (1 / GAMMA));
	c->color = lerp(c->color1_lin, c->color2_lin, step);
	c->total = sumChannels(c->color);
	if (c->total != 0)
		fix(c->color, c->intensity, c->total);
	return (SrgbCompanding(c->color));
}

void 	inverse(t_calcol *c, int scolor, int ecolor)
{
	c->color1_lin = InverseSrgbCompanding(scolor);
	c->bright1 = pow(sumChannels(c->color1_lin), GAMMA);
	c->color2_lin = InverseSrgbCompanding(ecolor);
	c->bright2 = pow(sumChannels(c->color2_lin), GAMMA);
}

void	init_bresenhams(t_bresvars *v, t_coord *start, t_coord *end)
{
	v->x = start->x;
	v->y = start->y;
	v->dx = abs(end->x - start->x);
	v->dy = abs(end->y - start->y);
	v->s1 = sign(end->x - start->x);
	v->s2 = sign(end->y - start->y);
	v->swap = 0;
	if (v->dy > v->dx)
	{
		v->temp = v->dx;
		v->dx = v->dy;
		v->dy = v->temp;
		v->swap = 1;
	}
}

void	bresenhams_cycle(t_bresvars *v, t_calcol *c, t_allvars *a)
{
	v->d = 2 * v->dy - v->dx;
	c->step_v = (1.0 / v->dx);
	v->i = 0;
	c->step = 0;
	while (v->i < v->dx)
	{
		c->step += c->step_v;
		c->clr = calculate_color_step(c, c->step);
		my_mlx_pixel_put(&a->img, v->x, v->y, c->clr);
		while (v->d >= 0)
		{
			v->d = v->d - 2 * v->dx;
			if (v->swap)
				v->x += v->s1;
			else
				v->y += v->s2;
		}
		v->d = v->d + 2 * v->dy;
		if (v->swap)
			v->y += v->s2;
		else
			v->x += v->s1;
		v->i++;
	}
}

void	bresenhams_alg(t_coord *start, t_coord *end, t_allvars *a)
{
	t_bresvars	v;
	t_calcol	c;

	inverse(&c, start->c, end->c);
	init_bresenhams(&v, start, end);
	bresenhams_cycle(&v, &c, a);
	free(c.color1_lin);
	free(c.color2_lin);
}

void	clear_image(t_allvars *a)
{
	int k;
	int l;

	k = 0;
	while (k < IMG_H)
	{
		l = 0;
		while (l < IMG_W)
		{
			my_mlx_pixel_put(&a->img, l, k, 0x151515);
			l++;
		}
		k++;
	}
	mlx_put_image_to_window(a->data.mlx_ptr, a->data.win_ptr, a->img.img, 0, 0);
	mlx_clear_window(a->data.mlx_ptr, a->data.win_ptr);
}

void	menu_text(t_allvars *a)
{
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 50, LTR_C, "W,A,S,D to translate on x & y");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 90, LTR_C, "I for isometric projection");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 110, LTR_C, "O for parallel projection");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 130, LTR_C, "P for perspective projection");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 150, LTR_C, "C for conical projection");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 180, LTR_C, "Z and X for zoom");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 200, LTR_C, "Up and Down to scale z");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 220, LTR_C, "Left and right to scale bending");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 260, LTR_C, "F and G to rotate on z");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 280, LTR_C, "H and J to rotate on y");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 300, LTR_C, "K and L to rotate on x");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr, 20, 320, LTR_C, "M to toggle the menu");
}

void	put_lines(t_allvars *a)
{
	for (int k = 0; k < a->ty; k++)
	{
		for (int l = 0; l < a->tx; l++)
		{
			if (l < a->tx - 1)
				bresenhams_alg(&a->c[k * a->tx + l], &a->c[k * a->tx + l + 1], a);
			if (k < a->ty -1)
				bresenhams_alg(&a->c[k * a->tx + l], &a->c[(k + 1 )* a->tx + l], a);
		}
	}
	if (a->menu == 1)
	{
		for (int i = 0; i < IMG_H; i++)
			for (int j = 0; j < MENU_W; j++)
				my_mlx_pixel_put(&a->img, j, i, 0xc3c3c3);
	}
}

int	render(t_allvars *a)
{
	make_matrix(a);
	if (a->data.win_ptr != NULL)
	{
		clear_image(a);
		put_lines(a);
		mlx_put_image_to_window(a->data.mlx_ptr, a->data.win_ptr, a->img.img, 0, 0);
		if (a->menu == 1)
			menu_text(a);
	}	
	return (0);
}

void	delete_arr_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
 * @brief If inputed j (aka x) is zero it assumes 
 * it is the first time running and counts
 * how many strings are in array arr.
 * 
 * However if j is not zero it again counts how many
 * strings are in array arr and compares it with j
 * If different it quits the program
 */
void	check_items_inline(t_allvars *a, char *line, char **arr, int *j)
{
	int			j2;

	if (*j == 0)
		while (arr[*j] != 0)
			(*j)++;
	else
	{
		j2 = 0;
		while (arr[j2] != 0)
			j2++;
		if (*j != j2)
		{
			delete_arr_arr(arr);
			free(line);
			quit(a, 3);
		}
	}
}

void	set_identity(t_allvars *a)
{
	a->tw.m[0][0] = 1;
	a->tw.m[0][1] = 0;
	a->tw.m[0][2] = 0;
	a->tw.m[0][3] = 0;
	a->tw.m[1][0] = 0;
	a->tw.m[1][1] = 1;
	a->tw.m[1][2] = 0;
	a->tw.m[1][3] = 0;
	a->tw.m[2][0] = 0;
	a->tw.m[2][1] = 0;
	a->tw.m[2][2] = 1;
	a->tw.m[2][3] = 0;
	a->tw.m[3][0] = 0;
	a->tw.m[3][1] = 0;
	a->tw.m[3][2] = 0;
	a->tw.m[3][3] = 1;
}

void	set_iso_op_matrix(t_pmatrix *wc, t_allvars *al)
{
	float	a;
	float	b;
	float	g;
	
	a = (45.0 + al->rz) * (M_PI / 180.0);
	b = (0.0 + al->ry) * (M_PI / 180.0);
	g = (35.264 + al->rx) * (M_PI / 180.0);
	wc->m[0][0] = cos(a) * cos(b);
	wc->m[0][1] = cos(a) * sin(b) * sin(g) - sin(a) * cos(g);
	wc->m[0][2] = cos(a) * sin(b) * cos(g) + sin(a) * sin(g);
	wc->m[0][3] = 0;
	wc->m[1][0] = sin(a) * (-cos(b));
	wc->m[1][1] = -sin(a) * sin(b) * sin(g) - cos(a) * cos(g);
	wc->m[1][2] = cos(a) * sin(g) * - sin(a) * sin(b) * cos(g);
	wc->m[1][3] = 0;
	wc->m[2][0] = -al->scale * sin(b);
	wc->m[2][1] = al->scale * cos(b) * sin(g);
	wc->m[2][2] = al->scale * cos(b) * cos(g);
	wc->m[2][3] = 0;
	wc->m[3][0] = al->tlx;
	wc->m[3][1] = al->tly;
	wc->m[3][2] = al->tlz;
	wc->m[3][3] = 1;
}

void	set_paralel_matrix(t_pmatrix *wc, t_allvars *al)
{
	float	a;
	float	b;
	float	g;
	
	a = (0 + al->rz) * (M_PI / 180.0);
	b = (0 + al->ry) * (M_PI / 180.0);
	g = (0 + al->rx) * (M_PI / 180.0);
	wc->m[0][0] = cos(a) * cos(b);
	wc->m[0][1] = cos(a) * sin(b) * sin(g) - sin(a) * cos(g);
	wc->m[0][2] = cos(a) * sin(b) * cos(g) + sin(a) * sin(g);
	wc->m[0][3] = 0;
	wc->m[1][0] = sin(a) * (-cos(b));
	wc->m[1][1] = -sin(a) * sin(b) * sin(g) - cos(a) * cos(g);
	wc->m[1][2] = cos(a) * sin(g) * - sin(a) * sin(b) * cos(g);
	wc->m[1][3] = 0;
	wc->m[2][0] = -al->scale * sin(b);
	wc->m[2][1] = al->scale * cos(b) * sin(g);
	wc->m[2][2] = al->scale * cos(b) * cos(g);
	wc->m[2][3] = 0;
	wc->m[3][0] = al->tlx;
	wc->m[3][1] = al->tly;
	wc->m[3][2] = al->tlz;
	wc->m[3][3] = 1;
}


/*
wc->m[3][0] = cos(b) * (al->tlx * cos(a) + al->tly * sin(a)) - al->tlz * sin(b) ;
wc->m[3][1] = sin(g) * (sin(b) * (al->tlx * cos(a) + al->tly * sin(a)) + al->tlz * cos(b)) + cos(g) * (al->tly * cos(a) - al->tlx * sin(a));
wc->m[3][2] = cos(g) * (sin(b) * (al->tlx * cos(a) + al->tly * sin(a)) + al->tlz * cos(b)) - sin(g) * (al->tly * cos(a) - al->tlx * sin(a));
*/
void	world_matrix(t_pmatrix *wc, t_allvars *al)
{	
	float	a;
	float	b;
	float	g;
	
	a = (0 + al->rz) * (M_PI / 180.0);
	b = (0 + al->ry) * (M_PI / 180.0);
	g = (0 + al->rx) * (M_PI / 180.0);
	wc->m[0][0] = cos(a) * cos(b);
	wc->m[0][1] = cos(a) * sin(b) * sin(g) - sin(a) * cos(g);
	wc->m[0][2] = cos(a) * sin(b) * cos(g) + sin(a) * sin(g);
	wc->m[0][3] = 0;
	wc->m[1][0] = sin(a) * (-cos(b));
	wc->m[1][1] = -sin(a) * sin(b) * sin(g) - cos(a) * cos(g);
	wc->m[1][2] = cos(a) * sin(g) * - sin(a) * sin(b) * cos(g);
	wc->m[1][3] = 0;
	wc->m[2][0] = -al->scale * sin(b);
	wc->m[2][1] = al->scale * cos(b) * sin(g);
	wc->m[2][2] = al->scale * cos(b) * cos(g);
	wc->m[2][3] = 0;
	wc->m[3][0] = al->tlx;
	wc->m[3][1] = al->tly;
	wc->m[3][2] = al->tlz;
	wc->m[3][3] = 1;
}

void	set_projection_matrix(t_pmatrix *pm, t_allvars *a)
{
	float	scale;

	scale = 1.0 / tan(a->fov * 0.5 * M_PI / 180.0);
	pm->m[0][0] = scale;
	pm->m[1][1] = scale;
	pm->m[2][2] = (-a->f) / (a->f - a->n);
	pm->m[3][2] = (-a->f * a->n) / (a->f - a->n);
	pm->m[2][3] = -1.0;
	pm->m[3][3] = 0.0;
}


void	set_ortog_matrix(t_pmatrix *pm, t_allvars *a)
{
	pm->m[0][0] = (2.0 / (a->r - a->l)) * a->zoom;
	pm->m[0][1] = 0;
	pm->m[0][2] = 0;
	pm->m[0][3] = 0;
	pm->m[1][0] = 0;
	pm->m[1][1] = (2.0 / (a->t - a->b)) * a->zoom;
	pm->m[1][2] = 0;
	pm->m[1][3] = 0;
	pm->m[2][0] = 0;
	pm->m[2][1] = 0;
	pm->m[2][2] = -(2.0 / (a->f - a->n)) * a->zoom;
	pm->m[2][3] = 0;
	pm->m[3][0] = -(a->r + a->l) / (a->r - a->l);
	pm->m[3][1] = -(a->t + a->b) / (a->t - a->b);
	pm->m[3][2] = -(a->f + a->n) / (a->f - a->n);
	pm->m[3][3] = 1;
}

void	set_ortog_matrix2(t_pmatrix *pm, t_allvars *a)
{
	pm->m[0][0] = (2.0 / (a->r - a->l)) * a->zoom;
	pm->m[0][1] = 0;
	pm->m[0][2] = 0;
	pm->m[0][3] = 0;
	pm->m[1][0] = 0;
	pm->m[1][1] = -(2.0 / (a->t - a->b)) * a->zoom;
	pm->m[1][2] = 0;
	pm->m[1][3] = 0;
	pm->m[2][0] = 0;
	pm->m[2][1] = 0;
	pm->m[2][2] = (-2.0 / (a->f - a->n)) * -a->zoom;
	pm->m[2][3] = 0;
	pm->m[3][0] = -(a->r + a->l) / (a->r - a->l);
	pm->m[3][1] = -(a->t + a->b) / (a->t - a->b);
	pm->m[3][2] = -(a->f + a->n) / (a->f - a->n);
	pm->m[3][3] = 1;
}

/**
 * @brief multiplies matrix i with m and outputs it to o
 * 
 * @param i input
 * @param o output
 * @param m matrix to multiply with
 */
void	multiply_matrix_vector(t_point *i, t_point *o, t_pmatrix *m)
{
	float	w;

	o->x = i->x * m->m[0][0] + i->y * m->m[1][0]
		+ i->z * m->m[2][0] + m->m[3][0];
	o->y = i->x * m->m[0][1] + i->y * m->m[1][1] 
		+ i->z * m->m[2][1] + m->m[3][1];
	o->z = i->x * m->m[0][2] + i->y * m->m[1][2]
		+ i->z * m->m[2][2] + m->m[3][2];
	w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3] + m->m[3][3];
	if (w != 0.0f)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
	o->c = i->c;
}

/**
 * @brief multiplies matrix i with m and outputs it to i
 * 
 * @param i input
 * @param m matrix to multiply with
 */
void	transform_matrix_vector(t_point *i, t_pmatrix *m)
{
	float	w;
	t_point	o;

	o.x = i->x * m->m[0][0] + i->y * m->m[1][0]
		+ i->z * m->m[2][0] + m->m[3][0];
	o.y = i->x * m->m[0][1] + i->y * m->m[1][1]
		+ i->z * m->m[2][1] + m->m[3][1];
	o.z = i->x * m->m[0][2] + i->y * m->m[1][2]
		+ i->z * m->m[2][2] + m->m[3][2];
	w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3] + m->m[3][3];
	if (w != 0.0f)
	{
		o.x /= w;
		o.y /= w;
		o.z /= w;
	}
	o.c = i->c;
	*i = o;
}

float	dmin(float x,float y){
	if (x > y)
		return (y);
	else
		return (x);
}

float	dmax(float x,float y){
	if (x > y)
		return (x);
	else
		return (y);
}

void	set_bb_variables(t_allvars *a, t_point min_camera, t_point max_camera)
{
	float	ar;
	float	maxx;
	float	maxy;
	float	max;

	ar = (float)IMG_W / (float)IMG_H; 
	maxx = dmax(fabs(min_camera.x), fabs(max_camera.x));
	maxy = dmax(fabs(min_camera.y), fabs(max_camera.y));
	max = dmax(maxx, maxy);
	a->r = (max * ar);
	a->t = max; 
	a->l = -(a->r);
	a->b = -(a->t); 
}

void	set_bounding_box_while(t_allvars *a, t_point *min_world,
									t_point *max_world)
{
	int	i;

	i = 0;
	while (i < (a->tx * a->ty))
	{
		if (a->i[i].x < min_world->x)
			min_world->x = a->i[i].x;
		if (a->i[i].y < min_world->y)
			min_world->y = a->i[i].y;
		if (a->i[i].z < min_world->z)
			min_world->z = a->i[i].z;
		if (a->i[i].x > max_world->x)
			max_world->x = a->i[i].x;
		if (a->i[i].y > max_world->y)
			max_world->y = a->i[i].y;
		if (a->i[i].z > max_world->z)
			max_world->z = a->i[i].z;
		i++;
	}
}

// compute the scene bounding box
void	set_bounding_box(t_allvars *a)
{
	t_point	min_world;
	t_point	max_world;
	t_point	min_camera;
	t_point	max_camera;

	min_world = (t_point){__FLT_MAX__, __FLT_MAX__, __FLT_MAX__, 0};
	max_world = (t_point){-__FLT_MAX__, -__FLT_MAX__, -__FLT_MAX__, 0};
	set_bounding_box_while(a, &min_world, &max_world);
	multiply_matrix_vector(&min_world, &min_camera, &a->wc);
	multiply_matrix_vector(&max_world, &max_camera, &a->wc);
	set_bb_variables(a, min_camera, max_camera);
}

void	get_z_offset(t_allvars *a)
{
	t_point	max_world;
	int		i;

	max_world = (t_point){-__FLT_MAX__, -__FLT_MAX__, -__FLT_MAX__, 0};
	i = 0;
	while (i++ < (a->tx * a->ty))
		if (a->i[i].z > max_world.z)
			max_world.z = a->i[i].z;
	a->tlz = -(max_world.z + 1);
}

void	get_xyz_offset(t_allvars *a)
{
	a->tlx = -(a->tx / 4);
	a->tly = (a->ty / 4);
	get_z_offset(a);
}

float	clamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}

float	inv_value(float value)
{
	if (value > 0.0)
		return (1.0 / value);
	else
		return (0.0);
}
 
int	my_sign(float value)
{
	if (value < 0.0)
		return (-1);
	else if (value > 0.0)
		return (1);
	else
		return (0);
}

void	set_rot_y(t_pmatrix *mat, float ammount_rad)
{
	float c;
	float s;

	s = sin(ammount_rad);
	c = cos(ammount_rad);
	mat->m[0][0] = c;
	mat->m[0][1] = 0;
	mat->m[0][2] = s;
	mat->m[0][3] = 0;
	mat->m[1][0] = 0;
	mat->m[1][1] = 1;
	mat->m[1][2] = 0;
	mat->m[1][3] = 0;
	mat->m[2][0] = -s;
	mat->m[2][1] = 0;
	mat->m[2][2] = c;
	mat->m[2][3] = 0;
	mat->m[3][0] = 0;
	mat->m[3][1] = 0;
	mat->m[3][2] = 0;
	mat->m[3][3] = 1;
}

void	matrix_multiply_4by4(float src1[4][4], float src2[4][4], float dest[4][4])
{
	dest[0][0] = src1[0][0] * src2[0][0] + src1[0][1] * src2[1][0] + src1[0][2] * src2[2][0] + src1[0][3] * src2[3][0]; 
	dest[0][1] = src1[0][0] * src2[0][1] + src1[0][1] * src2[1][1] + src1[0][2] * src2[2][1] + src1[0][3] * src2[3][1]; 
	dest[0][2] = src1[0][0] * src2[0][2] + src1[0][1] * src2[1][2] + src1[0][2] * src2[2][2] + src1[0][3] * src2[3][2]; 
	dest[0][3] = src1[0][0] * src2[0][3] + src1[0][1] * src2[1][3] + src1[0][2] * src2[2][3] + src1[0][3] * src2[3][3]; 
	dest[1][0] = src1[1][0] * src2[0][0] + src1[1][1] * src2[1][0] + src1[1][2] * src2[2][0] + src1[1][3] * src2[3][0]; 
	dest[1][1] = src1[1][0] * src2[0][1] + src1[1][1] * src2[1][1] + src1[1][2] * src2[2][1] + src1[1][3] * src2[3][1]; 
	dest[1][2] = src1[1][0] * src2[0][2] + src1[1][1] * src2[1][2] + src1[1][2] * src2[2][2] + src1[1][3] * src2[3][2]; 
	dest[1][3] = src1[1][0] * src2[0][3] + src1[1][1] * src2[1][3] + src1[1][2] * src2[2][3] + src1[1][3] * src2[3][3]; 
	dest[2][0] = src1[2][0] * src2[0][0] + src1[2][1] * src2[1][0] + src1[2][2] * src2[2][0] + src1[2][3] * src2[3][0]; 
	dest[2][1] = src1[2][0] * src2[0][1] + src1[2][1] * src2[1][1] + src1[2][2] * src2[2][1] + src1[2][3] * src2[3][1]; 
	dest[2][2] = src1[2][0] * src2[0][2] + src1[2][1] * src2[1][2] + src1[2][2] * src2[2][2] + src1[2][3] * src2[3][2]; 
	dest[2][3] = src1[2][0] * src2[0][3] + src1[2][1] * src2[1][3] + src1[2][2] * src2[2][3] + src1[2][3] * src2[3][3]; 
	dest[3][0] = src1[3][0] * src2[0][0] + src1[3][1] * src2[1][0] + src1[3][2] * src2[2][0] + src1[3][3] * src2[3][0]; 
	dest[3][1] = src1[3][0] * src2[0][1] + src1[3][1] * src2[1][1] + src1[3][2] * src2[2][1] + src1[3][3] * src2[3][1]; 
	dest[3][2] = src1[3][0] * src2[0][2] + src1[3][1] * src2[1][2] + src1[3][2] * src2[2][2] + src1[3][3] * src2[3][2]; 
	dest[3][3] = src1[3][0] * src2[0][3] + src1[3][1] * src2[1][3] + src1[3][2] * src2[2][3] + src1[3][3] * src2[3][3]; 
};

void sum_vect(t_point *src1, t_point *src2)
{
	src1->x += src2->x;
	src1->y += src2->y;
	src1->z += src2->z;
}

void sub_vect(t_point *src1, t_point *src2)
{
	src1->x -= src2->x;
	src1->y -= src2->y;
	src1->z -= src2->z;
}

void	bend_it2(t_point *mvPos, t_allvars *a)
{
	float		curveAmount;
	float		invRange;
	float		amountToApplyCurve;
	t_point		point;
	t_pmatrix	rmat;

	curveAmount = a->brange / a->tx/4;
	invRange = inv_value(a->brange);

	amountToApplyCurve = clamp(mvPos->z * invRange, 0.0, 1.0);
	set_rot_y(&rmat, curveAmount * amountToApplyCurve * my_sign(mvPos->x));
	point = (t_point){0, 0, -a->brange * amountToApplyCurve, 0};
	sum_vect(mvPos, &point);
	transform_matrix_vector(mvPos, &rmat);
}

void	bend_it(t_point *inpt, t_point *outpt, t_allvars *a)
{
	float	vv;
	float	x;

	x = abs((int)inpt->x);
	vv = (x * x) * (a->brange);
	outpt->x = inpt->x;
	outpt->y = inpt->y;
	outpt->z = inpt->z + vv;
}

//checks file and gets number of rows and columns
void	count_file_items(t_allvars *a, char **argv)
{
	char	*line;
	char	*pos;
	char	**arr;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		quit(a, 2);
	line = get_next_line(fd);
	a->x = 0;
	a->y = 0;
	while (line != NULL)
	{
		ft_printf("%s", line);
		pos = ft_strchr(line, '\n');
		*pos = '\0';
		arr = ft_split(line, ' ');
		check_items_inline(a, line, arr, &a->x);
		delete_arr_arr(arr);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		a->y++;
	}
	close(fd);
}

void	allocate_matrices(t_allvars *a)
{
	a->i = malloc(sizeof(t_point) * (a->tx * a->ty));
	if (!a->i)
		quit(a, 4);
	a->bt = malloc(sizeof(t_point) * (a->tx * a->ty));
	if (!a->bt)
		quit(a, 5);
	a->o = malloc(sizeof(t_point) * (a->tx * a->ty));
	if (!a->o)
		quit(a, 6);
	a->c = malloc(sizeof(t_coord) * (a->tx * a->ty));
	if (!a->c)
		quit(a, 7);
}

int hex2int(char *hex)
{
	int val;
	int byte;
	
	val = 0;
	while (*hex) {
		byte = *hex++;
		if (byte == '0' && (*hex == 'x' || *hex == 'X'))
		{
			hex++;
			continue;
		}
		else if (byte >= '0' && byte <= '9') 
			byte = byte - '0';
		else if (byte >= 'a' && byte <='f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <='F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}

void	get_z_values(t_allvars *a, char **argv)
{
	int		fd;
	char	*line;
	char	*pos;
	char	**arr;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		quit(a, 2);

	a->tx = a->x;
	a->ty = a->y;
	a->y = 0;
	//input vector array
	allocate_matrices(a);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("%s", line);
		pos = ft_strchr(line, '\n');
		*pos = '\0';
		arr = ft_split(line, ' ');
		a->x = 0;
		while (a->x < a->tx)
		{
			char	*pos2 = ft_strchr(arr[a->x], ',');
			char	**arr2;
			if (pos2)
			{
				arr2 = ft_split(arr[a->x], ',');
				a->i[a->y * a->tx + a->x].x = (float)a->x -(a->tx/2);
				a->i[a->y * a->tx + a->x].y = (float)a->y -(a->ty/2);
				a->i[a->y * a->tx + a->x].z = (float)(ft_atoi(arr2[0]));
				a->i[a->y * a->tx + a->x].c = (hex2int(arr2[1]));
				delete_arr_arr(arr2);
			}
			else
			{
				a->i[a->y * a->tx + a->x].x = (float)a->x -(a->tx/2);
				a->i[a->y * a->tx + a->x].y = (float)a->y -(a->ty/2);
				a->i[a->y * a->tx + a->x].z = (float)(ft_atoi(arr[a->x]));
				if (a->i[a->y * a->tx + a->x].z >= 10)
					a->i[a->y * a->tx + a->x].c = 0xf3b03d;
				else if (a->i[a->y * a->tx + a->x].z <= -10)
					a->i[a->y * a->tx + a->x].c = 0xffffff;
				else
					a->i[a->y * a->tx + a->x].c = 0x9A1F6A;
			}
			a->x++;
		}
		delete_arr_arr(arr);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		a->y++;
	}
	close(fd);
}

void	set_matrices(t_allvars *a)
{
	if (a->mode == 'i')
		set_iso_op_matrix(&a->wc, a);
	else if (a->mode == 'o')
		set_paralel_matrix(&a->wc, a);
	else
		world_matrix(&a->wc, a);
	if (a->mode == 'i' || a->mode == 'o')
	{
		set_bounding_box(a);
		set_ortog_matrix(&a->pm, a);
	}
	else if (a->mode == 'p')
		set_projection_matrix(&a->pm, a);
}

void	make_matrix(t_allvars *a)
{
	int	xp;
	int	yp;
	
	set_matrices(a);
	for (int k = 0; k < a->ty; k++)
	{
		for (int l = 0; l < a->tx; l++)
		{
			if (a->mode == 'c')
			{
				bend_it(&a->i[k * a->tx + l], &a->bt[k * a->tx + l], a);
				transform_matrix_vector(&a->bt[k * a->tx + l], &a->wc);
				multiply_matrix_vector(&a->bt[k * a->tx + l], &a->o[k * a->tx + l], &a->pm);
			}
			else
			multiply_matrix_vector(&a->i[k * a->tx + l], &a->bt[k * a->tx + l], &a->wc);
			multiply_matrix_vector(&a->bt[k * a->tx + l], &a->o[k * a->tx + l], &a->pm);
			if (a->mode != 'i' || a->mode != 'o')
			{
				xp = (int)((a->o[k * a->tx + l].x + 1) * 0.5 * IMG_W); 
				yp = (int)((1 - (a->o[k * a->tx + l].y + 1) * 0.5) * IMG_H);
			}
			else
			{
				xp = (int)(a->o[k * a->tx + l].x); 
				yp = (int)(a->o[k * a->tx + l].y);
			}
			a->c[k * a->tx + l].x = xp;
			a->c[k * a->tx + l].y = yp;
			a->c[k * a->tx + l].c = a->o[k * a->tx + l].c;
		}
	}
}

int	main(int argc, char **argv)
{
	t_allvars	a;
	t_data		data;
	t_img		img;

	a = (t_allvars){0};
	//open file
	if (argc != 2)
		quit(&a, 1);
	count_file_items(&a, argv);
	get_z_values(&a, argv);

	//initialize server and check
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(MLX_ERROR);
	//create new window and check; free mlx pointer on error
	data.win_ptr = mlx_new_window(data.mlx_ptr, IMG_W, IMG_H, "FdF");
	if (data.win_ptr == NULL)
		exit(WIN_ERROR);
	//create new image
	img.img = mlx_new_image(data.mlx_ptr, IMG_W, IMG_H);
	//get image parameters info
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	
	a.data = data;
	a.img = img;
	a.pm = (t_pmatrix){0};
	a.wc = (t_pmatrix){0};
	a.tw = (t_pmatrix){0};
	a.fov = 90; 
	a.n = 0.05; 
	a.f = 100;
	a.brange = 0.015;
	get_z_offset(&a);
	a.scale = 1;
	a.zoom = 1;
	a.mode = 'i';
	

	mlx_loop_hook(data.mlx_ptr, render, &a);
	mlx_key_hook(data.win_ptr, keypress, &a);
	//close program on close window
	mlx_hook(data.win_ptr, 17, 0, quit, &a);

	mlx_loop(data.mlx_ptr);
	//close window and free server
}

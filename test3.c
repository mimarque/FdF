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

#define MLX_ERROR 1
#define WIN_ERROR 2
#define PURPLE 0x00FFFFFF
#define IMG_W 500
#define IMG_H 500
#define GAMMA 0.43
#define BUFFER_SIZE 42
#define NUM_OF_FD 256


/*
** # define KEYPRESSMASK (1L<<0)
** # define KEYRELEASEMASK (1L<<1)
*/
/* MacRoman character codes*/
enum {
  kNullCharCode                 = 0,
  kHomeCharCode                 = 1,
  kEnterCharCode                = 3,
  kEndCharCode                  = 4,
  kHelpCharCode                 = 5,
  kBellCharCode                 = 7,
  kBackspaceCharCode            = 8,
  kTabCharCode                  = 9,
  kLineFeedCharCode             = 10,
  kVerticalTabCharCode          = 11,
  kPageUpCharCode               = 11,
  kFormFeedCharCode             = 12,
  kPageDownCharCode             = 12,
  kReturnCharCode               = 13,
  kFunctionKeyCharCode          = 16,
  kCommandCharCode              = 17,   /* glyph available only in system fonts*/
  kCheckCharCode                = 18,   /* glyph available only in system fonts*/
  kDiamondCharCode              = 19,   /* glyph available only in system fonts*/
  kAppleLogoCharCode            = 20,   /* glyph available only in system fonts*/
  kEscapeCharCode               = 27,
  kClearCharCode                = 27,
  kLeftArrowCharCode            = 28,
  kRightArrowCharCode           = 29,
  kUpArrowCharCode              = 30,
  kDownArrowCharCode            = 31,
  kSpaceCharCode                = 32,
  kDeleteCharCode               = 127,
  kBulletCharCode               = 165,
  kNonBreakingSpaceCharCode     = 202
};

/* useful Unicode code points*/
enum {
  kShiftUnicode                 = 0x21E7, /* Unicode UPWARDS WHITE ARROW*/
  kControlUnicode               = 0x2303, /* Unicode UP ARROWHEAD*/
  kOptionUnicode                = 0x2325, /* Unicode OPTION KEY*/
  kCommandUnicode               = 0x2318, /* Unicode PLACE OF INTEREST SIGN*/
  kPencilUnicode                = 0x270E, /* Unicode LOWER RIGHT PENCIL; actually pointed left until Mac OS X 10.3*/
  kPencilLeftUnicode            = 0xF802, /* Unicode LOWER LEFT PENCIL; available in Mac OS X 10.3 and later*/
  kCheckUnicode                 = 0x2713, /* Unicode CHECK MARK*/
  kDiamondUnicode               = 0x25C6, /* Unicode BLACK DIAMOND*/
  kBulletUnicode                = 0x2022, /* Unicode BULLET*/
  kAppleLogoUnicode             = 0xF8FF /* Unicode APPLE LOGO*/
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
  kVK_ANSI_A                    = 0x00,
  kVK_ANSI_S                    = 0x01,
  kVK_ANSI_D                    = 0x02,
  kVK_ANSI_F                    = 0x03,
  kVK_ANSI_H                    = 0x04,
  kVK_ANSI_G                    = 0x05,
  kVK_ANSI_Z                    = 0x06,
  kVK_ANSI_X                    = 0x07,
  kVK_ANSI_C                    = 0x08,
  kVK_ANSI_V                    = 0x09,
  kVK_ANSI_B                    = 0x0B,
  kVK_ANSI_Q                    = 0x0C,
  kVK_ANSI_W                    = 0x0D,
  kVK_ANSI_E                    = 0x0E,
  kVK_ANSI_R                    = 0x0F,
  kVK_ANSI_Y                    = 0x10,
  kVK_ANSI_T                    = 0x11,
  kVK_ANSI_1                    = 0x12,
  kVK_ANSI_2                    = 0x13,
  kVK_ANSI_3                    = 0x14,
  kVK_ANSI_4                    = 0x15,
  kVK_ANSI_6                    = 0x16,
  kVK_ANSI_5                    = 0x17,
  kVK_ANSI_Equal                = 0x18,
  kVK_ANSI_9                    = 0x19,
  kVK_ANSI_7                    = 0x1A,
  kVK_ANSI_Minus                = 0x1B,
  kVK_ANSI_8                    = 0x1C,
  kVK_ANSI_0                    = 0x1D,
  kVK_ANSI_RightBracket         = 0x1E,
  kVK_ANSI_O                    = 0x1F,
  kVK_ANSI_U                    = 0x20,
  kVK_ANSI_LeftBracket          = 0x21,
  kVK_ANSI_I                    = 0x22,
  kVK_ANSI_P                    = 0x23,
  kVK_ANSI_L                    = 0x25,
  kVK_ANSI_J                    = 0x26,
  kVK_ANSI_Quote                = 0x27,
  kVK_ANSI_K                    = 0x28,
  kVK_ANSI_Semicolon            = 0x29,
  kVK_ANSI_Backslash            = 0x2A,
  kVK_ANSI_Comma                = 0x2B,
  kVK_ANSI_Slash                = 0x2C,
  kVK_ANSI_N                    = 0x2D,
  kVK_ANSI_M                    = 0x2E,
  kVK_ANSI_Period               = 0x2F,
  kVK_ANSI_Grave                = 0x32,
  kVK_ANSI_KeypadDecimal        = 0x41,
  kVK_ANSI_KeypadMultiply       = 0x43,
  kVK_ANSI_KeypadPlus           = 0x45,
  kVK_ANSI_KeypadClear          = 0x47,
  kVK_ANSI_KeypadDivide         = 0x4B,
  kVK_ANSI_KeypadEnter          = 0x4C,
  kVK_ANSI_KeypadMinus          = 0x4E,
  kVK_ANSI_KeypadEquals         = 0x51,
  kVK_ANSI_Keypad0              = 0x52,
  kVK_ANSI_Keypad1              = 0x53,
  kVK_ANSI_Keypad2              = 0x54,
  kVK_ANSI_Keypad3              = 0x55,
  kVK_ANSI_Keypad4              = 0x56,
  kVK_ANSI_Keypad5              = 0x57,
  kVK_ANSI_Keypad6              = 0x58,
  kVK_ANSI_Keypad7              = 0x59,
  kVK_ANSI_Keypad8              = 0x5B,
  kVK_ANSI_Keypad9              = 0x5C
};

/* keycodes for keys that are independent of keyboard layout*/
enum {
  kVK_Return                    = 0x24,
  kVK_Tab                       = 0x30,
  kVK_Space                     = 0x31,
  kVK_Delete                    = 0x33,
  kVK_Escape                    = 0x35,
  kVK_Command                   = 0x37,
  kVK_Shift                     = 0x38,
  kVK_CapsLock                  = 0x39,
  kVK_Option                    = 0x3A,
  kVK_Control                   = 0x3B,
  kVK_RightShift                = 0x3C,
  kVK_RightOption               = 0x3D,
  kVK_RightControl              = 0x3E,
  kVK_Function                  = 0x3F,
  kVK_F17                       = 0x40,
  kVK_VolumeUp                  = 0x48,
  kVK_VolumeDown                = 0x49,
  kVK_Mute                      = 0x4A,
  kVK_F18                       = 0x4F,
  kVK_F19                       = 0x50,
  kVK_F20                       = 0x5A,
  kVK_F5                        = 0x60,
  kVK_F6                        = 0x61,
  kVK_F7                        = 0x62,
  kVK_F3                        = 0x63,
  kVK_F8                        = 0x64,
  kVK_F9                        = 0x65,
  kVK_F11                       = 0x67,
  kVK_F13                       = 0x69,
  kVK_F16                       = 0x6A,
  kVK_F14                       = 0x6B,
  kVK_F10                       = 0x6D,
  kVK_F12                       = 0x6F,
  kVK_F15                       = 0x71,
  kVK_Help                      = 0x72,
  kVK_Home                      = 0x73,
  kVK_PageUp                    = 0x74,
  kVK_ForwardDelete             = 0x75,
  kVK_F4                        = 0x76,
  kVK_End                       = 0x77,
  kVK_F2                        = 0x78,
  kVK_PageDown                  = 0x79,
  kVK_F1                        = 0x7A,
  kVK_LeftArrow                 = 0x7B,
  kVK_RightArrow                = 0x7C,
  kVK_DownArrow                 = 0x7D,
  kVK_UpArrow                   = 0x7E
};

/* ISO keyboards only*/
enum {
  kVK_ISO_Section               = 0x0A
};

/* JIS keyboards only*/
enum {
  kVK_JIS_Yen                   = 0x5D,
  kVK_JIS_Underscore            = 0x5E,
  kVK_JIS_KeypadComma           = 0x5F,
  kVK_JIS_Eisu                  = 0x66,
  kVK_JIS_Kana                  = 0x68
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
	float		fov;
	float		f;
	float		n;
	float		r;
	float		l;
	float		t;
	float		b;
	int			x;
	int			y;
	int			tx;
	int			ty;
	t_vars		vars;
}	t_allvars;

void	multiply_matrix_vector(t_point *i, t_point *o, t_pmatrix *m);

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
	if (error == 1)
		ft_printf("Wrong arguments.\nusage: ./FdF <map.fdf>");
	else if (error == 2)
		ft_printf("Error opening file");
	else if (error == 3)
		ft_printf("Error file improperly formated");
	else if (error >= 4 || error == 0)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
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
int	keypress(int keysym, t_data *data)
{
	ft_printf("%#010X\n", keysym);
	if (keysym == kVK_Escape)
		quit(data, 0);
	return (0);
}

//Returns a linear value in the range [0,1]
//for sRGB input in [0,255].
float ChannelInvCompanding(int c)
{
	float y;

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
	float  *r = malloc(4 * sizeof(float));

	r[0] = (float) get_t(c);
	r[1] = ChannelInvCompanding(get_r(c));
	r[2] = ChannelInvCompanding(get_g(c));
	r[3] = ChannelInvCompanding(get_b(c));

	return (r);
}

//Apply companding to Red, Green, and Blue
float ChannelCompanding(float c)
{
	float x;

	if (c <= 0.0031308)
		x = 12.92 * c; 
	else
		x = (1.055 * pow(c, (1/2.4))) - 0.055;
	return (x);
}

//return new color. Convert 0..1 back into 0..255
//Srgb Companding for Red, Green, and Blue
int SrgbCompanding(float *c)
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
float sumChannels(float *c)
{
	float x = c[1] + c[2] + c[3];
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
	float  *r = malloc(4 * sizeof(float));

	//r[1] = ((1 - t) * c1[1] + t * c2[1]);
	//r[2] = ((1 - t) * c1[2] + t * c2[2]);
	//r[3] = ((1 - t) * c1[3] + t * c2[3]);
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

void	init_bresenhams(t_bresvars *v, int x1, int y1, int x2, int y2)
{
	v->x = x1; 
	v->y = y1;
	v->dx = abs(x2 - x1); 
	v->dy = abs(y2 - y1);
	v->s1 = sign(x2 - x1); 
	v->s2 = sign(y2 - y1);
	v->swap = 0;
	if (v->dy > v->dx) {
		v->temp = v->dx;
		v->dx = v->dy;
		v->dy = v->temp;
		v->swap = 1;
	}
}

void	bresenhams_cycle(t_bresvars *v, t_calcol *c, t_vars *vars)
{
	v->d = 2*v->dy - v->dx;
	c->step_v = (1.0 / v->dx);
	v->i = 0;
	c->step = 0;
	while (v->i < v->dx)
	{
		c->step += c->step_v;
		c->clr = calculate_color_step(c, c->step);
		my_mlx_pixel_put(&vars->img, v->x, v->y, c->clr); 
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

void	bresenhams_alg(int x1, int y1, int x2, int y2, int scolor, int ecolor, t_vars *vars)
{
	t_bresvars v;
	t_calcol c;

	inverse(&c, scolor, ecolor);
	init_bresenhams(&v, x1, y1, x2, y2);
	bresenhams_cycle(&v, &c, vars);
	free(c.color1_lin);
	free(c.color2_lin);
}

int render(t_allvars *a)
{
	int xp;
	int yp;

	if (a->vars.data.win_ptr != NULL)
		for (int k = 0; k < a->ty; k++)
		{
			for (int l = 0; l < a->tx; l++)
			{
				multiply_matrix_vector(&a->i[k * a->tx + l], &a->bt[k * a->tx + l], &a->wc);
				multiply_matrix_vector(&a->bt[k * a->tx + l], &a->o[k * a->tx + l], &a->pm);
				//if (o[k * tx + l].x < -1 || o[k * tx + l].x > 1 || o[k * tx + l].y < -1 || o[k * tx + l].y > 1) 
				//	continue;
				xp = (int)((a->o[k * a->tx + l].x + 1) * 0.5 * IMG_W); 
				yp = (int)((1 - (a->o[k * a->tx + l].y + 1) * 0.5) * IMG_H);
				a->c[k * a->tx + l].x = xp;
				a->c[k * a->tx + l].y = yp;
				a->c[k * a->tx + l].c = a->o[k * a->tx + l].c;
				my_mlx_pixel_put(&a->vars.img, xp, yp, 0xffffff);
			}
		}
		for (int k = 0; k < a->ty; k++)
		{
			for (int l = 0; l < a->tx; l++)
			{
				if(l < a->tx - 1)
				{
					bresenhams_alg(a->c[k * a->tx + l].x, a->c[k * a->tx + l].y, a->c[k * a->tx + l + 1].x, a->c[k * a->tx + l + 1].y, a->c[k * a->tx + l].c, a->c[k * a->tx + l + 1].c, &a->vars);
				}
				if (k < a->ty -1)
				{
					bresenhams_alg(a->c[k * a->tx + l].x, a->c[k * a->tx + l].y, a->c[(k + 1 )* a->tx + l].x, a->c[(k + 1 )* a->tx + l].y, a->c[k * a->tx + l].c, a->c[(k + 1 )* a->tx + l].c, &a->vars);
				}
			}
		}
		mlx_put_image_to_window(a->vars.data.mlx_ptr, a->vars.data.win_ptr, a->vars.img.img, 0, 0);
		//mlx_put_image_to_window(vars->data.mlx_ptr, vars->data.win_ptr, vars->img.img, 0, 0);
	return(0);
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
void	check_items_inline(t_data *data, char *line, char **arr, int *j)
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
			quit(data, 3);
		}
	}
}


void	set_world_matrix(t_pmatrix *wc)
{
	wc->m[0][0] = 0.1;
	wc->m[1][1] = -0.1;
	wc->m[2][2] = -0.12;
	wc->m[3][3] = 1;
	wc->m[3][0] = -0.5;
	wc->m[3][1] = 0.5;
	wc->m[3][2] = 0;
}

void	set_projection_matrix(t_pmatrix *pm, float n, float f, float fov)
{
	float scale;
	
	scale = 1.0 / tan(fov * 0.5 * M_PI / 180.0);
	pm->m[0][0] = scale;
	pm->m[1][1] = scale;
	pm->m[2][2] = (-f) / (f - n);
	pm->m[3][2] = (-f * n) / (f - n);
	pm->m[2][3] = -1.0;
	pm->m[3][3] = 0.0;
}

void	set_ortog_matrix(t_pmatrix *pm, float b, float t, float l, float r, float n, float f)
{
    pm->m[0][0] = 2 / (r - l); 
    pm->m[0][1] = 0; 
    pm->m[0][2] = 0; 
    pm->m[0][3] = -(r + l) / (r - l); 
 
    pm->m[1][0] = 0; 
    pm->m[1][1] = 2 / (t - b); 
    pm->m[1][2] = 0; 
    pm->m[1][3] =  -(t + b) / (t - b); 
 
    pm->m[2][0] = 0; 
    pm->m[2][1] = 0; 
    pm->m[2][2] = -2 / (f - n); 
    pm->m[2][3] = -(f + n) / (f - n); 
 
    pm->m[3][0] = 0; 
    pm->m[3][1] = 0; 
    pm->m[3][2] = 0; 
    pm->m[3][3] = 1; 
} 

/**
 * @brief 
 * 
 * @param i input
 * @param o output
 * @param m matrix to multiply with
 */
void	multiply_matrix_vector(t_point *i, t_point *o, t_pmatrix *m)
{
	float w;

	o->x = i->x * m->m[0][0] + i->y * m->m[1][0] + i->z * m->m[2][0] + m->m[3][0];
	o->y = i->x * m->m[0][1] + i->y * m->m[1][1] + i->z * m->m[2][1] + m->m[3][1];
	o->z = i->x * m->m[0][2] + i->y * m->m[1][2] + i->z * m->m[2][2] + m->m[3][2];
	w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3] + m->m[3][3];
	if (w != 0.0f)
	{
		o->x /= w; 
		o->y /= w; 
		o->z /= w;
	}
	o->c = i->c;
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

void	set_variables(t_allvars *a, t_point minCamera, t_point maxCamera)
{
	float ar;
	float maxx;
	float maxy;
	float max;


	ar = (float)IMG_W / (float)IMG_H; 
    maxx = dmax(fabs(minCamera.x), fabs(maxCamera.x)); 
    maxy = dmax(fabs(minCamera.y), fabs(maxCamera.y)); 
    max = dmax(maxx, maxy); 
    a->r = max * ar;
	a->t = max; 
    a->l = -a->r;
	a->b = -a->t; 
}

// compute the scene bounding box
void	set_bounding_box(t_allvars *a)
{
	int i;
	t_point minWorld;
	t_point maxWorld;
	t_point minCamera;
	t_point maxCamera;

	minWorld = (t_point){__FLT_MAX__, __FLT_MAX__, __FLT_MAX__, 0};
	maxWorld = (t_point){-__FLT_MAX__, -__FLT_MAX__, -__FLT_MAX__, 0};
	i = 0;
    while (i < (a->tx * a->ty)) 
	{ 
        if (a->i[i].x < minWorld.x) minWorld.x = a->i[i].x; 
        if (a->i[i].y < minWorld.y) minWorld.y = a->i[i].y; 
        if (a->i[i].z < minWorld.z) minWorld.z = a->i[i].z; 
        if (a->i[i].x > maxWorld.x) maxWorld.x = a->i[i].x; 
        if (a->i[i].y > maxWorld.y) maxWorld.y = a->i[i].y; 
        if (a->i[i].z > maxWorld.z) maxWorld.z = a->i[i].z;
		i++;
    } 
    multiply_matrix_vector(&minWorld, &minCamera, &a->wc); 
    multiply_matrix_vector(&maxWorld, &maxCamera, &a->wc); 
	set_variables(a, minCamera, maxCamera);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_img	img;
	t_vars	vars;
	t_allvars a;
	int		fd;
	char	*line;
	char	**arr;
	char	*pos;
	int		x;
	int		y;
	int		tx;
	int		ty;

	t_pmatrix pm = {0};
	t_pmatrix wc = {0};
	

	//open file
	if (argc != 2)
		quit(&data, 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		quit(&data, 2);

	//check file and get sizes
	line = get_next_line(fd);
	x = 0;
	y = 0;
	while (line != NULL)
	{
		ft_printf("%s", line);
		pos = ft_strchr(line, '\n');
		*pos = '\0';
		arr = ft_split(line, ' ');
		check_items_inline(&data, line, arr, &x);
		delete_arr_arr(arr);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		y++;
	}
	close(fd);

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		quit(&data, 2);

	tx = x;
	ty = y;
	y = 0;
	//input vector array
	a.i = malloc(sizeof(t_point) * (x * y));
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("%s", line);
		pos = ft_strchr(line, '\n');
		*pos = '\0';
		arr = ft_split(line, ' ');
		x = 0;
		while (x < tx)
		{
			a.i[y * tx + x].x = (float)x;
			a.i[y * tx + x].y = (float)y;
			a.i[y * tx + x].z = (float)(ft_atoi(arr[x]));
			if (a.i[y * tx + x].z > 9)
				a.i[y * tx + x].c = 0xd97bd4;
			else
				a.i[y * tx + x].c = 0xffffff;
			x++;
		}
		delete_arr_arr(arr);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		y++;
	}
	close(fd);

	float fov = 90; 
    float n = 0.1; 
    float f = 100;

	a.bt = malloc(sizeof(t_point) * (a.tx * a.ty));
	a.o = malloc(sizeof(t_point) * (a.tx * a.ty));
	a.c = malloc(sizeof(t_coord) * (a.tx * a.ty));
	if(!a.bt && !a.o && !a.c)
		quit(&data, 5);

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
	a.pm = pm;
	a.wc = wc;
	a.vars = vars;
	a.fov = fov;
	a.f = f;
	a.n = n;
	a.x = x;
	a.y = y;
	a.tx = tx;
	a.ty = ty;
	set_bounding_box(&a);
	set_world_matrix(&a.wc);
	set_projection_matrix(&a.pm, n, f, fov);

	mlx_loop_hook(data.mlx_ptr, render, &a);
	//mlx_key_hook(data.win_ptr, keypress, &data);
	//close program on close window
	mlx_hook(data.win_ptr, 17, 0, quit, &data);

	mlx_loop(data.mlx_ptr);
	//close window and free server

}
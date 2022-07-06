/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:19:22 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 16:47:36 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# include <stdio.h>
# include <math.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define FDF_H

# define KEYPRESS 2
# define KEYRELEASE 3

# define MB1				1
# define MB2				3
# define MB3				2
# define MB2_UP				4
# define MB2_DOWN			5
# define MB2_LEFT			6
# define MB2_RIGHT			7

# define MLX_ERROR 1
# define WIN_ERROR 2
# define PURPLE 0x00FFFFFF
# define IMG_W 1280
# define IMG_H 720
# define MENU_W 250
# define LTR_C 0x111111
# define GAMMA 0.43
# define BUFFER_SIZE 42
# define NUM_OF_FD 256

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

//bounding_box.c
void	set_bb_variables(t_allvars *a, t_point min_camera, t_point max_camera);
void	set_bounding_box_while(t_allvars *a, t_point *min_world,
			t_point *max_world);
void	set_bounding_box(t_allvars *a);
//bresenham.c
void	init_bresenhams(t_bresvars *v, t_coord *start, t_coord *end);
void	bresenhams_cycle(t_bresvars *v, t_calcol *c, t_allvars *a);
void	bresenhams_alg(t_coord *start, t_coord *end, t_allvars *a);
//color.c
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
//color_calculate.c
int		calculate_color_step(t_calcol *c, float step);
void	inverse(t_calcol *c, int scolor, int ecolor);
//color_companding.c
float	channel_inv_companding(int c);
float	*inverse_srgb_companding(int c);
float	channel_companding(float c);
int		srgb_companding(float *c);
//color_lerping.c
float	sum_channels(float *c);
float	lerp_int(float c1, float c2, float t);
float	*lerp(float *c1, float *c2, float t);
void	fix(float *c, float intensity, float total);
//get_items.c
void	check_items_inline(t_allvars *a, char *line, char **arr, int *j);
void	count_file_items(t_allvars *a, char **argv);
//get_z_value.c
void	get_coordinates_color(char **arr, t_allvars *a);
void	get_coordinates(char **arr, t_allvars *a);
void	get_z_val_while(char **arr, t_allvars *a);
void	get_z_val_alocate(t_allvars *a);
void	get_z_values(t_allvars *a, char **argv);
//initialize.c
void	initialize_a(t_allvars *a);
void	allocate_matrices(t_allvars *a);
void	initialize_window(t_allvars *a);
//keypress.c
int		keypress(int key, t_allvars *a);
int		keypress1(int key, t_allvars *a);
int		keypress2(int key, t_allvars *a);
int		keypress3(int key, t_allvars *a);
//matrix_set.c
void	set_iso_op_matrix(t_pmatrix *wc, t_allvars *al);
void	set_paralel_matrix(t_pmatrix *wc, t_allvars *al);
void	world_matrix(t_pmatrix *wc, t_allvars *al);
void	set_projection_matrix(t_pmatrix *pm, t_allvars *a);
void	set_ortog_matrix(t_pmatrix *pm, t_allvars *a);
//matrix_calculate.c
void	multiply_matrix_vector(t_point *i, t_point *o, t_pmatrix *m);
void	transform_matrix_vector(t_point *i, t_pmatrix *m);
//matrix_make.c
void	set_matrices(t_allvars *a);
void	make_matrix_mode_c(int k, int l, t_allvars *a);
void	make_matrix_mode_iop(int k, int l, t_allvars *a);
void	make_matrix_assignment(int k, int l, t_allvars *a);
void	make_matrix(t_allvars *a);
//quit.c
int		quit(t_allvars *a, int error);
void	quit1(t_allvars *a, int error);
void	quit2(t_allvars *a, int error);
//render.c
void	clear_image(t_allvars *a);
void	menu_text(t_allvars *a);
void	put_menu(t_allvars *a);
void	put_lines(t_allvars *a);
int		render(t_allvars *a);
//utils.c
int		sign(int x);
float	dmin(float x, float y);
float	dmax(float x, float y);
float	clamp(float value, float min, float max);
float	inv_value(float value);
//utils2.c
int		my_sign(float value);
int		hex2int(char *hex);
void	delete_arr_arr(char **arr);
void	get_z_offset(t_allvars *a);
void	get_xyz_offset(t_allvars *a);
//utils3.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	bend_it(t_point *inpt, t_point *outpt, t_allvars *a);

#endif
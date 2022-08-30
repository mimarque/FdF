/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:19:22 by mimarque          #+#    #+#             */
/*   Updated: 2022/08/19 23:29:12 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

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

# ifndef MAC_K
#  define MAC_K
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
# endif

# ifndef LX_K
#  define LX_K

#  define XK_BACKSPACE                     0xff08  /* Back space, back char */
#  define XK_TAB                           0xff09
#  define XK_LINEFEED                      0xff0a  /* Linefeed, LF */
#  define XK_CLEAR                         0xff0b
#  define XK_RETURN                        0xff0d  /* Return, enter */
#  define XK_PAUSE                         0xff13  /* Pause, hold */
#  define XK_SCROLL_LOCK                   0xff14
#  define XK_SYS_REQ                       0xff15
#  define XK_ESCAPE                        0xff1b
#  define XK_DELETE                        0xffff  /* Delete, rubout */

#  define XK_HOME                          0xff50
#  define XK_LEFT                          0xff51  /* Move left, left arrow */
#  define XK_UP                            0xff52  /* Move up, up arrow */
#  define XK_RIGHT                         0xff53  /* Move right, right arrow */
#  define XK_DOWN                          0xff54  /* Move down, down arrow */
#  define XK_PRIOR                         0xff55  /* Prior, previous */
#  define XK_PAGE_UP                       0xff55
#  define XK_NEXT                          0xff56  /* Next */
#  define XK_PAGE_DOWN                     0xff56
#  define XK_END                           0xff57  /* EOL */
#  define XK_BEGIN                         0xff58  /* BOL */

#  define XK_KP_SPACE                      0xff80  /* Space */
#  define XK_KP_TAB                        0xff89
#  define XK_KP_ENTER                      0xff8d  /* Enter */
#  define XK_KP_F1                         0xff91  /* PF1, KP_A, ... */
#  define XK_KP_F2                         0xff92
#  define XK_KP_F3                         0xff93
#  define XK_KP_F4                         0xff94
#  define XK_KP_HOME                       0xff95
#  define XK_KP_LEFT                       0xff96
#  define XK_KP_UP                         0xff97
#  define XK_KP_RIGHT                      0xff98
#  define XK_KP_DOWN                       0xff99
#  define XK_KP_PRIOR                      0xff9a
#  define XK_KP_PAGE_UP                    0xff9a
#  define XK_KP_NEXT                       0xff9b
#  define XK_KP_PAGE_DOWN                  0xff9b
#  define XK_KP_END                        0xff9c
#  define XK_KP_BEGIN                      0xff9d
#  define XK_KP_INSERT                     0xff9e
#  define XK_KP_DELETE                     0xff9f

#  define XK_KP_0                          0xffb0
#  define XK_KP_1                          0xffb1
#  define XK_KP_2                          0xffb2
#  define XK_KP_3                          0xffb3
#  define XK_KP_4                          0xffb4
#  define XK_KP_5                          0xffb5
#  define XK_KP_6                          0xffb6
#  define XK_KP_7                          0xffb7
#  define XK_KP_8                          0xffb8
#  define XK_KP_9                          0xffb9

#  define XK_F1                            0xffbe
#  define XK_F2                            0xffbf
#  define XK_F3                            0xffc0
#  define XK_F4                            0xffc1
#  define XK_F5                            0xffc2
#  define XK_F6                            0xffc3
#  define XK_F7                            0xffc4
#  define XK_F8                            0xffc5
#  define XK_F9                            0xffc6
#  define XK_F10                           0xffc7
#  define XK_F11                           0xffc8
#  define XK_L1                            0xffc8
#  define XK_F12                           0xffc9
#  define XK_L2                            0xffc9
#  define XK_F13                           0xffca
#  define XK_L3                            0xffca
#  define XK_F14                           0xffcb
#  define XK_L4                            0xffcb
#  define XK_F15                           0xffcc
#  define XK_L5                            0xffcc
#  define XK_F16                           0xffcd
#  define XK_L6                            0xffcd
#  define XK_F17                           0xffce
#  define XK_L7                            0xffce
#  define XK_F18                           0xffcf
#  define XK_L8                            0xffcf
#  define XK_F19                           0xffd0
#  define XK_L9                            0xffd0
#  define XK_F20                           0xffd1
#  define XK_L10                           0xffd1
#  define XK_F21                           0xffd2
#  define XK_R1                            0xffd2
#  define XK_F22                           0xffd3
#  define XK_R2                            0xffd3
#  define XK_F23                           0xffd4
#  define XK_R3                            0xffd4
#  define XK_F24                           0xffd5
#  define XK_R4                            0xffd5
#  define XK_F25                           0xffd6
#  define XK_R5                            0xffd6
#  define XK_F26                           0xffd7
#  define XK_R6                            0xffd7
#  define XK_F27                           0xffd8
#  define XK_R7                            0xffd8
#  define XK_F28                           0xffd9
#  define XK_R8                            0xffd9
#  define XK_F29                           0xffda
#  define XK_R9                            0xffda
#  define XK_F30                           0xffdb
#  define XK_R10                           0xffdb
#  define XK_F31                           0xffdc
#  define XK_R11                           0xffdc
#  define XK_F32                           0xffdd
#  define XK_R12                           0xffdd
#  define XK_F33                           0xffde
#  define XK_R13                           0xffde
#  define XK_F34                           0xffdf
#  define XK_R14                           0xffdf
#  define XK_F35                           0xffe0
#  define XK_R15                           0xffe0

#  define XK_SPACE                         0x0020  /* U+0020 SPACE */
#  define XK_EXCLAM                        0x0021  /* U+0021 EXCLAMATION MARK */
#  define XK_QUOTEDBL                      0x0022  /* U+0022 QUOTATION MARK */
#  define XK_NUMBERSIGN                    0x0023  /* U+0023 NUMBER SIGN */
#  define XK_DOLLAR                        0x0024  /* U+0024 DOLLAR SIGN */
#  define XK_PERCENT                       0x0025  /* U+0025 PERCENT SIGN */
#  define XK_AMPERSAND                     0x0026  /* U+0026 AMPERSAND */
#  define XK_APOSTROPHE                    0x0027  /* U+0027 APOSTROPHE */
#  define XK_QUOTERIGHT                    0x0027  /* deprecated */
#  define XK_PARENLEFT                     0x0028  /* U+0028 LEFT PARENTHESIS */
#  define XK_PARENRIGHT                    0x0029  /* U+0029 R PARENTHESIS */
#  define XK_ASTERISK                      0x002a  /* U+002A ASTERISK */
#  define XK_PLUS                          0x002b  /* U+002B PLUS SIGN */
#  define XK_COMMA                         0x002c  /* U+002C COMMA */
#  define XK_MINUS                         0x002d  /* U+002D HYPHEN-MINUS */
#  define XK_PERIOD                        0x002e  /* U+002E FULL STOP */
#  define XK_SLASH                         0x002f  /* U+002F SOLIDUS */
#  define XK_0                             0x0030  /* U+0030 DIGIT ZERO */
#  define XK_1                             0x0031  /* U+0031 DIGIT ONE */
#  define XK_2                             0x0032  /* U+0032 DIGIT TWO */
#  define XK_3                             0x0033  /* U+0033 DIGIT THREE */
#  define XK_4                             0x0034  /* U+0034 DIGIT FOUR */
#  define XK_5                             0x0035  /* U+0035 DIGIT FIVE */
#  define XK_6                             0x0036  /* U+0036 DIGIT SIX */
#  define XK_7                             0x0037  /* U+0037 DIGIT SEVEN */
#  define XK_8                             0x0038  /* U+0038 DIGIT EIGHT */
#  define XK_9                             0x0039  /* U+0039 DIGIT NINE */
#  define XK_COLON                         0x003a  /* U+003A COLON */
#  define XK_SEMICOLON                     0x003b  /* U+003B SEMICOLON */
#  define XK_LESS                          0x003c  /* U+003C LESS-THAN SIGN */
#  define XK_EQUAL                         0x003d  /* U+003D EQUALS SIGN */
#  define XK_GREATER                       0x003e  /* U+003E GREATER-THAN */
#  define XK_QUESTION                      0x003f  /* U+003F QUESTION MARK */
#  define XK_AT                            0x0040  /* U+0040 COMMERCIAL AT */
#  define XK_A                             0x0041  /* U+0041 CAPITAL LETTER A */
#  define XK_B                             0x0042  /* U+0042 CAPITAL LETTER B */
#  define XK_C                             0x0043  /* U+0043 CAPITAL LETTER C */
#  define XK_D                             0x0044  /* U+0044 CAPITAL LETTER D */
#  define XK_E                             0x0045  /* U+0045 CAPITAL LETTER E */
#  define XK_F                             0x0046  /* U+0046 CAPITAL LETTER F */
#  define XK_G                             0x0047  /* U+0047 CAPITAL LETTER G */
#  define XK_H                             0x0048  /* U+0048 CAPITAL LETTER H */
#  define XK_I                             0x0049  /* U+0049 CAPITAL LETTER I */
#  define XK_J                             0x004a  /* U+004A CAPITAL LETTER J */
#  define XK_K                             0x004b  /* U+004B CAPITAL LETTER K */
#  define XK_L                             0x004c  /* U+004C CAPITAL LETTER L */
#  define XK_M                             0x004d  /* U+004D CAPITAL LETTER M */
#  define XK_N                             0x004e  /* U+004E CAPITAL LETTER N */
#  define XK_O                             0x004f  /* U+004F CAPITAL LETTER O */
#  define XK_P                             0x0050  /* U+0050 CAPITAL LETTER P */
#  define XK_Q                             0x0051  /* U+0051 CAPITAL LETTER Q */
#  define XK_R                             0x0052  /* U+0052 CAPITAL LETTER R */
#  define XK_S                             0x0053  /* U+0053 CAPITAL LETTER S */
#  define XK_T                             0x0054  /* U+0054 CAPITAL LETTER T */
#  define XK_U                             0x0055  /* U+0055 CAPITAL LETTER U */
#  define XK_V                             0x0056  /* U+0056 CAPITAL LETTER V */
#  define XK_W                             0x0057  /* U+0057 CAPITAL LETTER W */
#  define XK_X                             0x0058  /* U+0058 CAPITAL LETTER X */
#  define XK_Y                             0x0059  /* U+0059 CAPITAL LETTER Y */
#  define XK_Z                             0x005a  /* U+005A CAPITAL LETTER Z */
#  define XK_BRACKETLEFT                   0x005b  /* U+005B L SQUARE BRACKET */
#  define XK_BACKSLASH                     0x005c  /* U+005C REVERSE SOLIDUS */
#  define XK_BRACKETRIGHT                  0x005d  /* U+005D R SQUARE BRACKET */
#  define XK_ASCIICIRCUM                   0x005e  /* U+005E CIRCUMFLEX */
#  define XK_UNDERSCORE                    0x005f  /* U+005F LOW LINE */
#  define XK_GRAVE                         0x0060  /* U+0060 GRAVE ACCENT */
#  define XK_QUOTELEFT                     0x0060  /* deprecated */
#  define XK_S_A                           0x0061  /* U+0061 SMALL LETTER A */
#  define XK_S_B                           0x0062  /* U+0062 SMALL LETTER B */
#  define XK_S_C                           0x0063  /* U+0063 SMALL LETTER C */
#  define XK_S_D                           0x0064  /* U+0064 SMALL LETTER D */
#  define XK_S_E                           0x0065  /* U+0065 SMALL LETTER E */
#  define XK_S_F                           0x0066  /* U+0066 SMALL LETTER F */
#  define XK_S_G                           0x0067  /* U+0067 SMALL LETTER G */
#  define XK_S_H                           0x0068  /* U+0068 SMALL LETTER H */
#  define XK_S_I                           0x0069  /* U+0069 SMALL LETTER I */
#  define XK_S_J                           0x006a  /* U+006A SMALL LETTER J */
#  define XK_S_K                           0x006b  /* U+006B SMALL LETTER K */
#  define XK_S_L                           0x006c  /* U+006C SMALL LETTER L */
#  define XK_S_M                           0x006d  /* U+006D SMALL LETTER M */
#  define XK_S_N                           0x006e  /* U+006E SMALL LETTER N */
#  define XK_S_O                           0x006f  /* U+006F SMALL LETTER O */
#  define XK_S_P                           0x0070  /* U+0070 SMALL LETTER P */
#  define XK_S_Q                           0x0071  /* U+0071 SMALL LETTER Q */
#  define XK_S_R                           0x0072  /* U+0072 SMALL LETTER R */
#  define XK_S_S                           0x0073  /* U+0073 SMALL LETTER S */
#  define XK_S_T                           0x0074  /* U+0074 SMALL LETTER T */
#  define XK_S_U                           0x0075  /* U+0075 SMALL LETTER U */
#  define XK_S_V                           0x0076  /* U+0076 SMALL LETTER V */
#  define XK_S_W                           0x0077  /* U+0077 SMALL LETTER W */
#  define XK_S_X                           0x0078  /* U+0078 SMALL LETTER X */
#  define XK_S_Y                           0x0079  /* U+0079 SMALL LETTER Y */
#  define XK_S_Z                           0x007a  /* U+007A SMALL LETTER Z */
#  define XK_BRACELEFT                     0x007b  /* U+007B L CURLY BRACKET */
#  define XK_BAR                           0x007c  /* U+007C VERTICAL LINE */
#  define XK_BRACERIGHT                    0x007d  /* U+007D R CURLY BRACKET */
#  define XK_ASCIITILDE                    0x007e  /* U+007E TILDE */

# endif

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

//C is not OOP or C++... 
//so, many things I want to do in this program
//are limited by norminette and my lack of time
//thus this mosnstrosity is born
//always passed by reference and not by copy
typedef struct s_allvars
{
	t_point		*i;
	t_point		*bt;
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
bool	check(int k, int l, t_allvars *al);
bool	is_visible(t_coord *c);
void	bend_it(t_point *inpt, t_point *outpt, t_allvars *a);
char	*get_filext(char *filename);

#endif
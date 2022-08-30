/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:46:27 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/11 16:50:10 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		pixel = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
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

//invalid read
bool	check(int k, int l, t_allvars *al)
{	
	bool	a;
	bool	b;
	bool	c;
	bool	d;
	bool	e;

	e = is_visible(&al->c[k * al->tx + l]);
	k = (int)clamp(k, 2, al->ty - 2);
	l = (int)clamp(l, 2, al->tx - 2);
	a = is_visible(&al->c[k * al->tx + l - 2]);
	b = is_visible(&al->c[(k - 2) * al->tx + l]);
	c = is_visible(&al->c[k * al->tx + l + 2]);
	d = is_visible(&al->c[(k + 2) * al->tx + l]);
	if (((a || b) || (c || d)) || e)
		return (1);
	return (0);
}

bool	is_visible(t_coord *c)
{
	if ((c->x > IMG_W || c->x < 0)
		|| (c->y > IMG_H || c->y < 0))
		return (0);
	return (1);
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
	outpt->c = inpt->c;
}

char	*get_filext(char *filename)
{
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename)
		return (NULL);
    return (dot + 1);
}

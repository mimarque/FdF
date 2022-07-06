/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:46:27 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 16:47:40 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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

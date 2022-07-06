/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_companding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:46:24 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 04:46:50 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//Returns a linear value in the range [0,1]
//for sRGB input in [0,255].
float	channel_inv_companding(int c)
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
float	*inverse_srgb_companding(int c)
{
	float	*r;

	r = malloc(4 * sizeof(float));
	r[0] = (float) get_t(c);
	r[1] = channel_inv_companding(get_r(c));
	r[2] = channel_inv_companding(get_g(c));
	r[3] = channel_inv_companding(get_b(c));
	return (r);
}

//Apply companding to Red, Green, and Blue
float	channel_companding(float c)
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
int	srgb_companding(float *c)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)c[0];
	r = (int)(channel_companding(c[1]) * 255);
	g = (int)(channel_companding(c[2]) * 255);
	b = (int)(channel_companding(c[3]) * 255);
	free(c);
	return (create_trgb(t, r, g, b));
}

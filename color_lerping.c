/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_lerping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:51:50 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 04:53:24 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//sums channels
//does not include transperancy
float	sum_channels(float *c)
{
	float	x;

	x = c[1] + c[2] + c[3];
	return (x);
}

//Lerping see
//https://en.wikipedia.org/wiki/Linear_interpolation
//#Programming_language_support
float	lerp_int(float c1, float c2, float t)
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

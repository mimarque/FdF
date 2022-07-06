/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:11:19 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 16:13:01 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

float	dmin(float x, float y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

float	dmax(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
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

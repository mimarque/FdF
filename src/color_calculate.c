/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:57:06 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/07 22:13:31 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_color_step(t_calcol *c, float step)
{
	c->intensity = pow(lerp_int(c->bright1, c->bright2, step), (1 / GAMMA));
	c->color = lerp(c->color1_lin, c->color2_lin, step);
	c->total = sum_channels(c->color);
	if (c->total != 0)
		fix(c->color, c->intensity, c->total);
	return (srgb_companding(c->color));
}

void	inverse(t_calcol *c, int scolor, int ecolor)
{
	c->color1_lin = inverse_srgb_companding(scolor);
	c->bright1 = pow(sum_channels(c->color1_lin), GAMMA);
	c->color2_lin = inverse_srgb_companding(ecolor);
	c->bright2 = pow(sum_channels(c->color2_lin), GAMMA);
}

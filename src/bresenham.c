/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 05:03:24 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/07 22:13:10 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

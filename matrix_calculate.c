/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calculate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:01:49 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 16:03:00 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/**
 * @brief multiplies matrix i with m and outputs it to o
 * 
 * @param i input
 * @param o output
 * @param m matrix to multiply with
 */
void	multiply_matrix_vector(t_point *i, t_point *o, t_pmatrix *m)
{
	float	w;

	o->x = i->x * m->m[0][0] + i->y * m->m[1][0]
		+ i->z * m->m[2][0] + m->m[3][0];
	o->y = i->x * m->m[0][1] + i->y * m->m[1][1] 
		+ i->z * m->m[2][1] + m->m[3][1];
	o->z = i->x * m->m[0][2] + i->y * m->m[1][2]
		+ i->z * m->m[2][2] + m->m[3][2];
	w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3] + m->m[3][3];
	if (w != 0.0f)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
	o->c = i->c;
}

/**
 * @brief multiplies matrix i with m and outputs it to i
 * 
 * @param i input
 * @param m matrix to multiply with
 */
void	transform_matrix_vector(t_point *i, t_pmatrix *m)
{
	float	w;
	t_point	o;

	o.x = i->x * m->m[0][0] + i->y * m->m[1][0]
		+ i->z * m->m[2][0] + m->m[3][0];
	o.y = i->x * m->m[0][1] + i->y * m->m[1][1]
		+ i->z * m->m[2][1] + m->m[3][1];
	o.z = i->x * m->m[0][2] + i->y * m->m[1][2]
		+ i->z * m->m[2][2] + m->m[3][2];
	w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3] + m->m[3][3];
	if (w != 0.0f)
	{
		o.x /= w;
		o.y /= w;
		o.z /= w;
	}
	o.c = i->c;
	*i = o;
}

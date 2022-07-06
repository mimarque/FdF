/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:06:00 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 16:09:17 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_bb_variables(t_allvars *a, t_point min_camera, t_point max_camera)
{
	float	ar;
	float	maxx;
	float	maxy;
	float	max;

	ar = (float)IMG_W / (float)IMG_H;
	maxx = dmax(fabs(min_camera.x), fabs(max_camera.x));
	maxy = dmax(fabs(min_camera.y), fabs(max_camera.y));
	max = dmax(maxx, maxy);
	a->r = (max * ar);
	a->t = max;
	a->l = -(a->r);
	a->b = -(a->t);
}

void	set_bounding_box_while(t_allvars *a, t_point *min_world,
									t_point *max_world)
{
	int	i;

	i = 0;
	while (i < (a->tx * a->ty))
	{
		if (a->i[i].x < min_world->x)
			min_world->x = a->i[i].x;
		if (a->i[i].y < min_world->y)
			min_world->y = a->i[i].y;
		if (a->i[i].z < min_world->z)
			min_world->z = a->i[i].z;
		if (a->i[i].x > max_world->x)
			max_world->x = a->i[i].x;
		if (a->i[i].y > max_world->y)
			max_world->y = a->i[i].y;
		if (a->i[i].z > max_world->z)
			max_world->z = a->i[i].z;
		i++;
	}
}

// compute the scene bounding box
void	set_bounding_box(t_allvars *a)
{
	t_point	min_world;
	t_point	max_world;
	t_point	min_camera;
	t_point	max_camera;

	min_world = (t_point){__FLT_MAX__, __FLT_MAX__, __FLT_MAX__, 0};
	max_world = (t_point){-__FLT_MAX__, -__FLT_MAX__, -__FLT_MAX__, 0};
	set_bounding_box_while(a, &min_world, &max_world);
	multiply_matrix_vector(&min_world, &min_camera, &a->wc);
	multiply_matrix_vector(&max_world, &max_camera, &a->wc);
	set_bb_variables(a, min_camera, max_camera);
}

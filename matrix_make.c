/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:17:28 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 16:20:12 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_matrices(t_allvars *a)
{
	if (a->mode == 'i')
		set_iso_op_matrix(&a->wc, a);
	else if (a->mode == 'o')
		set_paralel_matrix(&a->wc, a);
	else
		world_matrix(&a->wc, a);
	if (a->mode == 'i' || a->mode == 'o')
	{
		set_bounding_box(a);
		set_ortog_matrix(&a->pm, a);
	}
	else if (a->mode == 'p')
		set_projection_matrix(&a->pm, a);
}

void	make_matrix_mode_c(int k, int l, t_allvars *a)
{
	bend_it(&a->i[k * a->tx + l], &a->bt[k * a->tx + l], a);
	transform_matrix_vector(&a->bt[k * a->tx + l], &a->wc);
	multiply_matrix_vector(&a->bt[k * a->tx + l], &a->o[k * a->tx + l], &a->pm);
}

void	make_matrix_mode_iop(int k, int l, t_allvars *a)
{
	multiply_matrix_vector(&a->i[k * a->tx + l], &a->bt[k * a->tx + l], &a->wc);
	multiply_matrix_vector(&a->bt[k * a->tx + l], &a->o[k * a->tx + l], &a->pm);
}

void	make_matrix_assignment(int k, int l, t_allvars *a)
{
	int	xp;
	int	yp;

	if (a->mode != 'i' || a->mode != 'o')
	{
		xp = (int)((a->o[k * a->tx + l].x + 1) * 0.5 * IMG_W);
		yp = (int)((1 - (a->o[k * a->tx + l].y + 1) * 0.5) * IMG_H);
	}
	else
	{
		xp = (int)(a->o[k * a->tx + l].x);
		yp = (int)(a->o[k * a->tx + l].y);
	}
	a->c[k * a->tx + l].x = xp;
	a->c[k * a->tx + l].y = yp;
	a->c[k * a->tx + l].c = a->o[k * a->tx + l].c;
}

void	make_matrix(t_allvars *a)
{
	int	k;
	int	l;

	set_matrices(a);
	k = 0;
	while (k < a->ty)
	{	
		l = 0;
		while (l < a->tx)
		{
			if (a->mode == 'c')
				make_matrix_mode_c(k, l, a);
			else
				make_matrix_mode_iop(k, l, a);
			make_matrix_assignment(k, l, a);
			l++;
		}
		k++;
	}
}

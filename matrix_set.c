/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:41:09 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 15:42:45 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
void	set_identity(t_allvars *a)
{
	a->tw.m[0][0] = 1;
	a->tw.m[0][1] = 0;
	a->tw.m[0][2] = 0;
	a->tw.m[0][3] = 0;
	a->tw.m[1][0] = 0;
	a->tw.m[1][1] = 1;
	a->tw.m[1][2] = 0;
	a->tw.m[1][3] = 0;
	a->tw.m[2][0] = 0;
	a->tw.m[2][1] = 0;
	a->tw.m[2][2] = 1;
	a->tw.m[2][3] = 0;
	a->tw.m[3][0] = 0;
	a->tw.m[3][1] = 0;
	a->tw.m[3][2] = 0;
	a->tw.m[3][3] = 1;
}
*/
void	set_iso_op_matrix(t_pmatrix *wc, t_allvars *al)
{
	float	a;
	float	b;
	float	g;

	a = (45.0 + al->rz) * (M_PI / 180.0);
	b = (0.0 + al->ry) * (M_PI / 180.0);
	g = (35.264 + al->rx) * (M_PI / 180.0);
	wc->m[0][0] = cos(a) * cos(b);
	wc->m[0][1] = cos(a) * sin(b) * sin(g) - sin(a) * cos(g);
	wc->m[0][2] = cos(a) * sin(b) * cos(g) + sin(a) * sin(g);
	wc->m[0][3] = 0;
	wc->m[1][0] = sin(a) * (-cos(b));
	wc->m[1][1] = -sin(a) * sin(b) * sin(g) - cos(a) * cos(g);
	wc->m[1][2] = cos(a) * sin(g) - sin(a) * sin(b) * cos(g);
	wc->m[1][3] = 0;
	wc->m[2][0] = -al->scale * sin(b);
	wc->m[2][1] = al->scale * cos(b) * sin(g);
	wc->m[2][2] = al->scale * cos(b) * cos(g);
	wc->m[2][3] = 0;
	wc->m[3][0] = al->tlx;
	wc->m[3][1] = al->tly;
	wc->m[3][2] = al->tlz;
	wc->m[3][3] = 1;
}

void	set_paralel_matrix(t_pmatrix *wc, t_allvars *al)
{
	float	a;
	float	b;
	float	g;

	a = (0 + al->rz) * (M_PI / 180.0);
	b = (0 + al->ry) * (M_PI / 180.0);
	g = (0 + al->rx) * (M_PI / 180.0);
	wc->m[0][0] = cos(a) * cos(b);
	wc->m[0][1] = cos(a) * sin(b) * sin(g) - sin(a) * cos(g);
	wc->m[0][2] = cos(a) * sin(b) * cos(g) + sin(a) * sin(g);
	wc->m[0][3] = 0;
	wc->m[1][0] = sin(a) * (-cos(b));
	wc->m[1][1] = -sin(a) * sin(b) * sin(g) - cos(a) * cos(g);
	wc->m[1][2] = cos(a) * sin(g) - sin(a) * sin(b) * cos(g);
	wc->m[1][3] = 0;
	wc->m[2][0] = -al->scale * sin(b);
	wc->m[2][1] = al->scale * cos(b) * sin(g);
	wc->m[2][2] = al->scale * cos(b) * cos(g);
	wc->m[2][3] = 0;
	wc->m[3][0] = al->tlx;
	wc->m[3][1] = al->tly;
	wc->m[3][2] = al->tlz;
	wc->m[3][3] = 1;
}

void	world_matrix(t_pmatrix *wc, t_allvars *al)
{	
	float	a;
	float	b;
	float	g;

	a = (0 + al->rz) * (M_PI / 180.0);
	b = (0 + al->ry) * (M_PI / 180.0);
	g = (0 + al->rx) * (M_PI / 180.0);
	wc->m[0][0] = cos(a) * cos(b);
	wc->m[0][1] = cos(a) * sin(b) * sin(g) - sin(a) * cos(g);
	wc->m[0][2] = cos(a) * sin(b) * cos(g) + sin(a) * sin(g);
	wc->m[0][3] = 0;
	wc->m[1][0] = sin(a) * (-cos(b));
	wc->m[1][1] = -sin(a) * sin(b) * sin(g) - cos(a) * cos(g);
	wc->m[1][2] = cos(a) * sin(g) - sin(a) * sin(b) * cos(g);
	wc->m[1][3] = 0;
	wc->m[2][0] = -al->scale * sin(b);
	wc->m[2][1] = al->scale * cos(b) * sin(g);
	wc->m[2][2] = al->scale * cos(b) * cos(g);
	wc->m[2][3] = 0;
	wc->m[3][0] = al->tlx;
	wc->m[3][1] = al->tly;
	wc->m[3][2] = al->tlz;
	wc->m[3][3] = 1;
}

void	set_projection_matrix(t_pmatrix *pm, t_allvars *a)
{
	float	scale;

	scale = 1.0 / tan(a->fov * 0.5 * M_PI / 180.0);
	pm->m[0][0] = scale;
	pm->m[1][1] = scale;
	pm->m[2][2] = (-a->f) / (a->f - a->n);
	pm->m[3][2] = (-a->f * a->n) / (a->f - a->n);
	pm->m[2][3] = -1.0;
	pm->m[3][3] = 0.0;
}

void	set_ortog_matrix(t_pmatrix *pm, t_allvars *a)
{
	pm->m[0][0] = (2.0 / (a->r - a->l)) * a->zoom;
	pm->m[0][1] = 0;
	pm->m[0][2] = 0;
	pm->m[0][3] = 0;
	pm->m[1][0] = 0;
	pm->m[1][1] = (2.0 / (a->t - a->b)) * a->zoom;
	pm->m[1][2] = 0;
	pm->m[1][3] = 0;
	pm->m[2][0] = 0;
	pm->m[2][1] = 0;
	pm->m[2][2] = -(2.0 / (a->f - a->n)) * a->zoom;
	pm->m[2][3] = 0;
	pm->m[3][0] = -(a->r + a->l) / (a->r - a->l);
	pm->m[3][1] = -(a->t + a->b) / (a->t - a->b);
	pm->m[3][2] = -(a->f + a->n) / (a->f - a->n);
	pm->m[3][3] = 1;
}

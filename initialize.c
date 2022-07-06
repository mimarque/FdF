/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:27:27 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 16:27:35 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	initialize_a(t_allvars *a)
{
	a->pm = (t_pmatrix){0};
	a->wc = (t_pmatrix){0};
	a->tw = (t_pmatrix){0};
	a->fov = 90;
	a->n = 0.05;
	a->f = 100;
	a->brange = 0.015;
	get_z_offset(a);
	a->scale = 1;
	a->zoom = 1;
	a->mode = 'i';
	a->menu = 1;
}

void	allocate_matrices(t_allvars *a)
{
	a->i = malloc(sizeof(t_point) * (a->tx * a->ty));
	if (!a->i)
		quit(a, 4);
	a->bt = malloc(sizeof(t_point) * (a->tx * a->ty));
	if (!a->bt)
		quit(a, 5);
	a->o = malloc(sizeof(t_point) * (a->tx * a->ty));
	if (!a->o)
		quit(a, 6);
	a->c = malloc(sizeof(t_coord) * (a->tx * a->ty));
	if (!a->c)
		quit(a, 7);
}

//initialize server and check
//create new window and check; free mlx pointer on error
//create new image
//get image parameters info
void	initialize_window(t_allvars *a)
{
	t_data		data;
	t_img		img;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		quit(a, 8);
	data.win_ptr = mlx_new_window(data.mlx_ptr, IMG_W, IMG_H, "FdF");
	if (data.win_ptr == NULL)
		quit(a, 9);
	img.img = mlx_new_image(data.mlx_ptr, IMG_W, IMG_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	a->data = data;
	a->img = img;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:51:03 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 15:56:42 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	clear_image(t_allvars *a)
{
	int	k;
	int	l;

	k = 0;
	while (k < IMG_H)
	{
		l = 0;
		while (l < IMG_W)
		{
			my_mlx_pixel_put(&a->img, l, k, 0x151515);
			l++;
		}
		k++;
	}
	mlx_put_image_to_window(a->data.mlx_ptr, a->data.win_ptr, a->img.img, 0, 0);
	mlx_clear_window(a->data.mlx_ptr, a->data.win_ptr);
}

void	menu_text(t_allvars *a)
{
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 50, LTR_C, "W,A,S,D to translate on x & y");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 90, LTR_C, "I for isometric projection");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 110, LTR_C, "O for parallel projection");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 130, LTR_C, "P for perspective projection");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 150, LTR_C, "C for conical projection");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 180, LTR_C, "Z and X for zoom");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 200, LTR_C, "Up and Down to scale z");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 220, LTR_C, "Left and right to scale bending");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 260, LTR_C, "F and G to rotate on z");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 280, LTR_C, "H and J to rotate on y");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 300, LTR_C, "K and L to rotate on x");
	mlx_string_put(a->data.mlx_ptr, a->data.win_ptr,
		20, 320, LTR_C, "M to toggle the menu");
}

void	put_menu(t_allvars *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < IMG_H)
	{
		j = 0;
		while (j < MENU_W)
		{
			my_mlx_pixel_put(&a->img, j, i, 0xc3c3c3);
			j++;
		}
		i++;
	}
}

void	put_lines(t_allvars *a)
{
	int	k;
	int	l;

	k = 0;
	while (k < a->ty)
	{
		l = 0;
		while (l < a->tx)
		{
			if (l < a->tx - 1)
				bresenhams_alg(&a->c[k * a->tx + l],
					&a->c[k * a->tx + l + 1], a);
			if (k < a->ty -1)
				bresenhams_alg(&a->c[k * a->tx + l],
					&a->c[(k + 1) * a->tx + l], a);
			l++;
		}
		k++;
	}
	if (a->menu == 1)
		put_menu(a);
}

int	render(t_allvars *a)
{
	make_matrix(a);
	if (a->data.win_ptr != NULL)
	{
		clear_image(a);
		put_lines(a);
		mlx_put_image_to_window(a->data.mlx_ptr,
			a->data.win_ptr, a->img.img, 0, 0);
		if (a->menu == 1)
			menu_text(a);
	}	
	return (0);
}

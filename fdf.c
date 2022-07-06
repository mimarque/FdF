/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:08:24 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 17:27:01 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_allvars	a;

	a = (t_allvars){0};
	if (argc != 2)
		quit(&a, 1);
	count_file_items(&a, argv);
	get_z_values(&a, argv);
	initialize_window(&a);
	initialize_a(&a);
	mlx_loop_hook(a.data.mlx_ptr, render, &a);
	mlx_key_hook(a.data.win_ptr, keypress, &a);
	mlx_hook(a.data.win_ptr, 17, 0, quit, &a);
	mlx_loop(a.data.mlx_ptr);
}

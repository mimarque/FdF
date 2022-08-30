/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:34:47 by mimarque          #+#    #+#             */
/*   Updated: 2022/08/30 16:28:47 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quit1(t_allvars *a, int error)
{
	if (error == 1)
		ft_printf("Wrong arguments.\nusage: ./FdF <map.fdf>");
	else if (error == 2)
		ft_printf("Error opening file");
	else if (error == 3)
		ft_printf("Error file improperly formated");
	else if (error == 4)
		ft_printf("Error allocating memory");
	else if (error == 5)
	{
		free(a->i);
		ft_printf("Error allocating memory");
	}
	else if (error == 6)
	{
		free(a->i);
		free(a->bt);
		ft_printf("Error allocating memory");
	}
}

void	quit2(t_allvars *a, int error)
{
	if (error == 7)
	{
		free(a->i);
		free(a->bt);
		ft_printf("Error allocating memory");
	}
	else if (error == 8)
	{
		free(a->i);
		free(a->bt);
		free(a->c);
	}
	else if (error == 9)
	{
		free(a->i);
		free(a->bt);
		free(a->c);
		mlx_destroy_window(a->data.mlx_ptr, a->data.win_ptr);
		mlx_destroy_display(a->data.mlx_ptr);
	}
}

/**
 * @brief Closes window and frees memory
 * 
 * @param a Data struct used in this program
 * @param error 0 if successfull 
 * @return int 
 */
int	quit(t_allvars *a, int error)
{
	if (error >= 1 && error < 7)
		quit1(a, error);
	if (error >= 7 && error <= 9)
		quit2(a, error);
	else if (error > 9 || error == 0)
	{
		free(a->i);
		free(a->bt);
		free(a->c);
		mlx_destroy_image(a->data.mlx_ptr, a->img.img);
		mlx_destroy_window(a->data.mlx_ptr, a->data.win_ptr);
		mlx_destroy_display(a->data.mlx_ptr);
		free(a->data.mlx_ptr);
	}
	exit(error);
}

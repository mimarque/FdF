/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:23:23 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/07 22:14:38 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_coordinates_color(char **arr, t_allvars *a)
{
	char	**arr2;

	arr2 = ft_split(arr[a->x], ',');
	a->i[a->y * a->tx + a->x].x = (float)a->x -(a->tx / 2);
	a->i[a->y * a->tx + a->x].y = (float)a->y -(a->ty / 2);
	a->i[a->y * a->tx + a->x].z = (float)(ft_atoi(arr2[0]));
	a->i[a->y * a->tx + a->x].c = (hex2int(arr2[1]));
	delete_arr_arr(arr2);
}

void	get_coordinates(char **arr, t_allvars *a)
{
	a->i[a->y * a->tx + a->x].x = (float)a->x - (a->tx / 2);
	a->i[a->y * a->tx + a->x].y = (float)a->y - (a->ty / 2);
	a->i[a->y * a->tx + a->x].z = (float)(ft_atoi(arr[a->x]));
	if (a->i[a->y * a->tx + a->x].z >= 10)
		a->i[a->y * a->tx + a->x].c = 0xf3b03d;
	else if (a->i[a->y * a->tx + a->x].z <= -10)
		a->i[a->y * a->tx + a->x].c = 0xffffff;
	else
		a->i[a->y * a->tx + a->x].c = 0x9A1F6A;
}

void	get_z_val_while(char **arr, t_allvars *a)
{
	char	*pos2;

	a->x = 0;
	while (a->x < a->tx)
	{
		pos2 = ft_strchr(arr[a->x], ',');
		if (pos2)
			get_coordinates_color(arr, a);
		else
			get_coordinates(arr, a);
		a->x++;
	}
}

void	get_z_val_alocate(t_allvars *a)
{
	a->tx = a->x;
	a->ty = a->y;
	a->y = 0;
	allocate_matrices(a);
}

void	get_z_values(t_allvars *a, char **argv)
{
	int		fd;
	char	*line;
	char	*pos;
	char	**arr;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		quit(a, 2);
	get_z_val_alocate(a);
	line = get_next_line(fd);
	while (line != NULL)
	{
		pos = ft_strchr(line, '\n');
		if(pos != NULL)
			*pos = '\0';
		arr = ft_split(line, ' ');
		get_z_val_while(arr, a);
		delete_arr_arr(arr);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		a->y++;
	}
	close(fd);
}

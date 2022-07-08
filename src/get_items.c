/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:43:27 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/07 22:14:35 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief If input j (aka x) is zero it assumes 
 * it is the first time running and counts
 * how many strings are in array arr.
 * 
 * However if j is not zero it again counts how many
 * strings are in array arr and compares it with j
 * If different it quits the program
 */
void	check_items_inline(t_allvars *a, char *line, char **arr, int *j)
{
	int			j2;

	if (*j == 0)
		while (arr[*j] != 0)
			(*j)++;
	else
	{
		j2 = 0;
		while (arr[j2] != 0)
			j2++;
		if (*j != j2)
		{
			delete_arr_arr(arr);
			free(line);
			quit(a, 3);
		}
	}
}

//checks file and gets number of rows and columns
void	count_file_items(t_allvars *a, char **argv)
{
	char	*line;
	char	*pos;
	char	**arr;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		quit(a, 2);
	line = get_next_line(fd);
	a->x = 0;
	a->y = 0;
	while (line != NULL)
	{
		pos = ft_strchr(line, '\n');
		*pos = '\0';
		arr = ft_split(line, ' ');
		check_items_inline(a, line, arr, &a->x);
		delete_arr_arr(arr);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		a->y++;
	}
	close(fd);
}

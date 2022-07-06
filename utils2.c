/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:38:27 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 16:40:07 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	my_sign(float value)
{
	if (value < 0.0)
		return (-1);
	else if (value > 0.0)
		return (1);
	else
		return (0);
}

int	hex2int(char *hex)
{
	int	val;
	int	byte;

	val = 0;
	while (*hex)
	{
		byte = *hex++;
		if (byte == '0' && (*hex == 'x' || *hex == 'X'))
		{
			hex++;
			continue ;
		}
		else if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}

void	delete_arr_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	get_z_offset(t_allvars *a)
{
	t_point	max_world;
	int		i;

	max_world = (t_point){-__FLT_MAX__, -__FLT_MAX__, -__FLT_MAX__, 0};
	i = 0;
	while (i++ < (a->tx * a->ty))
		if (a->i[i].z > max_world.z)
			max_world.z = a->i[i].z;
	a->tlz = -(max_world.z + 1);
}

void	get_xyz_offset(t_allvars *a)
{
	a->tlx = -(a->tx / 4);
	a->tly = (a->ty / 4);
	get_z_offset(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_valid_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:08:58 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:13:09 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rgb_to_hex(t_data *d)
{
	d->map->f_color = ((d->map->f[0]) & 0xff) + ((d->map->f[1]) & 0xff << 8) \
	+ ((d->map->f[2]) & 0xff << 16);
			d->map->c_color = ((d->map->c[0]) & 0xff) + ((d->map->c[1]) & \
			0xff << 8) + ((d->map->c[2]) & 0xff << 16);
}

void	check_sym(t_data *data, int i, int j)
{
	if (i != 0)
		if (!ft_strchr(" 1", data->map->map[i - 1][j]))
			data->err = 1;
	if (i != 0 && j != 0 && data->map->map[i - 1][j - 1])
		if (!ft_strchr(" 1", data->map->map[i - 1][j - 1]))
			data->err = 1;
	if (i != 0 && data->map->map[i - 1][j + 1] && data->map->map[i - 1][j + 1]
	!= '\n')
		if (!ft_strchr(" 1\0\n", data->map->map[i - 1][j + 1]))
			data->err = 1;
	if (j != 0 && data->map->map[i][j - 1])
		if (!ft_strchr(" 1", data->map->map[i][j - 1]))
			data->err = 1;
	if (data->map->map[i][j + 1] && data->map->map[i][j + 1] != '\n')
		if (!ft_strchr(" 1\0\n", data->map->map[i][j + 1]))
			data->err = 1;
}

void	check_next_sym(t_data *data, int i, int j)
{
	if (i + 1 != data->map->count_line)
	{
		if (data->map->map[i + 1][j])
			if (!ft_strchr(" 1", data->map->map[i + 1][j]))
				data->err = 1;
		if (j != 0 && data->map->map[i + 1][j - 1])
			if (!ft_strchr(" 1", data->map->map[i + 1][j - 1]))
				data->err = 1;
		if (data->map->map[i + 1][j + 1])
			if (!ft_strchr(" 1", data->map->map[i + 1][j + 1]))
				data->err = 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_valid_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:56:52 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 15:29:09 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	close_wall_utils(int i, t_data *data, int *err, int j)
{
	if (i == 0)
		if (!ft_strchr(" 1\n", data->map->map[i][j]))
			*err = 1;
	if (i == size_arr(data->map->map) - 1)
		if (!ft_strchr(" 1\n", data->map->map[i][j]))
			*err = 1;
	if (j == 0)
		if (!ft_strchr(" 1\n", data->map->map[i][j]))
			*err = 1;
	if (j == ft_strlen(data->map->map[i]) - 2)
		if (!ft_strchr(" 1\n", data->map->map[i][j]))
			*err = 1;
}

void	check_close_wall(t_data *data)
{
	int	i;
	int	j;
	int	err;

	i = 0;
	err = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			close_wall_utils(i, data, &err, j);
			j++;
		}
		i++;
	}
	if (err == 1)
		print_error_and_exit(data, "Error");
}

void	put_player(int i, int j, t_data *data)
{
	data->ply->x = j + 0.5;
	data->ply->y = i + 0.5;
	if (ft_strchr("N", data->map->map[i][j]))
		data->ply->angle = 90;
	else if (ft_strchr("S", data->map->map[i][j]))
		data->ply->angle = 270;
	else if (ft_strchr("W", data->map->map[i][j]))
		data->ply->angle = 180;
	else if (ft_strchr("E", data->map->map[i][j]))
		data->ply->angle = 0;
	data->ply->move_k = 0.2;
	data->ply->rotate_k = 1.5;
	data->ply->fov = 60;
}

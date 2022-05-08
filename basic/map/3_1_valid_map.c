/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_valid_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:52:07 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 15:23:18 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_player(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (ft_strchr("NSEW", data->map->map[i][j]))
			{
				put_player(i, j, data);
				count++;
				data->map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		print_error_and_exit(data, "Error");
}

void	check_map_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (!ft_strchr(" 10NSEW\n", data->map->map[i][j]))
				print_error_and_exit(data, "Error");
			j++;
		}
		i++;
	}
}

void	valid_map(t_data *data)
{
	check_map_line(data);
	check_player(data);
	check_close_wall(data);
	check_close_wall_inside(data);
	rgb_to_hex(data);
}

void	check_count_line(int count, t_data *data)
{
	int	len;
	int	pre_len;

	if (data->map->map[count - 1])
	{
		len = ft_strlen(data->map->map[count - 1]);
		pre_len = ft_strlen(data->map->map[count - 2]);
		if (len < pre_len)
		{
			if (data->map->map[count - 1][len - 1] != '1')
				print_error_and_exit(data, "Error");
		}
	}
}

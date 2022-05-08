/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_valid_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:02:25 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:09:18 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_space(int i, t_data *data, int j)
{
	if (data->map->map[i][j] == ' ')
	{
		check_sym(data, i, j);
		check_next_sym(data, i, j);
	}
}

void	wall_len_next_line2(int i, t_data *data, int size, int next_size)
{
	if (size < next_size)
	{
		while (data->map->map[i + 1][size])
		{
			if (!ft_strchr("1\n", data->map->map[i + 1][size]))
				data->err = 1;
			size++;
		}
	}
	else if (size > next_size)
	{
		while (next_size != size)
		{
			if (!ft_strchr("1\n", data->map->map[i][next_size]))
				data->err = 1;
			next_size++;
		}
	}
}

void	wall_len_next_line(int i, t_data *data, int j)
{
	size_t	size;
	size_t	next_size;

	size = ft_strlen(data->map->map[i]) - 2;
	if (data->map->map[i + 1])
	{
		next_size = ft_strlen(data->map->map[i + 1]) - 2;
		if (data->map->map[i + 1][next_size + 2] == '\0' )
			next_size++;
	}
	else
		return ;
	wall_len_next_line2(i, data, size, next_size);
}

void	close_wall_in_utils(int i, t_data *data, int j)
{
	if (i != (size_arr(data->map->map) - 1) && !data->map->map[i + 1][j])
	{
		if (!ft_strchr("1\n", data->map->map[i][j]))
			data->err = 1;
	}
	if (i != (size_arr(data->map->map) - 1) && data->map->map[i + 1][j])
	{
		if (data->map->map[i + 1][j] == '\n' || data->map->map[i + 1][j] ==
		'\0')
			if (!ft_strchr("1\n", data->map->map[i][j]))
				data->err = 1;
	}
}

void	check_close_wall_inside(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->err = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			close_wall_in_utils(i, data, j);
			wall_len_next_line(i, data, j);
			check_space(i, data, j);
			j++;
		}
		i++;
	}
	if (data->err == 1)
	{
		printf("Error\n");
		clear_and_exit(data);
	}
}

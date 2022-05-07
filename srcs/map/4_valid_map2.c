/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_valid_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:26:51 by sshera            #+#    #+#             */
/*   Updated: 2022/05/07 19:30:32 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	close_wall_in_utils(int i, t_data *data, int *err, int j)
{
	if (i != (size_arr(data->map->map) - 1) && !data->map->map[i + 1][j])
	{
		if (!ft_strchr("1\n", data->map->map[i][j]))
			*err = 1;
	}
	if (i != (size_arr(data->map->map) - 1) && data->map->map[i + 1][j])
	{
		if (data->map->map[i + 1][j] == '\n' || data->map->map[i + 1][j] ==
		'\0')
			if (!ft_strchr("1\n", data->map->map[i][j]))
				*err = 1;
	}
}

void	wall_len_next_line(int i, t_data *data, int *err, int j)
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
	if (size < next_size)
	{
		while (data->map->map[i + 1][size])
		{
			if (!ft_strchr("1\n", data->map->map[i + 1][size]))
				*err = 1;
			size++;
		}
	}
	else if (size > next_size)
	{
		while (next_size != size)
		{
			if (!ft_strchr("1\n", data->map->map[i][next_size]))
				*err = 1;
			next_size++;
		}
	}
}

void	check_space(int i, t_data *data, int *err, int j)
{
	if (data->map->map[i][j] == ' ')
	{
		check_sym(data, i, j, err);
		check_next_sym(data, i, j, err);
	}
}

void	check_close_wall_inside(t_data *data)
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
			close_wall_in_utils(i, data, &err, j);
			wall_len_next_line(i, data, &err, j);
			check_space(i, data, &err, j);
			j++;
		}
		i++;
	}
	if (err == 1)
	{
		printf("Error\n");
		clear_and_exit(data);
	}
}

void	init_direction(int y, int x, t_data *o)
{
	if (o->map->map[y][x] == 'N')
	{
		o->dir_y = -1;
		o->dir_x = 0;
	}
	else if (o->map->map[y][x] == 'S')
	{
		o->dir_y = 1;
		o->dir_x = 0;
	}
	else if (o->map->map[y][x] == 'E')
	{
		o->dir_y = 0;
		o->dir_x = 1;
	}
	else if (o->map->map[y][x] == 'W')
	{
		o->dir_y = 0;
		o->dir_x = -1;
	}
}

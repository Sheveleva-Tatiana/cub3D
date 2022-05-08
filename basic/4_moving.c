/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_moving.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:29:12 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:29:59 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_up_down(double x, double y, t_data *data)
{
	if (data->active_key[13] == 1)
	{
		if (data->map->map[(int)data->ply->y][(int)(data->ply->x + x)] == '0')
			data->ply->x = data->ply->x + x;
		if (data->map->map[(int)(data->ply->y + y)][(int)data->ply->x] == '0')
			data->ply->y = data->ply->y + y;
	}
	else if (data->active_key[1] == 1)
	{
		if (data->map->map[(int)data->ply->y][(int)(data->ply->x - x)] == '0')
			data->ply->x = data->ply->x - x;
		if (data->map->map[(int)(data->ply->y - y)][(int)data->ply->x] == '0')
			data->ply->y = data->ply->y - y;
	}
}

void	player_left_right(double x, double y, t_data *data)
{
	if (data->active_key[123] == 1)
	{
		data->ply->angle = data->ply->angle + data->ply->rotate_k;
		if (data->ply->angle >= 360)
			data->ply->angle = 0;
		if (data->ply->angle <= -360)
			data->ply->angle = 0;
	}
	else if (data->active_key[124] == 1)
	{
		data->ply->angle = data->ply->angle - data->ply->rotate_k;
		if (data->ply->angle >= 360)
			data->ply->angle = 0;
		if (data->ply->angle <= -360)
			data->ply->angle = 0;
	}
}

void	player_rotate(t_data *data)
{
	if (data->active_key[0])
	{
		data->ply->angle = data->ply->angle + data->ply->rotate_k;
		if (data->ply->angle >= 360)
			data->ply->angle = 0;
		if (data->ply->angle <= -360)
			data->ply->angle = 0;
	}
	if (data->active_key[2])
	{
		data->ply->angle = data->ply->angle - data->ply->rotate_k;
		if (data->ply->angle >= 360)
			data->ply->angle = 0;
		if (data->ply->angle <= -360)
			data->ply->angle = 0;
	}
}

void	moving(t_data *data)
{
	double	x;
	double	y;

	x = data->ply->move_k * cos(data->ply->angle * PI / 180);
	y = -data->ply->move_k * sin(data->ply->angle * PI / 180);
	if (data->active_key[53] == 1)
		clear_and_exit(data);
	player_up_down(x, y, data);
	player_left_right(x, y, data);
	player_rotate(data);
}

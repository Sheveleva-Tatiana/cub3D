#include "../include/cub3d.h"

void	player_up_down(double x, double y, t_data *data)
{
	if (data->active_key[13] == 1) {
		if (data->map->map[(int) data->ply->y][(int) (data->ply->x + x)] == '0')
			data->ply->x = data->ply->x + x;
		if (data->map->map[(int)(data->ply->y + y)][(int)data->ply->x] == '0')
			data->ply->y = data->ply->y + y;
	}
	else if (data->active_key[1] == 1)
	{
		if (data->map->map[(int) data->ply->y][(int) (data->ply->x - x)] == '0')
			data->ply->x = data->ply->x - x;
		if (data->map->map[(int)(data->ply->y - y)][(int)data->ply->x] == '0')
			data->ply->y = data->ply->y - y;
	}
}

void	player_left_right(double x, double y, t_data *data)
{
	int p_y;
	int p_x;

	p_y = (int)data->ply->y;
	p_x = (int)data->ply->x;
	if (data->active_key[124] == 1)
	{
		if (data->map->map[p_y][(int)(p_x - y)] == '0'
			&& data->map->map[(int)(p_y + x)][p_x] == '0')
		{
			data->ply->x = data->ply->x - y;
			data->ply->y = data->ply->y + x;
		}
	}
	else if (data->active_key[123] == 1)
	{
		if (data->map->map[p_y][(int)(p_x + y)] == '0'
			&& data->map->map[(int)(p_y - x)][p_x] == '0')
		{
			data->ply->x = data->ply->x + y;
			data->ply->y = data->ply->y - x;
		}
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

void	get_coordinates(t_data *data)
{
	double x;
	double y;

	x = data->ply->move_k * cos(data->ply->angle * PI / 180);
	y = -data->ply->move_k * sin(data->ply->angle * PI / 180);
	player_up_down(x, y, data);
	player_left_right(x, y, data);
	player_rotate(data);
}
#include "../../include/cub3d.h"

 void	check_map_line(t_data *data)
{
	int	i;
	int j;

	i = 0;
	while(data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j]) {
			if (!ft_strchr(" 10NSEW\n", data->map->map[i][j])) {
				printf("Error\n");
				clear_and_exit(data);
			}
			j++;
		}
		i++;
	}
}

void	put_player(int i, int j, t_data *data)
{
	data->ply->x = j;
	data->ply->y = i;
	if (ft_strchr("N", data->map->map[i][j])) {
		data->ply->pos = N;
		data->ply->angle = 90;
	}
	else if (ft_strchr("S", data->map->map[i][j])) {
		data->ply->pos = S;
		data->ply->angle = 270;
	}
	else if (ft_strchr("W", data->map->map[i][j])) {
		data->ply->pos = W;
		data->ply->angle = 180;
	}
	else if (ft_strchr("E", data->map->map[i][j])) {
		data->ply->pos = E;
		data->ply->angle = 0;
	}
	data->ply->move_k = 0.1;
	data->ply->rotate_k = 1.5;
}

void	check_player(t_data *data)
{
	int	i;
	int j;
	int count;

	i = 0;
	count = 0;
	while(data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j]) {
			if (ft_strchr("NSEW", data->map->map[i][j])) {
				put_player(i, j, data);
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		printf("Error\n");
		clear_and_exit(data);
	}
}

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
	int j;
	int err;

	i = 0;
	err = 0;
	while(data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j]) {
			close_wall_utils(i, data, &err, j);
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

void	valid_map(t_data *data)
{
	check_map_line(data);
	check_player(data);
	check_close_wall(data);
	check_close_wall_inside(data);
}

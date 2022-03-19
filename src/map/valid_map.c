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

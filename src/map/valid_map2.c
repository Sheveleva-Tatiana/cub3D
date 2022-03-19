#include "../../include/cub3d.h"

void	close_wall_in_utils(int i, t_data *data, int *err, int j)
{
	if (i != (size_arr(data->map->map) - 1) && !data->map->map[i + 	1][j])
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
	int size;
	int next_size;

	size = ft_strlen(data->map->map[i]) - 2;
	if (data->map->map[i + 1])
		next_size = ft_strlen(data->map->map[i + 1]) - 2;
	else
		return ;
	if (size < next_size)
	{
		while (data->map->map[i + 1][size]) {
			if (!ft_strchr("1\n", data->map->map[i + 1][size]))
				*err = 1;
			size++;
		}
	}
	else if (size > next_size)
	{
		while (next_size != size)
		{
			if (!ft_strchr("1\n", data->map->map[i ][next_size]))
				*err = 1;
			next_size++;
		}
	}
}

void	check_close_wall_inside(t_data *data)
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
			close_wall_in_utils(i, data, &err, j);
			wall_len_next_line(i, data, &err, j);
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
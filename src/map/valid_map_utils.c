#include "../../include/cub3d.h"

void	check_sym(t_data *data, int i, int j, int *err)
{
	if (i != 0)
		if (!ft_strchr(" 1", data->map->map[i - 1][j]))
			*err = 1;
	if (i != 0 && j != 0 && data->map->map[i - 1][j - 1])
		if (!ft_strchr(" 1", data->map->map[i - 1][j - 1]))
			*err = 1;
	if (i != 0 && data->map->map[i - 1][j + 1] && data->map->map[i - 1][j + 1]
	!= '\n')
		if (!ft_strchr(" 1\0\n", data->map->map[i - 1][j + 1]))
			*err = 1;
	if (j != 0 && data->map->map[i][j - 1])
		if (!ft_strchr(" 1", data->map->map[i][j - 1]))
			*err = 1;
	if (data->map->map[i][j + 1] && data->map->map[i][j + 1] != '\n')
		if (!ft_strchr(" 1\0\n", data->map->map[i][j + 1]))
			*err = 1;
}

void	check_next_sym(t_data *data, int i, int j, int *err)
{
	if (i + 1 != data->map->count_line) {
		if (data->map->map[i + 1][j])
			if (!ft_strchr(" 1", data->map->map[i + 1][j]))
				*err = 1;
		if (j != 0 && data->map->map[i + 1][j - 1])
			if (!ft_strchr(" 1", data->map->map[i + 1][j - 1]))
				*err = 1;
		if (data->map->map[i + 1][j + 1])
			if (!ft_strchr(" 1", data->map->map[i + 1][j + 1]))
				*err = 1;
	}
}
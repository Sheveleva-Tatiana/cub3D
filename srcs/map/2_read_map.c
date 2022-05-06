#include "../../include/cub3d.h"

void	init_struct_map(t_data *data)
{
	data->map->ea = NULL;
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->we = NULL;
}

void	get_data(char *line, t_data *data, int flag)
{
	char	**arr;
	char	*l;
	int		i;

	i = 0;
	l = ft_substr(line, 1, ft_strlen(line));
	free(line);
	line = ft_strtrim(l, " ");
	free(l);
	arr = ft_split(line, ',');
	while (arr[i])
	{
		if (!(ft_isdigit_char(arr[i])))
			print_error_and_exit(data, "Error is not digit");
		if (flag == 0)
			data->map->f[i] = ft_atoi(arr[i]);
		else
			data->map->c[i] = ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	copy_map(char *file, int start, t_data *data, int end)
{
	int		fd;
	char	*line;
	int 	i;
	int		k;

	fd = open(file, O_RDONLY);
	i = 0;
	k = 0;
	line = get_next_line(fd);
	data->map->map = malloc(sizeof(char *) * ((end - start) + 1) + 1);
	while(line)
	{
		if (i >= start && line[0] != '\n')
		{
			data->map->map[k] = line;
			k++;
		}
		else
			free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map->map[k] = NULL;
	close(fd);
}

void	trim_space(t_data *data)
{
	char	*line;

	if (data->map->no)
	{
		line = ft_strtrim(data->map->no, " ");
		free(data->map->no);
		data->map->no = line;
	}
	if (data->map->so)
	{
		line = ft_strtrim(data->map->so, " ");
		free(data->map->so);
		data->map->so = line;
	}
	if (data->map->we)
	{
		line = ft_strtrim(data->map->we, " ");
		free(data->map->we);
		data->map->we = line;
	}
	if (data->map->ea)
	{
		line = ft_strtrim(data->map->ea, " ");
		free(data->map->ea);
		data->map->ea = line;
	}

}

void	init_camera_plane(t_data *data)
{
	if (data->dir_x == 0 && data->dir_y == -1)
	{
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (data->dir_x  == 0 && data->dir_y == 1)
	{
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else if (data->dir_y == 0 && data->dir_x == -1)
	{
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	else if (data->dir_y == 0 && data->dir_x == 1)
	{
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
}
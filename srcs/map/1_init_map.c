#include "../../include/cub3d.h"

int	check_line(char *line, t_data *data)
{
	char	*l;
	int 	i;

	i = 0;
	l = ft_strtrim(line, " ");
	free(line);
	if (ft_strlen(l) > 2) {
		if (ft_strnstr(l, "NO", 2))
			data->map->no = ft_substr(l, 2, ft_strlen(l));
		else if (ft_strnstr(l, "SO", 2))
			data->map->so = ft_substr(l, 2, ft_strlen(l));
		else if (ft_strnstr(l, "WE", 2))
			data->map->we = ft_substr(l, 2, ft_strlen(l));
		else if (ft_strnstr(l, "EA", 2))
			data->map->ea = ft_substr(l, 2, ft_strlen(l));
		else if (ft_strnstr(l, "F", 1))
			get_data(l, data, 0);
		else if (ft_strnstr(l, "C", 1))
			get_data(l, data, 1);
		else
			i = 1;
	}
	free(l);
	if (i == 1)
		return (0);
	return (1);
}

int		get_start_line(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int 	i;

	data->map = malloc(sizeof(t_map));
	if(!data->map)
		print_error_and_exit(data, "Malloc error");
	init_struct_map(data);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line) {
		if (check_line(line, data))
			i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int     get_count_line(char *file, int *count)
{
    int		fd;
	char 	*line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1);
	(*count) = 0;
	line = get_next_line(fd);
    while(line)
	{
		free(line);
		line = get_next_line(fd);
		(*count)++;
	}
	free(line);
    close(fd);
    return (1);
}

void	init_active_key(t_data *data)
{
	int i;

	i = 0;
	data->ply = malloc(sizeof(t_ply));
}

void	rgb_to_hex(t_data *data)
{
	data->map->f_color = ((data->map->f[0]) & 0xff) + ((data->map->f[1]) & 0xff<< 8) +
			((data->map->f[2]) & 0xff << 16);
	data->map->c_color = ((data->map->c[0]) & 0xff) + ((data->map->c[1]) &
			0xff << 8) + ((data->map->c[2]) & 0xff << 16);
}

void	free_all(t_data *data)
{
	int i;

	i = 0;
	if(data)
	{
		if (data->map)
		{
			while (data->map->map[i])
				free(data->map->map[i++]);
			free(data->map->map);
			free(data->map->ea);
			free(data->map->no);
			free(data->map->so);
			free(data->map->we);
			i = 0;
			if (data->map->tex)
				free(data->map->tex);
			while (i < 4 && data->map->tex[i].path)
				free(data->map->tex[i++].path);
			free(data->map);
		}
		if (data->ply)
			free(data->ply);
		if (data->img)
			free(data->img);
		free(data);
	}
}

void    lets_start(char *filename, t_data *data)
{
    int count;
	int	start;

    count = 0;
	data = malloc(sizeof(t_data));
	if(!data)
		print_error_and_exit(data, "Malloc error");
	init_active_key(data);
	start = get_start_line(filename, data);
    if (get_count_line(filename, &count) == -1)
		print_error_and_exit(data, "Operation file corrupted");
	copy_map(filename, start, data, count);
	trim_space(data);
    data->map->count_line = count - start;
	valid_map(data);
	init_camera_plane(data);
	rgb_to_hex(data);
	run_game(data);
}



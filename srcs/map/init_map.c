#include "../../include/cub3d.h"

int	check_line(char *line, t_data *data)
{
	char	*l;
	int 	i;

	i = 0;
	l = ft_strtrim(line, " ");
	free (line);
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
    int		b;
	char	buf;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1);
	(*count) = 0;
    while(get_next_line(fd))
		(*count)++;
    close(fd);
    return (1);
}

void	init_active_key(t_data *data)
{
	int i;

	i = 0;
	data->ply = malloc(sizeof(t_ply));
	data->active_key = malloc(sizeof(char) * 256);
	while(i < 256)
		data->active_key[i++] = 0;
}

void    init_map(char *filename, t_data *data)
{
    int count;
	int	start;
	int i = 0;

    count = 0;
	data = malloc(sizeof(t_data));
	init_active_key(data);
	start = get_start_line(filename, data);
    if (get_count_line(filename, &count) == -1)
        print_error(1);
	copy_map(filename, start, data, count);
	trim_space(data);
    data->map->count_line = count - start;
	valid_map(data);
	run_game(data);
}



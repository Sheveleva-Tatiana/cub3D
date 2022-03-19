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
	(*count) = 1;
    b = 1;
    while (b > 0)
    {
        b = read(fd, &buf, 1);
        if (buf == '\n')
			(*count)++;
        if (b == -1)
            return (-1);
    }
    close(fd);
    return (1);
}

void    init_map(char *filename, t_data *data)
{
    int count;
	int	start;

    count = 0;
	data = malloc(sizeof(t_data));
	start = get_start_line(filename, data);
    if (get_count_line(filename, &count) == -1)
        print_error(1);
	copy_map(filename, start, data, count);
	int i = 0;
	while (data->map->map[i])
		printf("%s", data->map->map[i++]);
	i = 0;
	while (i < 3)
	{
		printf("\n%d     %d\n", data->map->f[i], data->map->c[i]);
		i++;
	}
	printf("%s%s%s%s", data->map->no, data->map->so,
		   data->map->we, data->map->ea);
    data->map->count_line = count - start + 1;
}



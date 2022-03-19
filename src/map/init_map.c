#include "../../include/cub3d.h"

int		get_start_line(char *file)
{
	int fd;
	fd = open(file, O_RDONLY);


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
	start = get_start_line(filename);
    if (get_count_line(filename, &count) == -1)
        print_error(1);
	printf("%d\n", count);
    data->map = malloc(sizeof (t_map));
    data->map->count_line = count;
}



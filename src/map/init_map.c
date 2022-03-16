#include "../../includes/cub3d.h"

int     get_count_line(char *file, int *count)
{
    int fd;
    int b;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1);
    *count = 1;
    b = 1;
    while (b > 0)
    {
        b = read(fd, &buf, 1);
        if (buf == '\n')
            *count++;
        if (b == -1)
            return (-1);
    }
    close(fd);
    return (1);
}

void    init_map(char *filename, t_data *data)
{
    int count;

    data = malloc(sizeof(t_data));
    if (get_count_line(filename, &count) == -1)

}
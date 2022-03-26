#include "../../include/cub3d.h"

void print_error(int i)
{
    if (i == 1)
    {
        printf("Operation file corrupted");
        exit(1);
    }
}

void	print_error_and_exit(t_data *data, char *str)
{
	printf("%s", str);
	clear_and_exit(data);
}
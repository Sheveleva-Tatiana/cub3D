#include "../../include/cub3d.h"

void print_error(int i)
{
    if (i == 1)
    {
        printf("Operation file corrupted");
        exit(1);
    }
}
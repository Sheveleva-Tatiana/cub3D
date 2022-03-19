#include "../../include/cub3d.h"

int size_arr(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}
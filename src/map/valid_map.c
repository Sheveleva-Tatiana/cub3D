#include "../../include/cub3d.h"

int check_map_line(t_data *data)
{
	int	i;
	int sym_num;
	int j;

	i = 0;
	sym_num = ft_strlen(data->map->map[0]);
	while(data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
			j++;
//		printf("sym= %d,   line=%d\n", sym_num, j);
//		if (sym_num != j) {
//			printf("Error\n");
//			clear_and_exit(data);
//		}
		i++;
	}
}

void	valid_map(t_data *data)
{
	if (check_map_line(data))
		clear_and_exit(data);
}

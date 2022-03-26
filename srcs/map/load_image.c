#include "../../include/cub3d.h"

void	load_image(t_data *data)
{
	int i;

	i = 0;
	data->map->tex = (t_tex *)malloc(sizeof(t_tex) * 4);
	while (i < 3)
	{
		load_tex(data->map->tex[i], data);
		i++;
	}
}
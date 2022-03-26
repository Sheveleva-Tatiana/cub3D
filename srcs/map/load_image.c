#include "../../include/cub3d.h"

char	*load_path(int flag, t_data *data)
{
	if (flag == 0)
		return (ft_strdup(data->map->no));
	else if (flag == 1)
		return (ft_strdup(data->map->we));
	else if (flag == 2)
		return (ft_strdup(data->map->ea));
	else
		return (ft_strdup(data->map->so));
}

void	load_tex(t_tex *tex, t_data *data, int flag)
{
	char	*path;

	path = load_path(flag, data);
	if (access(path, F_OK) == -1)
		print_error_and_exit(data, "Texture file not found\n");
	else if (access(path, R_OK) == -1)
		print_error_and_exit(data, "Error reading texture file\n");
	else
		tex->path = path;
}

void	init_texture(t_tex *tex, t_data *data)
{
	mlx_xpm_file_to_image(data->mlx, tex->path, &tex->width, &tex->height);
}

void	load_image(t_data *data)
{
	int i;

	i = 0;
	data->map->tex = (t_tex *)malloc(sizeof(t_tex) * 4);
	while (i < 4)
	{
		load_tex(&data->map->tex[i], data, i);
		init_texture(&data->map->tex[i], data);
		i++;
	}
}
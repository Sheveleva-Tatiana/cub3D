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

int	check_image_file(char *file)
{
	if (ft_strlen(file) > 4)
		if (!(ft_strnstr(&file[ft_strlen(file) - 4], ".xpm", 4)))
			return (0);
	return (1);
}

void	load_tex(t_tex *tex, t_data *data, int flag)
{
	char	*path;
	char	*all_path;

	all_path = load_path(flag, data);
	path = ft_substr(all_path, 0, ft_strlen(all_path) - 1);
	if (access(path, F_OK)) {
		free(path);
		print_error_and_exit(data, "Texture file not found\n");
	}
	else if (access(path, R_OK)) {
		free(path);
		print_error_and_exit(data, "Error reading texture file\n");
	}
	else
		tex->path = path;
	if (!check_image_file(tex->path))
		print_error_and_exit(data, "The file extension is not .xpm\n");
}

void	init_texture(t_tex *tex, t_data *data)
{
	tex->ptr = mlx_xpm_file_to_image(data->mlx, tex->path, &tex->width,
								   &tex->height);
	tex->data = (int *)mlx_get_data_addr(tex->ptr, &tex->bpp, &tex->size,
								  &tex->endian);
}

void	load_image(t_data *data)
{
	int i;

	i = -1;
	data->map->tex = (t_tex *)malloc(sizeof(t_tex) * 4);
	while (++i < 4)
	{
		load_tex(&data->map->tex[i], data, i);
		init_texture(&data->map->tex[i], data);
	}
}

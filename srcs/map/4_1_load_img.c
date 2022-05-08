/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_1_load_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:14:46 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 16:32:38 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture(t_tex *tex, t_data *data)
{
	tex->ptr = mlx_xpm_file_to_image(data->mlx, tex->path, &tex->width, \
							&tex->height);
	if (!tex->ptr)
		print_error_and_exit(data, "Error cub->map->tex[i].ptr");
	tex->data = mlx_get_data_addr(tex->ptr, &tex->bpp, &tex->size, \
							&tex->endian);
	if (!tex->data)
		print_error_and_exit(data, "Error cub->map->tex[i].data");
}

int	check_image_file(char *file)
{
	if (ft_strlen(file) > 4)
		if (!(ft_strnstr(&file[ft_strlen(file) - 4], ".xpm", 4)))
			return (0);
	return (1);
}

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
	char	*all_path;
	int		fd;

	all_path = load_path(flag, data);
	path = ft_substr(all_path, 0, ft_strlen(all_path) - 1);
	free(all_path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		close(fd);
		print_error_and_exit(data, "Texture file not found");
	}
	else
		tex->path = path;
	if (!check_image_file(tex->path))
	{
		close(fd);
		print_error_and_exit(data, "The file extension is not .xpm");
	}
	close(fd);
}

void	load_image(t_data *data)
{
	int	i;

	i = -1;
	data->map->tex = (t_tex *)malloc(sizeof(t_tex) * 4);
	if (!data->map->tex)
		print_error_and_exit(data, "Malloc error");
	while (++i < 4)
		data->map->tex[i].path = NULL;
	i = -1;
	while (++i < 4)
		load_tex(&data->map->tex[i], data, i);
}

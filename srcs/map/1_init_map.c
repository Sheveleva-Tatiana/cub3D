/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:26:43 by sshera            #+#    #+#             */
/*   Updated: 2022/05/07 19:26:45 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	proverka(char *str, t_data *data)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!ft_strchr("10SNWE \n", str[j]))
			print_error_and_exit(data, "Error: hey, honey, your map is bad");
		j++;
	}
	return (1);
}

int	check_line(char *line, t_data *data)
{
	char	*l;
	int		i;

	i = 0;
	l = ft_strtrim(line, " ");
	free(line);
	if (ft_strlen(l) > 2)
	{
		if (ft_strnstr(l, "NO", 2))
			data->map->no = ft_substr(l, 2, ft_strlen(l));
		else if (ft_strnstr(l, "SO", 2))
			data->map->so = ft_substr(l, 2, ft_strlen(l));
		else if (ft_strnstr(l, "WE", 2))
			data->map->we = ft_substr(l, 2, ft_strlen(l));
		else if (ft_strnstr(l, "EA", 2))
			data->map->ea = ft_substr(l, 2, ft_strlen(l));
		else if (ft_strnstr(l, "F", 1))
			get_data(l, data, 0);
		else if (ft_strnstr(l, "C", 1))
			get_data(l, data, 1);
		else if (ft_strnstr(l, "1", 1) || ft_strnstr(l, "0", 1))
			i = proverka(l, data);
		else
			print_error_and_exit(data, "Error: hey, honey, your map is bad");
	}
	free(l);
	if (i == 1)
		return (0);
	return (1);
}

int	get_start_line(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	data->map = malloc(sizeof(t_map));
	if (!data->map)
		print_error_and_exit(data, "Malloc error");
	init_struct_map(data);
	fd = open(file, O_RDONLY);
	if (!fd)
		print_error_and_exit(data, "Error: I can't open file");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (check_line(line, data))
			i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	get_count_line(char *file, int *count)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	(*count) = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		(*count)++;
	}
	free(line);
	close(fd);
	return (1);
}

void	rgb_to_hex(t_data *d)
{
	d->map->f_color = ((d->map->f[0]) & 0xff) + ((d->map->f[1]) & 0xff << 8) \
			+ ((d->map->f[2]) & 0xff << 16);
	d->map->c_color = ((d->map->c[0]) & 0xff) + ((d->map->c[1]) & \
			0xff << 8) + ((d->map->c[2]) & 0xff << 16);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		if (data->map)
		{
			if (data->map->map)
				clear_arr(data->map->map);
			if (data->map->ea)
				free(data->map->ea);
			if (data->map->no)
				free(data->map->no);
			if (data->map->so)
				free(data->map->so);
			if (data->map->we)
				free(data->map->we);
			i = 0;
			if (data->map->tex)
			{
				while (i < 4 && data->map->tex[i].path)
					free(data->map->tex[i++].path);
				free(data->map->tex);
			}
			free(data->map);
		}
		if (data->ply)
			free(data->ply);
		if (data->img)
			free(data->img);
		free(data);
	}
}

void	check_texture(t_data *data)
{
	if (!data->map->ea)
		print_error_and_exit(data, "Error: Hey, baby, give me correct texture");
	if (!data->map->no)
		print_error_and_exit(data, "Error: Hey, baby, give me correct texture");
	if (!data->map->we)
		print_error_and_exit(data, "Error: Hey, baby, give me correct texture");
	if (!data->map->so)
		print_error_and_exit(data, "Error: Hey, baby, give me correct texture");
	if (!data->map->f[0] || !data->map->c[0])
		print_error_and_exit(data, "Error: Hey, baby, give me correct color");
}

void	check_count_line(int count, t_data *data)
{
	int	len;
	int	pre_len;

	if (data->map->map[count - 1])
	{
		len = ft_strlen(data->map->map[count - 1]);
		pre_len = ft_strlen(data->map->map[count - 2]);
		if (len < pre_len)
		{
			if (data->map->map[count - 1][len - 1] != '1')
				print_error_and_exit(data, "Error");
		}
	}
}

void	lets_start(char *filename, t_data *data)
{
	int	count;
	int	start;

	count = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		print_error_and_exit(data, "Malloc error");
	data->ply = malloc(sizeof(t_ply));
	if (!data->ply)
		print_error_and_exit(data, "Malloc error");
	start = get_start_line(filename, data);
	check_texture(data);
	if (get_count_line(filename, &count) == -1)
		print_error_and_exit(data, "Operation file corrupted");
	copy_map(filename, start, data, count);
	trim_space(data);
	data->map->count_line = count - start;
	check_count_line(data->map->count_line, data);
	valid_map(data);
	init_camera_plane(data);
	rgb_to_hex(data);
	run_game(data);
}

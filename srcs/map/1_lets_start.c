/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_lets_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:49:47 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:59:46 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	copy_sides(char *l, t_data *data, int *i)
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
		(*i) = proverka(l, data);
	else
		print_error_and_exit(data, "Error: hey, honey, your map is bad");
}

int	check_line(char *line, t_data *data, int i)
{
	char	*l;

	l = ft_strtrim(line, " ");
	free(line);
	if (ft_strlen(l) > 2)
		copy_sides(l, data, &i);
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

	fd = open(file, O_RDONLY);
	if (!fd)
		print_error_and_exit(data, "Error: I can't open file");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (check_line(line, data, 0))
			i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	init_struct_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		print_error_and_exit(data, "Malloc error");
	data->ply = malloc(sizeof(t_ply));
	if (!data->ply)
		print_error_and_exit(data, "Malloc error");
	data->map->ea = NULL;
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->we = NULL;
	data->map->map = NULL;
	data->map->f[0] = 0;
	data->map->c[0] = 0;
}

void	lets_start(char *filename, t_data *data, int count, int start)
{
	data = malloc(sizeof(t_data));
	if (!data)
		print_error_and_exit(data, "Malloc error");
	init_struct_map(data);
	start = get_start_line(filename, data);
	check_texture(data);
	if (get_count_line(filename, &count) == -1)
		print_error_and_exit(data, "Operation file corrupted");
	copy_map(filename, start, data, count);
	trim_space(data);
	data->map->count_line = count - start;
	check_count_line(data->map->count_line, data);
	valid_map(data);
	run_game(data);
}

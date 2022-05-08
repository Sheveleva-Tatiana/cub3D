/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_checking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:50:01 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 12:51:26 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	trim_space2(t_data *data)
{
	char	*line;

	if (data->map->we)
	{
		line = ft_strtrim(data->map->we, " ");
		free(data->map->we);
		data->map->we = line;
	}
	if (data->map->ea)
	{
		line = ft_strtrim(data->map->ea, " ");
		free(data->map->ea);
		data->map->ea = line;
	}
}

void	trim_space(t_data *data)
{
	char	*line;

	if (data->map->no)
	{
		line = ft_strtrim(data->map->no, " ");
		free(data->map->no);
		data->map->no = line;
	}
	if (data->map->so)
	{
		line = ft_strtrim(data->map->so, " ");
		free(data->map->so);
		data->map->so = line;
	}
	trim_space2(data);
}

void	copy_map(char *file, int start, t_data *data, int end)
{
	int		fd;
	char	*line;
	int		i;
	int		k;

	fd = open(file, O_RDONLY);
	i = 0;
	k = 0;
	line = get_next_line(fd);
	data->map->map = malloc(sizeof(char *) * ((end - start) + 1) + 1);
	while (line)
	{
		if (i >= start && line[0] != '\n')
		{
			data->map->map[k] = line;
			k++;
		}
		else
			free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map->map[k] = NULL;
	close(fd);
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

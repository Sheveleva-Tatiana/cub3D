/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:35:11 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 16:00:01 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	size_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_data_map(t_data *data, int i)
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
	if (data->map->tex)
	{
		while (i < 4 && data->map->tex[i].path)
			free(data->map->tex[i++].path);
		free(data->map->tex);
	}
	free(data->map);
}

void	free_all(t_data *data)
{
	if (data)
	{
		if (data->map)
			free_data_map(data, 0);
		if (data->ply)
			free(data->ply);
		if (data->img)
			free(data->img);
		free(data);
	}
}

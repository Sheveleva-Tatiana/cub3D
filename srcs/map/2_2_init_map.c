/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_2_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:59:14 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:50:08 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	get_data(char *line, t_data *data, int flag)
{
	char	**arr;
	char	*l;
	int		i;

	i = 0;
	l = ft_substr(line, 1, ft_strlen(line));
	free(line);
	line = ft_strtrim(l, " ");
	free(l);
	arr = ft_split(line, ',');
	while (arr[i])
	{
		if (!(ft_isdigit_char(arr[i])))
			print_error_and_exit(data, "Error is not digit");
		if (flag == 0)
			data->map->f[i] = ft_atoi(arr[i]);
		else
			data->map->c[i] = ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

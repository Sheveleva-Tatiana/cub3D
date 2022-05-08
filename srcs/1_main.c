/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:24:56 by bcarlee           #+#    #+#             */
/*   Updated: 2022/05/08 14:25:28 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_name(char *name)
{
	int	fd;

	if (ft_strlen(name) > 4)
	{
		if (ft_strnstr(&name[ft_strlen(name) - 4], ".cub", 4))
		{
			fd = open(name, O_RDONLY);
			if (fd < 0)
				return (0);
			close(fd);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2 && ft_check_name(av[1]))
		lets_start(av[1], &data, 0, 0);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}

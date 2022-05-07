/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:24:56 by bcarlee           #+#    #+#             */
/*   Updated: 2022/05/07 19:36:12 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2 && ft_check_name(av[1]))
		lets_start(av[1], &data);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}

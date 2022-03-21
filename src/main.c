/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:24:56 by bcarlee           #+#    #+#             */
/*   Updated: 2022/03/16 11:24:56 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int ac, char **av)
{
    t_data  data;

    if (ac == 2 && ft_check_name(av[1])) {
		init_map(av[1], &data);
		run_game(&data);
	}
    else
        write(2, "Error : Invalid arguments\n", 26);
    return (0);
}
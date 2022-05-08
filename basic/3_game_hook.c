/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_game_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:44:09 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:28:25 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	press_key(int key, t_data *data)
{
	data->active_key[key] = 1;
	return (0);
}

int	unpress_key(int key, t_data *data)
{
	data->active_key[key] = 0;
	return (0);
}

void	game_hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, press_key, data);
	mlx_hook(data->win, 3, 1L << 0, unpress_key, data);
}

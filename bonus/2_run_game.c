/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_run_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:36:19 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 16:33:00 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	moving(data);
	draw_game(data);
	return (0);
}

int	game_close(t_data *data)
{
	clear_and_exit(data);
	return (0);
}

void	run_game(t_data *data)
{
	int	i;

	load_image(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	i = -1;
	while (++i < 4)
		init_texture(&data->map->tex[i], data);
	data->img = malloc(sizeof(t_img));
	data->img->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img->data = (int *)mlx_get_data_addr(data->img->img, &data->img->bpp, \
	&data->img->ll, &data->img->e);
	mlx_hook(data->win, 17, 0, game_close, data);
	game_hook(data);
	mlx_loop_hook(data->mlx, &render, (void *) data);
	mlx_loop(data->mlx);
}

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

#include "../include/cub3d.h"

int	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	moving(data);
	draw_game(data);
	draw_minimap(data);
	return (0);
}

int	start_game(int keycode, t_data *d)
{
	if (keycode == 36)
	{
		mlx_destroy_image(d->mlx, d->img->img2);
		d->img->img = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
		d->img->data = (int *)mlx_get_data_addr(d->img->img, &d->img->bpp, \
					&d->img->ll, &d->img->e);
		game_hook(d);
		mlx_loop_hook(d->mlx, &render, (void *) d);
	}
	if (keycode == 53)
		clear_and_exit(d);
	return (1);
}

int	animation(t_data *data)
{
	int			w;
	int			h;
	static int	times;

	if (times % 30 == 0)
	{
		data->img->img2 = mlx_xpm_file_to_image(data->mlx, "./tex/begin1" \
					".xpm", &w, &h);
	}
	if (times % 60 == 0)
	{
		data->img->img2 = mlx_xpm_file_to_image(data->mlx, "./tex/begin2" \
					".xpm", &w, &h);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img2, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, start_game, data);
	times++;
	return (1);
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
	mlx_hook(data->win, 17, 0, game_close, data);
	mlx_loop_hook(data->mlx, &animation, (void *) data);
	mlx_loop(data->mlx);
}

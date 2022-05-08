/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_1_draw_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:30:53 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:32:19 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_game2(t_data *data, t_draw *draw)
{
	draw->y = 0;
	ceiling(data, draw);
	draw->texx = (int)(draw->wallx * data->map->tex->height);
	if ((draw->side == 0 && draw->cos > 0) || \
		(draw->side == 1 && draw->sin < 0))
		draw->texx = data->map->tex->width - draw->texx - 1;
	draw->step = (double)data->map->tex->height / draw->lineheight;
	draw->texpos = (draw->drawstart - \
			WIN_HEIGHT / 2 + draw->lineheight / 2) * draw->step;
	walls(data, data->map, draw);
	flour(data, draw);
}

void	draw_game(t_data *data)
{
	t_draw	draw;

	draw.angle_start = data->ply->angle + data->ply->fov / 2;
	draw.angle_end = data->ply->angle - data->ply->fov / 2;
	draw.angle_step = data->ply->fov / WIN_WIDTH;
	draw.angle = draw.angle_start;
	draw.x = 0;
	while (draw.angle > draw.angle_end)
	{
		draw_step_side(data, &draw);
		hit_wall(data, data->map, &draw, data->ply);
		height_wall(data, &draw);
		draw_game2(data, &draw);
		draw.angle -= draw.angle_step;
		draw.x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

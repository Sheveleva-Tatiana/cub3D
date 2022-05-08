/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_2_game_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:34:27 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:35:36 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	height_wall(t_data *cub, t_draw *draw)
{
	if (draw->side == 0)
		draw->perpwalldist = (draw->sidedistx - draw->deltadistx) \
			* cos((cub->ply->angle - draw->angle) * PI / 180);
	else
		draw->perpwalldist = (draw->sidedisty - draw->deltadisty) \
			* cos((cub->ply->angle - draw->angle) * PI / 180);
	draw->lineheight = (int)(WIN_HEIGHT / draw->perpwalldist \
		/ tan(cub->ply->fov / 2 * PI / 180));
	if (draw->side == 0)
		draw->wallx = \
			cub->ply->y - (draw->sidedistx - draw->deltadistx) * draw->sin;
	else
		draw->wallx = \
			cub->ply->x + (draw->sidedisty - draw->deltadisty) * draw->cos;
	draw->wallx -= floor((draw->wallx));
	draw->drawstart = -draw->lineheight / 2 + WIN_HEIGHT / 2;
	if (draw->drawstart < 0)
		draw->drawstart = 0;
	draw->drawend = draw->lineheight / 2 + WIN_HEIGHT / 2;
	if (draw->drawend >= WIN_HEIGHT)
		draw->drawend = WIN_HEIGHT - 1;
}

void	hit_wall(t_data *cub, t_map *map, t_draw *draw, t_ply *player)
{
	draw->hit = 0;
	draw->side = 0;
	while (draw->hit == 0)
	{
		if (draw->sidedistx < draw->sidedisty)
		{
			draw->sidedistx += draw->deltadistx;
			draw->mapx += draw->stepx;
			draw->side = 0;
		}
		else
		{
			draw->sidedisty += draw->deltadisty;
			draw->mapy += draw->stepy;
			draw->side = 1;
		}
		if (map->map[draw->mapy][draw->mapx] == '1')
			draw->hit = 1;
	}
}

void	draw_step_side(t_data *data, t_draw *draw)
{
	draw->cos = cos(draw->angle * PI / 180);
	draw->sin = sin(draw->angle * PI / 180);
	draw->deltadistx = 1 / fabs(draw->cos);
	draw->deltadisty = 1 / fabs(draw->sin);
	draw->mapy = (int)data->ply->y;
	draw->mapx = (int)data->ply->x;
	draw->stepy = -1;
	if (draw->sin > 0)
		draw->sidedisty = (data->ply->y - draw->mapy) * draw->deltadisty;
	else
	{
		draw->stepy = 1;
		draw->sidedisty = (draw->mapy + 1 - data->ply->y) * draw->deltadisty;
	}
	draw->stepx = 1;
	if (draw->cos > 0)
		draw->sidedistx = (draw->mapx + 1 - data->ply->x) * draw->deltadistx;
	else
	{
		draw->stepx = -1;
		draw->sidedistx = (data->ply->x - draw->mapx) * draw->deltadistx;
	}
}

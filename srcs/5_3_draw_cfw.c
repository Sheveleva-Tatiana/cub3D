/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_3_draw_cfw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:32:44 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:33:56 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ceiling(t_data *cub, t_draw *draw)
{
	while (draw->y < draw->drawstart)
	{
		cub->img->data[draw->y * WIN_WIDTH + draw->x] = cub->map->c_color;
		draw->y++;
	}
}

void	flour(t_data *cub, t_draw *draw)
{
	while (draw->y < WIN_HEIGHT)
	{
		cub->img->data[draw->y * WIN_WIDTH + draw->x] = cub->map->f_color;
		draw->y++;
	}
}

void	walls(t_data *cub, t_map *map, t_draw *draw)
{
	while (draw->y < draw->drawend)
	{
		draw->texy = (int)draw->texpos & (map->tex->width - 1);
		draw->texpos += draw->step;
		if (draw->side == 1 && draw->mapy < cub->ply->y)
			draw->tn = 0;
		else if (draw->side == 1)
			draw->tn = 1;
		else if (draw->side == 0 && draw->mapx < cub->ply->x)
			draw->tn = 2;
		else
			draw->tn = 3;
		cub->img->data[draw->y * WIN_WIDTH + draw->x] = map->tex[draw->tn] \
				.data[draw->texy * map->tex->width + draw->texx];
		draw->y++;
	}
}

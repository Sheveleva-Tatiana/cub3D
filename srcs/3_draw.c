#include "../include/cub3d.h"

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

void	celing(t_data *cub, t_draw *draw)
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

static void	walls(t_data *cub, t_map *map, t_draw *draw)
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
		cub->img->data[draw->y * WIN_WIDTH + draw->x] = map->tex[draw->tn]
				.data[draw->texy * map->tex->width + draw->texx];
		draw->y++;
	}
}

void	draw2(t_data *data, t_draw *draw)
{
	draw->y = 0;
	celing(data, draw);
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

void draw(t_data *data)
{
	t_draw	draw;

	draw.angle_start = data->ply->angle + data->ply->fov / 2;
	draw.angle_end = data->ply->angle - data->ply->fov / 2;
	draw.angle_step = data->ply->fov / WIN_WIDTH;
	draw.angle = draw.angle_start;
	draw.x = 0;
	while(draw.angle > draw.angle_end)
	{
		draw_step_side(data, &draw);
		hit_wall(data, data->map, &draw, data->ply);
		height_wall(data, &draw);
		draw2(data, &draw);
		draw.angle -= draw.angle_step;
		draw.x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);

}
#include "../include/cub3d.h"

void	init_texture(int side, t_data *o)
{
	if (side)
	{
		if (o->ray_dir_y < 0)
			o->wall_side = WALL_SOUTH;
		else
			o->wall_side = WALL_NORTH;
	}
	else
	{
		if (o->ray_dir_x < 0)
			o->wall_side = WALL_EAST;
		else
			o->wall_side = WALL_WEST;
	}
}


void	init_delta(int x, t_data *data)
{
	data->camera_x = 2 * x / (double) WIN_WIDTH - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = data->ply->x;
	data->map_y = data->ply->y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 2147483647;
	else
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 2147483647;
	else
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
}

void	init_side(t_data *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (d->ply->x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->ply->x + 1.0 - d->map_x) * d->delta_dist_x;
	}
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->ply->y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->ply->y + 1.0 - d->map_y) * d->delta_dist_y;
	}
}

int		throw_ray(t_data *d)
{
	int hit;
	int side;

	hit = 0;
	while (hit == 0)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->map_x += d->step_x;
			side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			side = 1;
		}
		if (d->map->map[d->map_y][d->map_x] == '1')
			hit = 1;
	}
	return (side);
}

void	my_mlx_pixel_put(t_img *i, int x, int y, int color)
{
	char	*dst;

	dst = i->data + (y * i->line_length + x * (i->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void put_ceil(int x, int start, t_data *data)
{
	int	i;

	i = -1;
	while (++i < start)
		my_mlx_pixel_put(data->img, x, i, 0X00FFFF);
}
void	fill_floor(int x, int draw_end, t_data *o)
{
	int	i;

	i = draw_end;
	while (i < WIN_HEIGHT)
	{
		my_mlx_pixel_put(o->img, x, i, 0X2E8B57);
		i++;
	}
}

void	init_wall_x(int side, t_data *o)
{
	if (side)
		o->wall_x = o->ply->x + o->perp_wall_dist * o->ray_dir_x - o->map_x;
	else
		o->wall_x = o->ply->y + o->perp_wall_dist * o->ray_dir_y - o->map_y;
}

void	fill_walls(int x, int side, int line_height, t_data *o)
{
	int		y;
	int		color;
	double	step;
	double	tex_pos;

	init_wall_x(side, o);
	o->tex_x = o->wall_x * (double) o->tex_w;
	step = 1.0 * o->tex_h / line_height;
	tex_pos = (o->draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;
	y = o->draw_start;
	while (y < o->draw_end)
	{
		o->tex_y = (int)tex_pos & (o->tex_h - 1);
		tex_pos += step;
		if (o->wall_side == WALL_NORTH)
			color = 0XFFC0CB;
		else if (o->wall_side == WALL_SOUTH)
			color = 0XFF7F50;
		else if (o->wall_side == WALL_WEST)
			color = 0XD8BFD8;
		else if (o->wall_side == WALL_EAST)
			color = 0X8A2BE2;
		my_mlx_pixel_put(o->img, x, y, color);
		y++;
	}
}

void	fill_vertical(int x, int side, t_data *data)
{
	int line_height;

	if (x == WIN_WIDTH / 2)
		data->dist = data->perp_wall_dist;
	line_height = WIN_HEIGHT / data->perp_wall_dist;
	data->draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (data->draw_end >= WIN_HEIGHT)
		data->draw_end = WIN_HEIGHT - 1;
	init_texture(side, data);
	put_ceil(x, data->draw_start, data);
	fill_floor(x, data->draw_end, data);
	fill_walls(x, side, line_height, data);
}

void	draw_petr(t_data *data)
{
	int		x;
	int 	side;

	x = -1;
	while (++x < WIN_WIDTH) // движимся в цикле по каждому столбцу карты
	{
		init_delta(x, data);
		init_side(data);
		side = throw_ray(data);
		if (side == 0)
			data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
		else
			data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
		fill_vertical(x, side, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
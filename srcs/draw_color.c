#include "../include/cub3d.h"

void	draw_color(t_data *data)
{
	t_paint paint;

	mlx_clear_window(data->mlx, data->win);
	paint.start = data->ply->angle - 30;
	paint.end = data->ply->angle + 31;
	paint.step = 1;
	paint.angle = paint.start;
	paint.x = 0;
	double h = data->ply->angle - 30;
	while (h < data->ply->angle + 31) {
		double a = data->ply->x;
		double b = data->ply->y;
		while (a > 0 && b > 0 && data->map->map[(int) b][(int) a] != '1') {
			a += 0.1 * cos(h * PI / 180);
			b -= 0.1 * sin(h * PI / 180);
//			mlx_pixel_put(data->mlx, data->win, (a * 30), (b * 30),
//						  0x7FFFD4);
		}
		double delta_a = 1 / fabs(a);
		double delta_b = 1 / fabs(b);
		if (a > 0)
			a += delta_a;
		else
			a -= delta_a;
		if (b > 0)
			b += delta_b;
		else
			b -= delta_b;
		mlx_pixel_put(data->mlx, data->win, (a * 30), (b * 30),
						  0x7FFFD4);
		h += 1;
	}
}

void	get_value(t_data *data, t_paint *paint)
{
	paint->cos = cos(paint->angle * PI / 180);
	paint->sin = sin(paint->angle  * PI / 180);
	paint->dis_x_delta = 1 / fabs(paint->cos);
	paint->dis_y_delta = 1 / fabs(paint->sin);
	paint->map_y = (int)data->ply->y;
	paint->map_x = (int)data->ply->x;
	if (paint->sin > 0)
		paint->dis_y_side = (data->ply->y - paint->map_y) * paint->dis_y_delta;
	else
	{
		paint->step_y = 1;
		paint->dis_y_side = (paint->map_y + 1 - data->ply->y) *
							paint->dis_y_delta;
	}
	paint->step_x = 1;
	if (paint->cos > 0)
		paint->dis_x_side = (paint->map_x + 1 - data->ply->x) *
							paint->dis_x_delta;
	else
	{
		paint->step_x = -1;
		paint->dis_x_side = (data->ply->x - paint->map_x) * paint->dis_x_delta;
	}
}

//void	draw_color(t_data *data)
//{
//	t_paint paint;
//
//	mlx_clear_window(data->mlx, data->win);
//	paint.start = data->ply->angle - 30;
//	paint.end = data->ply->angle + 31;
//	paint.step = 1;
//	paint.angle = paint.start;
//	paint.x = 0;
//	while (paint.angle < data->ply->angle + 31) {
//		get_value(data, &paint);
//		mlx_pixel_put(data->mlx, data->win, (paint.cos * 30),
//					  (paint.sin * 30), 0x7FFFD4);
//		paint.angle += 1;
//	}
//
//}
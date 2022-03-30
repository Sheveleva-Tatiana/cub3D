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
			mlx_pixel_put(data->mlx, data->win, (a * 30), (b * 30),
						  0x7FFFD4);
			a += 0.1 * cos(h * PI / 180);
			b -= 0.1 * sin(h * PI / 180);
		}
		double delta_a = 1 / fabs(a);
		double delta_b = 1 / fabs(b);
		if (a > 0)
			a -= (1 - delta_a);
		else
			a += (data->ply->x - (int)a);
		if (b > 0)
			b += delta_b;
		else
			b += (data->ply->y - (int)b);
		mlx_pixel_put(data->mlx, data->win, (a * 30), (b * 30),
						  0x7FFFD4);
		h += 1;
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
#include "../include/cub3d.h"

void	get_step(t_data *data, t_paint *paint)
{
	paint->cos = cos(paint->angle * PI / 180);
	paint->sin =  sin(paint->angle * PI / 180);
	paint->delta_x = 1 / fabs(paint->cos);
	paint->delta_y = 1 / fabs(paint->sin);
	paint->map_x = (int)data->ply->x;
	paint->map_y = (int)data->ply->y;
	paint->step_y = -1;
	if (paint->sin > 0)
		paint->dis_y_side = (data->ply->y - paint->map_y) * paint->delta_y;
	else
	{
		paint->step_y = 1;
		paint->dis_y_side = (paint->map_y + 1 - data->ply->y) * paint->delta_y;
	}
	paint->step_x = 1;
	if (paint->cos > 0)
		paint->dis_x_side = (paint->map_x + 1 - data->ply->x) * paint->delta_x;
	else
	{
		paint->step_x = -1;
		paint->dis_x_side = (data->ply->x - paint->map_x) * paint->delta_x;
	}
}

void put_wall(t_data *data, t_paint *paint)
{

}

void	draw_wall(t_data *data)
{
	t_paint paint;

	paint.start = data->ply->angle + 30;
	paint.end = data->ply->angle - 30;
	paint.step = 60 / WIN_WIDTH;
	paint.angle = paint.start;
	paint.x = 0;
	while (paint.angle > paint.end)
	{
		get_step(data, &paint);
		paint.angle = paint.angle - paint.step;
		put_wall(data, &paint);
	}
}

void	draw(t_data *data)
{
	draw_wall(data);
}
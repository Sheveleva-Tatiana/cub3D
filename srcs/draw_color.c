#include "../include/cub3d.h"

void	draw_color(t_data *data)
{
	t_paint paint;

	paint.start = data->ply->angle + 30;
	paint.end = data->ply->angle - 30;
	paint.step = 60 / WIN_WIDTH;
	paint.angle = paint.start;
	paint.x = 0;
	while (paint.angle > paint.end)
	{

		paint.angle = paint.angle - paint.step;
		paint.x++;
	}
}
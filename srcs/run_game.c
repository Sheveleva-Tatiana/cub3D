#include "../include/cub3d.h"

void	ft_pixel_put(int y, int x, t_data *data, unsigned int color)
{
	int i = -1, j = 0;
	while (++i < 27)
	{
		j = -1;
		while (++j < 27)
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, (int)color);
	}
}


void	draw_map(t_data *data)
{
	int x, y = -1;
	double h;
	double a = data->ply->x, b = data->ply->y, angle;
	mlx_clear_window(data->mlx, data->win);
	while (++y < size_arr(data->map->map))
	{
		x = -1;
		while (++x < ft_strlen(data->map->map[y]))
		{
			if ((ft_strchr("1", data->map->map[y][x])))
				ft_pixel_put(y * 30, x * 30, data, 0x4B0082);
		}
	}
	mlx_pixel_put(data->mlx, data->win, x * 30, y * 30, 0x00FFFF);
	h = data->ply->angle - 30;
	while (h < data->ply->angle + 31)
	{
		a = data->ply->x;
		b = data->ply->y;
		while (a > 0 && b > 0 && data->map->map[(int) b][(int) a] != '1') {
			a += 0.1 * cos(h * PI / 180);
			b -= 0.1 * sin(h * PI / 180);
			mlx_pixel_put(data->mlx, data->win, (a * 30), (b * 30),
						  0x7FFFD4);
			}
		h += 1;
	}
}

int	render(t_data *data)
{
	if (data->active_key[53] == 1)
		clear_and_exit(data);
	get_coordinates(data);
	draw(data);
//	draw_map(data);
	return (0);
}

void	run_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = (int *)mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, &data->img.line_length,
											   &data->img.endian);
	game_hook(data);
	mlx_loop_hook(data->mlx, &render, data);
	mlx_loop(data->mlx);
}
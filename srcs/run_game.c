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

void	ft_pixel_ply(double y, double x, t_data *data, unsigned int color)
{
	mlx_pixel_put(data->mlx, data->win, x, y, (int)color);
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
	ft_pixel_ply(data->ply->y * 30, data->ply->x * 30, data, 0x00FFFF);
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

int	game_close(t_data *data)
{
	clear_and_exit(data);
	return (0);
}

static int	press_key(int key, t_data *data)
{
	data->active_key[key] = 1;
	return (0);
}

int	unpress_key(int key, t_data *data)
{
	data->active_key[key] = 0;
	return (0);
}

void	game_hook(t_data *data)
{
	mlx_hook(data->win, 17, 0, game_close, data);
	mlx_hook(data->win, 2, 1L << 0, press_key, data);
	mlx_hook(data->win, 3, 1L << 0, unpress_key, data);
}

void	player_up_down(double x, double y, t_data *data)
{
	if (data->active_key[13] == 1) {
		if (data->map->map[(int) data->ply->y][(int) (data->ply->x + x)] == '0')
			data->ply->x = data->ply->x + x;
		if (data->map->map[(int)(data->ply->y + y)][(int)data->ply->x] == '0')
			data->ply->y = data->ply->y + y;
	}
	else if (data->active_key[1] == 1)
	{
		if (data->map->map[(int) data->ply->y][(int) (data->ply->x - x)] == '0')
			data->ply->x = data->ply->x - x;
		if (data->map->map[(int)(data->ply->y - y)][(int)data->ply->x] == '0')
			data->ply->y = data->ply->y - y;
	}
}

void	player_left_right(double x, double y, t_data *data)
{
	int p_y;
	int p_x;

	p_y = (int)data->ply->y;
	p_x = (int)data->ply->x;
	if (data->active_key[124] == 1)
	{
		if (data->map->map[p_y][(int)(p_x - y)] == '0'
			&& data->map->map[(int)(p_y + x)][p_x] == '0')
		{
			data->ply->x = data->ply->x - y;
			data->ply->y = data->ply->y + x;
		}
	}
	else if (data->active_key[123] == 1)
	{
		if (data->map->map[p_y][(int)(p_x + y)] == '0'
			&& data->map->map[(int)(p_y - x)][p_x] == '0')
		{
			data->ply->x = data->ply->x + y;
			data->ply->y = data->ply->y - x;
		}
	}
}

void	player_rotate(t_data *data)
{
	if (data->active_key[0])
	{
		data->ply->angle = data->ply->angle + data->ply->rotate_k;
		if (data->ply->angle >= 360)
			data->ply->angle = 0;
		if (data->ply->angle <= -360)
			data->ply->angle = 0;
	}
	if (data->active_key[2])
	{
		data->ply->angle = data->ply->angle - data->ply->rotate_k;
		if (data->ply->angle >= 360)
			data->ply->angle = 0;
		if (data->ply->angle <= -360)
			data->ply->angle = 0;
	}
}

void	get_coordinates(t_data *data)
{
	double x;
	double y;

	x = data->ply->move_k * cos(data->ply->angle * PI / 180);
	y = -data->ply->move_k * sin(data->ply->angle * PI / 180);
	player_up_down(x, y, data);
	player_left_right(x, y, data);
	player_rotate(data);
}

int	render(t_data *data)
{
	if (data->active_key[53] == 1)
		clear_and_exit(data);
	get_coordinates(data);
	draw_map(data);
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
	draw_map(data);
	mlx_loop(data->mlx);
}
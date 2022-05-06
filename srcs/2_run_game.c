#include "../include/cub3d.h"

void	ft_pixel_put(int y, int x, t_data *data, unsigned int color)
{
	int i = -1, j = 0;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, (int)color);
	}
}

void	draw_map(t_data *data)
{
	int x, y = -1;
	double h;
	double a, b;
//	mlx_clear_window(data->mlx, data->win);
	while (++y < size_arr(data->map->map))
	{
		x = -1;
		while (++x < ft_strlen(data->map->map[y]))
		{
			if ((ft_strchr("1", data->map->map[y][x])))
				ft_pixel_put(y * 10, x * 10, data, 0x4B0082);
		}
	}
	mlx_pixel_put(data->mlx, data->win, x * 10, y * 10, 0x00FFFF);
	h = data->ply->angle -30;
	while (h < data->ply->angle + 30)
	{
		a = data->ply->x;
		b = data->ply->y;
		while (a > 0 && b > 0 && data->map->map[(int) b][(int) a] != '1') {
			mlx_pixel_put(data->mlx, data->win, (a * 10), (b * 10),
						  0x7FFFD4);
			a += 0.095 * cos(h * PI / 180);
			b -= 0.095 * sin(h * PI / 180);
		}
		mlx_pixel_put(data->mlx, data->win, (a * 10), (b * 10),
						  0x7FFFD4);
		h +=0.5;
	}
}

int	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	moving(data);
	draw(data);
	draw_map(data);
	return (0);
}

int	start_game(int keycode, t_data *data)
{
	if (keycode == 36)
	{
		mlx_destroy_image(data->mlx, data->img->img2);
		data->img->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
		data->img->data = mlx_get_data_addr(data->img->img, \
        &data->img->bits_per_pixel, &data->img->line_length,
											&data->img->endian);
		game_hook(data);
		mlx_loop_hook(data->mlx, &render, (void *) data);
	}
	if (keycode == 53)
		clear_and_exit(data);
}

int animation(t_data *data)
{
	int 	w, h;
	static int times;

	if (times % 30 == 0)
		data->img->img2 = mlx_xpm_file_to_image(data->mlx, "./tex/begin1"
														   ".xpm",&w, &h);
	if (times % 60 == 0)
		data->img->img2 = mlx_xpm_file_to_image(data->mlx, "./tex/begin2"
														   ".xpm",&w, &h);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img2, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, start_game, data);
	times++;
}

void	run_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	data->img = malloc(sizeof(t_img));
	load_image(data);
	mlx_hook(data->win, 17, 0, game_close, data);
	mlx_loop_hook(data->mlx, &animation, (void *) data);
	mlx_loop(data->mlx);
}
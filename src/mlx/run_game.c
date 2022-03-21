#include "../../include/cub3d.h"

void	ft_pixel_put(int y, int x, t_data *data, unsigned int color)
{
	int i = -1, j = 0;
	while (++i < 31)
	{
		j = -1;
		while (++j < 31)
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, (int)color);
	}
}

void	draw_map(t_data *data)
{
	int x, y = -1;

	while (++y < size_arr(data->map->map))
	{
		x = -1;
		while (++x < ft_strlen(data->map->map[y]))
		{
			if ((ft_strchr("1", data->map->map[y][x])))
				ft_pixel_put(y * 30, x * 30, data, 0xFFFFFF);
			else if ((ft_strchr("NSEW", data->map->map[y][x])))
				ft_pixel_put(y * 30, x * 30, data, 0xFF69B4);
		}
	}
}

void	run_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 640, 480, "cub3D");
	draw_map(data);
	mlx_loop(data->mlx);
}
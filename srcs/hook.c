#include "../include/cub3d.h"

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
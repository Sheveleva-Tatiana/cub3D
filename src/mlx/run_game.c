#include "../../include/cub3d.h"

void	run_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 640, 480, "cub3D");
	mlx_loop(data->mlx);
}
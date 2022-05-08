/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_draw_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:36:23 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 14:38:56 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_pixel_put(int y, int x, t_data *data, unsigned int color)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, (int)color);
	}
}

void	draw_minimap2(t_data *data, double a, double b, double h)
{
	while (h < data->ply->angle + 30)
	{
		a = data->ply->x;
		b = data->ply->y;
		while (a > 0 && b > 0 && data->map->map[(int) b][(int) a] != '1')
		{
			mlx_pixel_put(data->mlx, data->win, (a * 5), (b * 5), \
						0x7FFFD4);
			a += 0.095 * cos(h * PI / 180);
			b -= 0.095 * sin(h * PI / 180);
		}
		h += 0.5;
	}
}

void	draw_minimap(t_data *data)
{
	int		x;
	int		y;
	double	h;
	double	a;
	double	b;

	y = -1;
	while (++y < size_arr(data->map->map))
	{
		x = -1;
		while (++x < ft_strlen(data->map->map[y]))
		{
			if ((ft_strchr("1", data->map->map[y][x])))
				ft_pixel_put(y * 5, x * 5, data, 0x4B0082);
		}
	}
	h = data->ply->angle - 30;
	draw_minimap2(data, a, b, h);
}

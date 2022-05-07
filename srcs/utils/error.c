/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:33:23 by sshera            #+#    #+#             */
/*   Updated: 2022/05/07 19:33:33 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_error(int i)
{
	if (i == 1)
	{
		printf("Operation file corrupted");
		exit(1);
	}
}

void	print_error_and_exit(t_data *data, char *str)
{
	printf("%s\n", str);
	free_all(data);
	exit(1);
}

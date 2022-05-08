/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:33:39 by sshera            #+#    #+#             */
/*   Updated: 2022/05/08 16:00:11 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_subst(char *str, int s, int l, int flag)
{
	int		i;
	int		k;
	char	*res;

	if (ft_strle(str, '\0') < (s + l))
		l = ft_strle(str, '\0') - s;
	res = malloc((sizeof(char) * (l + 1)));
	k = 0;
	if (s >= 0 && (ft_strle((char *)str, '\0') > s))
	{
		i = s;
		while (str[i] && k < l)
			res[k++] = str[i++];
		res[k] = '\0';
		if (flag == 1)
			free(str);
		return (res);
	}
	res[k] = '\0';
	if (flag == 1)
		free(str);
	return (res);
}

void	clear_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int	ft_isdigit_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit(str[i])) == -1)
			return (0);
		i++;
	}
	return (1);
}

void	clear_and_exit(t_data *data)
{
	printf("GOOD BYE, MY FRIEND! I WILL MISS YOU!\n");
	free_all(data);
	exit(1);
}

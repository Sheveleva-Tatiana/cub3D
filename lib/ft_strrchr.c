/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:47:25 by sshera            #+#    #+#             */
/*   Updated: 2021/10/14 12:45:02 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;
	char	*str_new;

	i1 = 0;
	i2 = 0;
	i3 = 0;
	str_new = (char *)str;
	while (str_new[i1] != '\0')
	{
		if (str_new[i1] == (char) ch)
		{
			i2 = i1;
			i3++;
		}
		i1++;
	}
	if (ch == '\0')
		return (str_new + i1);
	if (i3 > 0)
		return (str_new + i2);
	return (0);
}

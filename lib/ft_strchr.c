/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:43:14 by sshera            #+#    #+#             */
/*   Updated: 2021/10/11 19:46:53 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	while (str2[i] != '\0')
	{
		if (str2[i] == (char) ch)
			return (str2 + i);
		i++;
	}
	if (ch == '\0')
		return (str2 + i);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:09:26 by sshera            #+#    #+#             */
/*   Updated: 2021/10/14 12:45:21 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *s, size_t n)
{
	size_t	i;
	size_t	n2;

	i = 0;
	while (s[i])
		i++;
	n2 = i;
	i = 0;
	if (n2 == 0)
		return ((char *)str);
	while (i < n && str[i] != '\0')
	{
		if (str[i] == s[0])
		{
			if (ft_strncmp(str + i, s, n2) == 0)
				if (i + n2 <= n)
					return ((char *)str + i);
		}
		i++;
	}
	return (0);
}

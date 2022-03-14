/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:59:27 by sshera            #+#    #+#             */
/*   Updated: 2021/10/11 20:04:04 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s1;
	while (n > 0)
	{
		if (*s2 == (unsigned char)c)
			return ((unsigned char *)s2);
		s2++;
		n--;
	}
	return (0);
}

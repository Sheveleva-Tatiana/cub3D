/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:04:51 by sshera            #+#    #+#             */
/*   Updated: 2021/10/11 20:09:10 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*n_s1;
	unsigned char	*n_s2;

	n_s1 = (unsigned char *)s1;
	n_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*n_s1 != *n_s2 || !n_s1 || !n_s2)
			return (*n_s1 - *n_s2);
		n_s1++;
		n_s2++;
	}
	return (0);
}

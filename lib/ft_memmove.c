/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:14:27 by sshera            #+#    #+#             */
/*   Updated: 2021/10/11 19:20:57 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *d, const void *source, size_t n)
{
	size_t	i;

	i = 0;
	if (source < d)
	{
		while (n-- > 0)
			*((unsigned char *)d + n) = *((unsigned char *)source + n);
		return (d);
	}
	if (source > d)
	{
		while (i < n)
		{
			*((unsigned char *)d + i) = *((unsigned char *)source + i);
			i++;
		}
		return (d);
	}
	return (d);
}

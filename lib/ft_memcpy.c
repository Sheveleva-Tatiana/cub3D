/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:10:44 by sshera            #+#    #+#             */
/*   Updated: 2021/10/11 19:21:56 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t	i;

	i = 0;
	if (destination == NULL && source == NULL)
		return (NULL);
	while (i < n)
	{
		*((unsigned char *)destination + i) = *((unsigned char *)source + i);
		i++;
	}
	return (destination);
}

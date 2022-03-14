/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:54:52 by sshera            #+#    #+#             */
/*   Updated: 2021/10/20 14:57:26 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	while (len-- > 0)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		if (*s1 != *s2)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}

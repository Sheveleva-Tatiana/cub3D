/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:03:14 by sshera            #+#    #+#             */
/*   Updated: 2021/10/20 16:25:35 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	k;
	char	*res;

	if (s == NULL)
		return (NULL);
	if ((ft_strlen(s) <= start) || start < 0)
		return (ft_strdup(""));
	if ((ft_strlen(s)) < (start + len))
		len = ft_strlen(s) - start;
	res = (char *)malloc((sizeof(char) * (len + 1)));
	if (!res)
		return (NULL);
	k = 0;
	if (start >= 0 && (ft_strlen((char *)s) > start))
	{
		i = start;
		while (s[i] && k < len)
			res[k++] = s[i++];
		res[k] = '\0';
		return (res);
	}
	res[k] = '\0';
	return (res);
}

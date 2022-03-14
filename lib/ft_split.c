/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:23:00 by sshera            #+#    #+#             */
/*   Updated: 2021/10/15 17:20:24 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_malloc(char **s, size_t count)
{
	while (count >= 0)
	{
		free(s[count]);
		count--;
	}
	free (s);
}

static size_t	str_leng(char const **s, char c)
{
	size_t	count;

	count = 0;
	while (**s != c && **s != '\0')
	{
		count++;
		(*s)++;
	}
	return (count);
}

static size_t	str_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	size_t	count;
	size_t	maxcounts;

	if (s == NULL)
		return (NULL);
	splits = malloc(sizeof(char *) * (str_count(s, c) + 1));
	if (splits == NULL)
		return (NULL);
	count = 0;
	maxcounts = str_count(s, c);
	while (*s != '\0' && count < maxcounts)
	{
		while (*s == c)
			s++;
		splits[count] = ft_substr(s, 0, str_leng(&s, c));
		if (splits[count] == NULL)
		{
			free_malloc(splits, count - 1);
			return (NULL);
		}
		count++;
	}
	splits[count] = NULL;
	return (splits);
}

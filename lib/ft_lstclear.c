/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:43:35 by sshera            #+#    #+#             */
/*   Updated: 2021/10/20 12:23:55 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	while (*lst)
	{
		new = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new;
	}
	*lst = NULL;
}

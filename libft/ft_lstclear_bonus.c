/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:20:27 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/14 17:52:40 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nodo;

	while (*lst)
	{
		nodo = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nodo;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:56:21 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/14 17:42:42 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*nodo;

	if (!lst || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		nodo = ft_lstnew(NULL);
		if (!nodo)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		nodo->content = f(lst->content);
		ft_lstadd_back(&newlst, nodo);
		lst = lst->next;
	}
	return (newlst);
}

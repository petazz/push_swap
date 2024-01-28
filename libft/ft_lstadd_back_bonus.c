/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:12:13 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/14 17:47:49 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*actual;

	if (!*lst)
		*lst = new;
	else
	{
		actual = *lst;
		while (actual->next != NULL)
			actual = actual->next;
		actual->next = new;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_A_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:15:07 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 19:42:28 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_node **head)
{
	int	aux;

	if (!*head)
		return ;
	aux = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = aux;
}

void	pa(t_node **dst, t_node **src)
{
	if (!*src || !*dst)
		return ;
	ft_push(dst, ft_pop(src));
}

void	ra(t_node **head)
{
	if (!*head)
		return ;
	*head = (*head)->next;
}

void	rra(t_node **head)
{
	if (!*head)
		return ;
	*head = (*head)->prev;
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rra(head_a);
	rrb(head_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_B_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:15:25 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:44 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_node **head)
{
	int	aux;

	if (!*head)
		return ;
	aux = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = aux;
}

void	pb(t_node **dst, t_node **src)
{
	if (!*src)
		return ;
	ft_push(dst, ft_pop(src));

}

void	rb(t_node **head)
{
	if (!*head)
		return ;
	*head = (*head)->next;
}

void	rrb(t_node **head)
{
	if (!*head)
		return ;
	*head = (*head)->prev;
}

void	rr(t_node **head_a, t_node **head_b)
{
	ra(head_a);
	rb(head_b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:11:06 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:30 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **head)
{
	int	aux;

	if (!head)
		return ;
	printf("sb\n");
	aux = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = aux;
}

void	pb(t_node **dst, t_node **src)
{
	if (!src)
		return ;
	ft_push(dst, ft_pop(src));
	printf("pb\n");
}

void	rb(t_node **head)
{
	if (!head)
		return ;
	printf("rb\n");
	*head = (*head)->next;
}

void	rrb(t_node **head)
{
	if (!head)
		return ;
	printf("rrb\n");
	*head = (*head)->prev;
}

void	rr(t_node **head_a, t_node **head_b)
{
	if (!head_a || !head_b)
		return ;
	printf("rr\n");
	*head_a = (*head_a)->next;
	*head_b = (*head_b)->next;
}

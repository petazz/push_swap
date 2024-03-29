/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:11:03 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:30 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head)
{
	int	aux;

	if (!head)
		return ;
	aux = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = aux;
	printf("sa\n");
}

void	pa(t_node **dst, t_node **src)
{
	if (!src)
		return ;
	ft_push(dst, ft_pop(src));
	printf("pa\n");
}

void	ra(t_node **head)
{
	if (!head)
		return ;
	printf("ra\n");
	*head = (*head)->next;
}

void	rra(t_node **head)
{
	if (!head)
		return ;
	printf("rra\n");
	*head = (*head)->prev;
}

void	rrr(t_node **head_a, t_node **head_b)
{
	if (!head_a || !head_b)
		return ;
	printf("rrr\n");
	*head_a = (*head_a)->prev;
	*head_b = (*head_b)->prev;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:20:14 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:30 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_besties(t_node *head_a, t_node *head_b, t_data *data)
{
	int	target;
	int	size;
	int	i;
	int	num;

	num = 0;
	i = 1;
	target = __INT_MAX__;
	size = ft_lst_len(head_a);
	while (i <= size)
	{
		num = head_a->n - head_b->n;
		if ((num < target) && (head_a->n > head_b->n))
		{
			target = num;
			data->bestie = head_a;
		}
		head_a = head_a->next;
		i++;
	}
	return (data->bestie->position);
}

int	ft_calculate_top(t_node **head)
{
	int	counter;
	int	num;

	counter = 0;
	num = ft_lst_len(*head) - (*head)->position;
	if (num + 1 > (*head)->position)
		counter = (*head)->position;
	else
		counter = (-1) * (num);
	return (counter);
}

void	ft_total_cost(t_node *head_b)
{
	int	num_bestie;
	int	num_node;

	num_bestie = head_b->cost_bestie;
	num_node = head_b->cost_node;
	if (num_bestie < 0)
		num_bestie = -num_bestie;
	if (num_node < 0)
		num_node = -num_node;
	head_b->total_cost = num_bestie + num_node;
}

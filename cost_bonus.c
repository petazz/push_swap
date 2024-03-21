/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:13:49 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:30 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cheapest_node(t_node *head_b, t_data *data)
{
	int	cheapest;
	int	i;
	int	size;

	i = 0;
	cheapest = head_b->total_cost;
	data->cheapest = head_b;
	size = ft_lst_len(head_b);
	while (i < size)
	{
		if (cheapest > head_b->total_cost)
		{
			cheapest = head_b->total_cost;
			data->cheapest = head_b;
		}
		head_b = head_b->next;
		i++;
	}
}

void	ft_move_node_top(t_node **cheapest, t_data *data)
{
	int	num;

	num = (*cheapest)->cost_node;
	if (num < 0)
	{
		while (num != 0)
		{
			rrb(&data->stack_b);
			num = num + 1;
		}
	}
	else if (num > 0)
	{
		while (num != 0)
		{
			rb(&data->stack_b);
			num = num - 1;
		}
	}
}

void	ft_move_bestie_top(t_node **bestie, t_data *data)
{
	int	num;

	num = (*bestie)->cost_bestie;
	if (num < 0)
	{
		while (num != 0)
		{
			rra(&data->stack_a);
			num = num + 1;
		}
	}
	else if (num > 0)
	{
		while (num != 0)
		{
			ra(&data->stack_a);
			num = num - 1;
		}
	}
}

void	ft_set_bestie(int position, t_node *head_a, t_data *data)
{
	int	i;

	i = 1;
	while (i <= position)
	{
		head_a = head_a->next;
		i++;
	}
	data->bestie = head_a;
}

void	ft_calculate_cost(t_node **head_a, t_node **head_b, t_data *data)
{
	int	i;

	i = 1;
	ft_positions(&data->stack_a);
	ft_positions(&data->stack_b);
	while (i <= ft_lst_len(*head_b))
	{
		(*head_b)->bestie_position = ft_besties(*head_a, *head_b, data);
		(*head_b)->cost_bestie = ft_calculate_top(&data->bestie);
		(*head_b)->cost_node = ft_calculate_top(head_b);
		ft_total_cost(*head_b);
		*head_b = (*head_b)->next;
		i++;
	}
	ft_cheapest_node(*head_b, data);
	ft_set_bestie(data->cheapest->bestie_position, *head_a, data);
	if (data->cheapest->position != 0)
		ft_move_node_top(&data->cheapest, data);
	data->bestie->cost_bestie = ft_calculate_top(&data->bestie);
	if (data->bestie->position != 0)
		ft_move_bestie_top(&data->bestie, data);
	pa(head_a, head_b);
}

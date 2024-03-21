/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:15:41 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 16:42:25 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_sorted(t_node *head)
{
	t_node	*aux;
	t_node	*last;

	aux = head;
	last = head->prev;
	while (head != last)
	{
		if (head->n > head->next->n)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_sort_3(t_node **head, t_data *data)
{
	if (((*head)->n > (*head)->next->n)
		&& ((*head)->next->n < (*head)->next->next->n)
		&& (*head)->n > (*head)->next->next->n)
		ra(&data->stack_a);
	else if (((*head)->n > (*head)->next->n)
		&& ((*head)->next->n > (*head)->next->next->n))
	{
		sa(&data->stack_a);
		rra(&data->stack_a);
	}
	else if (((*head)->n > (*head)->next->n)
		&& ((*head)->next->n < (*head)->next->next->n)
		&& (*head)->n < (*head)->next->next->n)
		sa(&data->stack_a);
	else if (((*head)->n < (*head)->next->n)
		&& ((*head)->next->n > (*head)->next->next->n)
		&& (*head)->n < (*head)->next->next->n)
	{
		sa(&data->stack_a);
		ra(&data->stack_a);
	}
	else if (((*head)->n < (*head)->next->n)
		&& ((*head)->next->n > (*head)->next->next->n)
		&& (*head)->n > (*head)->next->next->n)
		rra(&data->stack_a);
}

void	ft_sort(t_data *data)
{
	int	size_a;
	int	i;

	data->stack_b = NULL;
	if (!ft_is_sorted(data->stack_a))
	{
		i = 0;
		size_a = ft_lst_len(data->stack_a);
		if (data->len == 2)
			sa(&data->stack_a);
		if (data->len == 3)
			ft_sort_3(&data->stack_a, data);
		if (data->len > 3)
		{
			while (ft_lst_len(data->stack_a) > 3)
				ft_above_average(data, ft_average(data->stack_a));
			ft_sort_3(&data->stack_a, data);
			while (i < size_a - 3)
			{
				ft_calculate_cost(&data->stack_a, &data->stack_b, data);
				i++;
			}
		}
	}
}

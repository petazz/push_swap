/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:16:34 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 16:40:40 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 5);
	exit(EXIT_FAILURE);
}

long	ft_average(t_node *head)
{
	long	average;
	t_node	*aux;

	aux = head;
	average = 0;
	while (aux->next != head)
	{
		average += aux->n;
		aux = aux->next;
	}
	average += aux->n;
	average = average / (long)ft_lst_len(head);
	return (average);
}

void	ft_above_average(t_data *data, long average)
{
	if (data->stack_a->n <= average)
		pb(&data->stack_b, &data->stack_a);
	else
		ra(&data->stack_a);
}

int	ft_lst_len(t_node *head)
{
	int		i;
	t_node	*aux;

	aux = head;
	i = 1;
	if (!head)
		return (1);
	while (aux->next != head)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

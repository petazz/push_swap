/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:16:15 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:30 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**ft_free_split(char **matrix)
{
	int	t;

	t = 0;
	while (matrix[t])
	{
		free(matrix[t]);
		t++;
	}
	free(matrix);
	return (NULL);
}

void	ft_positions(t_node **head)
{
	int	i;

	i = 0;
	while (i < ft_lst_len(*head))
	{
		(*head)->position = i;
		*head = (*head)->next;
		i++;
	}
}

void	ft_min(t_node *head_a, t_data *data)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	ft_positions(&data->stack_a);
	while (i < ft_lst_len(head_a))
	{
		if (min > head_a->n)
		{
			min = head_a->n;
			data->position_min = head_a->position;
		}
		head_a = head_a->next;
		i++;
	}
}

int	ft_set_head(t_node **head_a, t_data *data)
{
	if (data->position_min < ft_lst_len(*head_a) / 2)
	{
		while (data->position_min != 0)
		{
			ra(&data->stack_a);
			data->position_min = data->position_min - 1;
		}
	}
	else
	{
		data->position_min = ft_lst_len(*head_a) - data->position_min;
		while (data->position_min != 0)
		{
			rra(&data->stack_a);
			data->position_min = data->position_min - 1;
		}
	}
	return (data->position_min);
}

void	ss(t_node **head_a, t_node **head_b)
{
	sa(head_a);
	sb(head_b);
}

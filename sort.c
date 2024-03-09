#include "prueba.h"

int	ft_isSort(t_node *head, t_data *data)
{
	t_node *aux;
	t_node *last;

	aux = head;
	last = head->prev;
	while(head != last)
	{
		if(head->n > head->next->n)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_positions(t_node **head)
{
	int i;

	i = 0;
	while(i < ft_lst_len(*head))
	{
		(*head)->position = i;
		*head = (*head)->next;
		i++;
	}
}

void	ft_sort_3(t_node **head, t_data *data)
{
	if(((*head)->n > (*head)->next->n) && ((*head)->next->n < (*head)->next->next->n) && (*head)->n > (*head)->next->next->n)
		ra(&data->stack_A);
	else if(((*head)->n > (*head)->next->n) && ((*head)->next->n > (*head)->next->next->n))
	{
		sa(&data->stack_A);
		rra(&data->stack_A);
	}
	else if(((*head)->n > (*head)->next->n) && ((*head)->next->n < (*head)->next->next->n) && (*head)->n < (*head)->next->next->n)
		sa(&data->stack_A);
	else if(((*head)->n < (*head)->next->n) && ((*head)->next->n > (*head)->next->next->n) && (*head)->n < (*head)->next->next->n)
	{
		sa(&data->stack_A);
		ra(&data->stack_A);
	}
	else if(((*head)->n < (*head)->next->n) && ((*head)->next->n > (*head)->next->next->n) && (*head)->n > (*head)->next->next->n)
		rra(&data->stack_A);
}

void	ft_sort(t_data *data)
{
	data->stack_B = NULL;

	if(!ft_isSort(data->stack_A, data))
	{
		int size_A;
		int i;

		i = 0;
		size_A = ft_lst_len(data->stack_A);
		if(data->len == 2)
			sa(&data->stack_A);
		if(data->len == 3)
			ft_sort_3(&data->stack_A, data);
		if(data->len > 3)
		{
			while(ft_lst_len(data->stack_A) > 3)
				ft_above_average(data, ft_average(data->stack_A, size_A));
			ft_sort_3(&data->stack_A, data);
			while(i < size_A - 3)
			{
				ft_calculate_cost(&data->stack_A, &data->stack_B, data);
				i++;
			}
		}
	}
}

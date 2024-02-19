#include "prueba.h"

int	ft_isSort(t_node *head, t_data *data)
{
	t_node *aux;

	aux = head;
	data->last = head->prev;
	while(head != data->last)
	{
		if(head->n > head->next->n)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_positions(t_node **head)
{
	t_node *ultimo;
	int i;

	i = 0;
	ultimo = (*head)->prev;
	while(*head != ultimo)
	{
		(*head)->position = i++;
		*head = (*head)->next;
	}
}

void	ft_sort_3(t_node **head, t_data *data)
{
	if(((*head)->n > (*head)->next->n) && ((*head)->next->n < (*head)->next->next->n))
		sx(&data->stack_A);
	if(((*head)->n > (*head)->next->n) && ((*head)->next->n > (*head)->next->next->n))
	{
		sx(&data->stack_A);
		rrx(&data->stack_A);
	}
	if(((*head)->n > (*head)->next->n) && ((*head)->next->n < (*head)->next->next->n))
		rx(&data->stack_A);
	if(((*head)->n < (*head)->next->n) && ((*head)->next->n > (*head)->next->next->n))
	{
		sx(&data->stack_A);
		rx(&data->stack_A);
	}
	if(((*head)->n < (*head)->next->n) && ((*head)->next->n > (*head)->next->next->n))
		rrx(&data->stack_A);
	for(int i = 0; i < 3; i++)
	{
		printf("ORDENADO:	%d\n", data->stack_A->n);
		data->stack_A = data->stack_A->next;
	}
}

int	ft_average(t_node *last, t_node *head, int size_A)
{
	int average;

	average = 0;
	while(head != last)
	{
		average += head->n;
		head = head->next;
	}
	average = average / size_A;
	return (average);
}

void	ft_above_average(t_data *data, int average)
{
	while(ft_lst_len(data) > 3)
	{
		printf("entra while\n");
		if(data->stack_A->n > average)
			px(&data->stack_B, &data->stack_A);
		else
			rx(&data->stack_A);
	}
}

int	ft_lst_len(t_data *data)
{
	int i;

	i = 0;
	while(data->stack_A != data->last)
	{
		printf("entra len\n");
		data->stack_A = data->stack_A->next;
		i++;
	}
	return (i);
}

void	ft_sort(t_data *data)
{
	data->stack_B = NULL;

	if(!ft_isSort(data->stack_A, data))
	{
		int size_A;

		size_A = ft_lst_len(data);
		if(data->len == 2)
			sx(&data->stack_A);
		if(data->len == 3)
			ft_sort_3(&data->stack_A, data);
		if(data->len > 3)
		{
			printf("entra\n");
			ft_above_average(data, ft_average(data->last, data->stack_A, size_A));
			for(int i = 0; i < data->len; i++)
			{
				printf("nodo iuygewouy:	%d\n", data->stack_A->n);
				data->stack_A = data->stack_A->next;
			}
		}
	}
} 
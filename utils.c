#include "push_swap.h"

void	ft_error()
{
	write(2, "Error\n", 5);
	exit(EXIT_FAILURE);
}

long	ft_average(t_node *head, int size_A)
{
	long average;
	t_node *aux;

	aux = head;
	average = 0;
	while(aux->next != head)
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
	if(data->stack_A->n <= average)
		pb(&data->stack_B, &data->stack_A);
	else
		ra(&data->stack_A);
}

int	ft_lst_len(t_node *head)
{
	int i;
	t_node *aux;

	aux = head;
	i = 1;
	if(!head)
		return (1);
	while(aux->next != head)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}
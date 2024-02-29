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

int	ft_average(t_node *head, int size_A)
{
	int average;
	t_node *aux;

	aux = head;
	average = 0;
	while(aux->next != head)
	{
		average += aux->n;
		aux = aux->next;
	}
	average += aux->n;
	printf("total sum:	%d\n", average);
	average = average / size_A;
	printf("average:	%d\n", average);
	return (average);
}

void	ft_above_average(t_data *data, int average)
{
	if(data->stack_A->n <= average)
	{
		printf("px a %d\n", data->stack_A->n);
		px(&data->stack_B, &data->stack_A);
	}
	else
	{
		printf("rx a %d\n", data->stack_A->n);
		rx(&data->stack_A);
	}
}

int	ft_lst_len(t_node *head)
{
	int i;
	t_node *aux;

	aux = head;
	i = 1;
	while(aux->next != head)
	{
		aux = aux->next;
		i++;
	}
	printf("len:	%d\n", i);
	return (i);
}

void	ft_sort(t_data *data)
{
	data->stack_B = NULL;

	if(!ft_isSort(data->stack_A, data))
	{
		int size_A;

		size_A = ft_lst_len(data->stack_A);
		if(data->len == 2)
			sx(&data->stack_A);
		if(data->len == 3)
			ft_sort_3(&data->stack_A, data);
		if(data->len > 3)
		{
			//ft_average(data->stack_A, size_A);
			while(ft_lst_len(data->stack_A) > 3)
			{
				ft_above_average(data, ft_average(data->stack_A, size_A));
				printf("entra en el while\n");
				printf("primer nodo:	%d\n", data->stack_B->n);
				printf("ultimo nodo:	%d\n", data->stack_B->prev->n);
				
				/* printf("primer nodo2:	%d\n", data->stack_B->n);
				printf("ultimo nodo2:	%d\n", data->stack_B->prev->n);
			 */
			}
			ft_sort_3(&data->stack_A, data);
			ft_besties(&data->stack_A, &data->stack_B);
			ft_besties(&data->stack_A, &data->stack_B);
				
			/* for(int i = 0; i < 10; i++)
			{
				printf("nodo B:	%d\n", data->stack_B->n);
				data->stack_B = data->stack_B->next;
			}
			for(int i = 0; i < 10; i++)
			{
				printf("nodo A:	%d\n", data->stack_A->n);
				data->stack_A = data->stack_A->next;
			} */
		}
	}
} 

//********************************************************************************//
void	ft_besties(t_node **head_A, t_node **head_B)
{
	int	target;
	int size;
	int	i;
	int	bestie;
	int num;

	num = 0;
	i = 1;
	target = __INT_MAX__;
	size = ft_lst_len(*head_A);
	while(i <= size)
	{
		
		num = (*head_A)->n - (*head_B)->n;
		if ((num < target) && ((*head_A)->n > (*head_B)->n))
		{
			target = num;
			bestie = (*head_A)->n;
		}
		*head_A = (*head_A)->next;
		i++;
	}

	printf("bestie: %i de %i\n", bestie, (*head_B)->n);
	//return ()
}
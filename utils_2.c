#include "prueba.h"

void	ft_min(t_node *head_A, t_data *data)
{
	int i;
	int min;

	i = 0;
	min = 0;
	while(i < ft_lst_len(head_A))
	{
		if(min > head_A->n)
		{
			min = head_A->n;
			data->positionMin = head_A->position;
		}
		head_A = head_A->next;
		i++;
	}
}

void	ft_set_head(t_node **head_A, t_data *data)
{
	if(data->positionMin < ft_lst_len(*head_A) / 2)
	{
		while(data->positionMin != 0)
		{
			ra(&data->stack_A);
			data->positionMin = data->positionMin - 1;
		} 
	}
	else
	{
		data->positionMin = ft_lst_len(*head_A) - data->positionMin;
		while(data->positionMin != 0)
		{
			rra(&data->stack_A);
			data->positionMin = data->positionMin - 1;
		}
	}
}
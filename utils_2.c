#include "push_swap.h"

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
	int i;

	i = 0;
	while(i < ft_lst_len(*head))
	{
		(*head)->position = i;
		*head = (*head)->next;
		i++;
	}
}

void	ft_min(t_node *head_A, t_data *data)
{
	int i;
	int min;

	i = 0;
	min = INT_MAX;
	ft_positions(&data->stack_A);
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
	//printf("ft_min: %d\n", min);
}
                                                                                             
int	ft_set_head(t_node **head_A, t_data *data)
{
	// printf("data->position: %d", data->positionMin);

	if(data->positionMin < ft_lst_len(*head_A) / 2)
	{
		// printf("data->position: %d", data->positionMin);
		while(data->positionMin != 0)
		{
			//printf("data->position: %d", data->positionMin);
			ra(&data->stack_A);
			data->positionMin = data->positionMin - 1;
			//printf("data->position: %d", data->positionMin);
		} 
	}
	else
	{
		// printf("data->position: %d", data->positionMin);
		data->positionMin = ft_lst_len(*head_A) - data->positionMin;
		while(data->positionMin != 0)
		{
			rra(&data->stack_A);
			data->positionMin = data->positionMin - 1;
			//printf("data->position: %d", data->positionMin);
		}
	}
	return (data->positionMin);
}
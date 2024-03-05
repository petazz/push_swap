#include "prueba.h"

int	ft_besties(t_node *head_A, t_node *head_B, t_data *data)
{
	int	target;
	int size;
	int	i;
	int num;

	num = 0;
	i = 1;
	target = __INT_MAX__;
	size = ft_lst_len(head_A);
	while(i <= size)
	{
		
		num = head_A->n - head_B->n;
		if ((num < target) && (head_A->n > head_B->n))
		{
			target = num;
			data->bestie = head_A;
		}
		head_A = head_A->next;
		i++;
	}
	//if (target == __INT_MAX__)
	//	return;	//ft_error;
	return (data->bestie->position);
}

 
int	ft_calculate_top(t_node **head)
{
	int counter;
	int	num;

	counter = 0;
	num = ft_lst_len(*head) - (*head)->position; 
	if(num + 1 > (*head)->position)
		counter = (*head)->position;
	else
		counter = (-1) * (num);
/* 	
	if(head->position <= (ft_lst_len(head) / 2))
		counter = head->position;
	else if (head->position > ft_lst_len(head) / 2)
		counter = ft_lst_len(head) - head->position;
*/
	return (counter);
}

void	ft_total_cost(t_node *head_B)
{
	int num_bestie;
	int num_node;

	num_bestie = head_B->cost_bestie;
	num_node = head_B->cost_node;
	if(num_bestie < 0)
		num_bestie = -num_bestie;
	if(num_node < 0)
		num_node = -num_node;
	head_B->total_cost = num_bestie + num_node;
}

void	ft_cheapest_node(t_node *head_B, t_data *data)
{
	int cheapest;
	int i;
	int size;

	i = 0;
	cheapest = head_B->total_cost;
	data->cheapest = head_B;
	size = ft_lst_len(head_B);
	while(i < size)
	{
		if(cheapest > head_B->total_cost)
		{
			cheapest = head_B->total_cost;
			data->cheapest = head_B;
		}
		head_B = head_B->next;
		i++;
	}
}

void	ft_move_node_top(t_node **cheapest)
{
	if((*cheapest)->cost_node < 0)
	{
		while((*cheapest)->cost_node != 0)
		{
			rrx(cheapest);
			(*cheapest)->cost_node = (*cheapest)->cost_node + 1;
		}
	}
	else if ((*cheapest)->cost_node > 0)
	{
		while((*cheapest)->cost_node != 0)
		{
			rx(cheapest);
			(*cheapest)->cost_node = (*cheapest)->cost_node - 1;
		}
	}
}

void	ft_set_bestie(int position, t_node *head_A, t_data *data)
{
	int i;

	i = 0;
	while(i <= position)
	{
		head_A = head_A->next;
		i++;
	}
	data->bestie = head_A;
}
 
void	ft_calculate_cost(t_node **head_A, t_node **head_B, t_data *data)
{
	int	i;

	i = 1;
	ft_positions(&data->stack_A);
	ft_positions(&data->stack_B);


	while(i <= ft_lst_len(*head_B))
	{	
		(*head_B)->bestie_position = ft_besties(*head_A, *head_B, data);
		(*head_B)->cost_bestie = ft_calculate_top(&data->bestie);
		(*head_B)->cost_node = ft_calculate_top(head_B);
		ft_total_cost(*head_B);
		printf("node: %i ; posicion bestie: %i ; coste bestie: %i ; coste node: %i ; total: %i ; posicion: %i\n", (*head_B)->n, (*head_B)->bestie_position, (*head_B)->cost_bestie, (*head_B)->cost_node, (*head_B)->total_cost, (*head_B)->position);
		*head_B = (*head_B)->next;
		i++;
	}
	ft_cheapest_node(*head_B, data);
	ft_set_bestie(data->cheapest->bestie_position, *head_A, data);
	printf("el nodo mas barato es: %i\n", data->cheapest->n);
	if(data->cheapest->position != 0)
		ft_move_node_top(&data->cheapest);
	if(data->cheapest->position != 0)
		ft_move_node_top(&data->bestie);
	px(head_A, head_B);
for(int i = 0; i < 10;i++)
			{
				//printf("node: %i ; bestie: %i ; coste bestie: %i ; coste node: %i ; total: %i ; posicion: %i\n", head_B->n, data->bestie->n, head_B->cost_bestie, head_B->cost_node, head_B->total_cost, head_B->position);
				printf("node BBBBB: %i\n ", (*head_B)->n);
				*head_B = (*head_B)->next;
			} 
	for(int i = 0; i < 13;i++)
	{
		printf("node AAAA: %i\n ", (*head_A)->n);
		*head_A = (*head_A)->next;
	} 
}
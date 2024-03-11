#include "push_swap.h"

void	sa(t_node **head)
{
	int aux;

	if (!head)
		return;
	aux = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = aux;
	printf("sa\n");
}

void	pa(t_node **dst, t_node **src)
{
	ft_push(dst, ft_pop(src));
	printf("pa\n");
}

void	ra(t_node **head)
{
	printf("ra\n");
	*head = (*head)->next;
}

void	rra(t_node **head)
{
	printf("rra\n");
	*head = (*head)->prev;
}

void	rrr(t_node **head_A, t_node **head_B)
{
	printf("rrr\n");
	*head_A = (*head_A)->prev;
	*head_B = (*head_B)->prev;
}

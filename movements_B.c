#include "push_swap.h"

void	sb(t_node **head)
{
	printf("sb\n");
	int aux;

	if (!head)
		return;
	aux = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = aux;
}

void	pb(t_node **dst, t_node **src)
{
	ft_push(dst, ft_pop(src));
	printf("pb\n");
}

void	rb(t_node **head)
{
	printf("rb\n");
	*head = (*head)->next;
}

void	rrb(t_node **head)
{
	printf("rrb\n");
	*head = (*head)->prev;
}

void	rr(t_node **head_A, t_node **head_B)
{
	printf("rr\n");
	*head_A = (*head_A)->next;
	*head_B = (*head_B)->next;
}
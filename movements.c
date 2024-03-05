#include "prueba.h"

void	sx(t_node **head)
{
	int aux;

	if (!head)
		return;
	aux = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = aux;
}

void	px(t_node **dst, t_node **src)
{
	ft_push(dst, ft_pop(src));
	printf("px\n");
}

void	rx(t_node **head)
{
	*head = (*head)->next;
	printf("rx\n");
}

void	rrx(t_node **head)
{
	*head = (*head)->prev;
	printf("rrx\n");
}

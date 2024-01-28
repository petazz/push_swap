#include "prueba.h"

void	sa(t_node *head)
{
	int aux;

	aux = head->n;
	head->n = head->next->n;
	head->next->n = aux;
}
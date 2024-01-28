#include "prueba.h"

t_node *newNode(int n)
{
	t_node *node = malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
    node->prev = NULL;
	return node;
}

t_node *listGenerator(int *arr, int len)
{
	t_node *node;
	t_node *aux;
	t_node *head;
	int		i;

	i = 1;
	if (len >= 1)
		node = newNode(arr[0]);
	head = node;
	aux = head;
	while(i < len)
	{
		node = newNode(arr[i]);
		aux->next = node;
		node->prev = aux;
		aux = node;
		i++;
	}
	head->prev = node;
	node->next = head;
	return (head);
} 
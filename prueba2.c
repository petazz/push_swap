#include "prueba.h"

t_node *newNode(int n)
{
	t_node *nodo = malloc(sizeof(t_node));
	nodo->n = n;
	return nodo;
}

t_node *generarLista(int *n, int len)
{
	int i = 0;
	t_node *head;
	t_node *aux;
	t_node *node;
	
	
	if(len >= 1)
		head = newNode(n[0]);
	aux = head;
	while(i < len)
	{
		node = newNode(n[i]);
		aux->next = node;
		prev->node = aux;
		aux = node;
		i++;
	}
}

int main(void)
{
	int stack[5] = {1,2,3,4,5};

}
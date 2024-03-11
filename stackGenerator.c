#include "push_swap.h"

t_node *listGenerator(int *arr, int len)
{
	t_node *head;
	int		i;

	if (len < 1)
		return NULL;
	head = NULL;
	i = len - 1;
	while(i >= 0)
	{
		ft_push(&head, arr[i]);
		i--;
	}
	return (head);
} 

static t_node *newNode(int n)
{
	t_node *node = malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
    node->prev = NULL;
	return node;
}

void	ft_push(t_node **head, int n)
{
	t_node *top;

	top = newNode(n);
	if(!(*head))
	{
		top->next = top;
		top->prev = top;
	}
	else
	{
		top->next = (*head);
		top->prev = (*head)->prev;
		(*head)->prev->next = top;
		(*head)->prev = top;
	}
	(*head) = top; 
}

int	ft_pop(t_node **head)
{
	int n;
	t_node *aux;

	if(!head)
		exit(EXIT_FAILURE);
	n = (*head)->n;
	aux = *head; 
	if((*head)->prev == (*head))
	{
		free(*head);
		(*head) = NULL;
	}
	else
	{
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		(*head) = (*head)->next;
		free(aux);
	}
	return (n);
}

void	ft_free_stack(t_node **stack)
{
	int size;

	size = ft_lst_len(*stack);
	while(size)
	{
		ft_pop(stack);
		size--;
	}
}
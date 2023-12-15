#include "prueba.h"
#include "libft.h"

t_node *newNode(int n)
{
	t_node *node = malloc(sizeof(t_node));
	node->n = n;
	return node;
}

t_node *listGenerator(int *n, int len)
{
	t_node *node;
	t_node *aux;
	t_node *head;

	if (len >= 1)
		head = newNode(n[0]);
	aux = head;
	for (int i = 1; i < len; i++)
	{
		node = newNode(n[i]);
		aux->next = node;
		node->prev = aux;
		aux = node;
	}
	head->prev = node;
	node->next = head;
	return (head);
} 

int		ft_is_valid(char *str)
{
	unsigned long num;
	int sign;
	int i;

	i = 0;
	sign = 1;
	num = 0;
	if(str == NULL || !str[i])
		return (0);
	while(str[i] == '-')
		{
			sign = -1;
			i++;
		}
	while(str[i] && num < 2147483648)
	{
		if(str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	if((sign == 1 && num > 2147483648) || (sign == -1 && num > 2147483648))
		return (0);
	return (1);
}


int	ft_comprobation(char **argv, int argc)
{
	int num;
	int c;

	c = 1;
	num = 0;
	while(c < argc)
	{
		if(!ft_is_valid(argv[c]))
			return (0);
		ft_atoi(argv[c]);
		c++;
	}
	return (1);
}

int ft_count_numbers(char **argv)
{	
	int i;
	
	i = 0;
	while(argv[i] != NULL)
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if(argc == 1 || (argv[1][0] == '\0'))
		return 1;
	else if (argc == 2 && ft_strchr(argv[1], ' '))
		{
			argv = ft_split(argv[1], ' ');
			argc = ft_count_numbers(argv);
		}	
	if (ft_comprobation(argv, argc) == 0)
		return (0, printf("ERROR"));
		
	
	
	
	
	
	
	//int stack[5] = {1,2,3,4,5};
	/* t_node *primerNodo = listGenerator(argv, argc); */

	/* for(int i = 0; i < 5; i++)
	{
		printf("%d\n", primerNodo->n);
		primerNodo = primerNodo->next;
	} */
}
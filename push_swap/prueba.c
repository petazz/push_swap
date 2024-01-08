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



int main(int argc, char **argv)
{
	if(argc == 1 || (argv[1][0] == '\0'))		//si no entran numeros o un string vacio 
		return (0);
	else if (argc == 2 && ft_strchr(argv[1], ' '))		//comprobamos si entran entre comillas
		{
			argv = ft_split(argv[1], ' ');				//separamos los numeros por espacios y los guardamos a argv
			argc = ft_count_numbers(argv);				//contamos la cantidad de numeros introducidos
		}	
	if (ft_comprobation(argv, argc) == 0 && ft_repeat(argv, argc) == 0)				//comprobamos que el numero esta dentro del rango de int y lo convertimos a numero
		return (0, printf("ERROR"));
	
	
	//int stack[5] = {1,2,3,4,5};
	t_node *primerNodo = listGenerator(argv, argc);		//generamos el stack

	/*for(int i = 0; i < 5; i++)
	{
		printf("%d\n", primerNodo->n);
		primerNodo = primerNodo->next;
	}*/
}


for(int i = 0; i < 5; i++)
{
    if (primerNodo == NULL) {
        printf("Node is null\n");
        break;
    }
    printf("%d\n", primerNodo->n);
    primerNodo = primerNodo->next;
}
#include "prueba.h"

int main(int argc, char **argv)
{
	t_data data;

	if(argc == 1)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(EXIT_FAILURE);
	}
	data.arr = NULL;
	data.len = 0;
	init_stack(argv + 1, &data, argc);
	ft_sort(&data);
	/*  for(int i = 0; i < data.len; i++)
	{
		printf("nodo :	%d\n", data.stack_B->n);
		data.stack_B = data.stack_B->next;
	} */ 
}


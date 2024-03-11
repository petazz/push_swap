#include "push_swap.h"us


// void leaks() {
// 	system("leaks push_swap");
// }

int main(int argc, char **argv)
{
	t_data data;

	if(argc == 1 || (argc == 2 && !argv[1][0]))
		ft_error();
	//atexit(leaks);
	data.arr = NULL;
	data.len = 0;
	init_stack(argv + 1, &data, argc);
	ft_sort(&data);
	ft_min(data.stack_A, &data);
	ft_set_head(&data.stack_A, &data); 
	ft_free_stack(&data.stack_A);
}


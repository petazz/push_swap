#include "push_swap.h"

void	ft_KO()
{
	write(2, "KO\n", 3);

}

int main(int argc, char **argv)
{
	t_data data;
	char *str;
	if(argc == 1)
		return (0);
	data.arr = NULL;
	data.len = 0;
	init_stack(argv + 1, &data, argc);
	// while((str = get_next_line(STDIN_FILENO)) != NULL)
	// {
	// 	if(!ft_strncmp(str, "sa\n", 3) && data.stack_A)
	// 		sa(&data.stack_A);
	// 	else if(!ft_strncmp(str, "ra\n", 3) && data.stack_A)
	// 		ra(&data.stack_A);
	// 	else if(!ft_strncmp(str, "pa\n", 3) && data.stack_B)
	// 		pa(&data.stack_A, &data.stack_B);
	// 	else if(!ft_strncmp(str, "rra\n", 4) && data.stack_A)
	// 		rra(&data.stack_A);
	// 	else if(!ft_strncmp(str, "sb\n", 3) && data.stack_B)
	// 		sb(&data.stack_B);
	// 	else if(!ft_strncmp(str, "rb\n", 3) && data.stack_B)
	// 		rb(&data.stack_B);
	// 	else if(!ft_strncmp(str, "pb\n", 3) && data.stack_A)
	// 		pb(&data.stack_B, &data.stack_A);
	// 	else if(!ft_strncmp(str, "rrb\n", 4) && data.stack_B)
	// 		rrb(&data.stack_B);	
	// 	else if(!ft_strncmp(str, "rr\n", 3) && (data.stack_B && data.stack_A))
	// 		rr(&data.stack_A, &data.stack_B);
	// 	else if(!ft_strncmp(str, "rrr\n", 4) && (data.stack_B && data.stack_A))
	// 		rrr(&data.stack_A, &data.stack_B);
	// 	else
	// 	{
	// 		ft_error();	
	// 	}
	// 	free(str);
	// }
		while((str = get_next_line(STDIN_FILENO)) != NULL)
	{
		if(!ft_strncmp(str, "sa\n", 3))
		{
			if(data.stack_A)
				sa(&data.stack_A);
			else
			
		}
		else if(!ft_strncmp(str, "ra\n", 3))
			ra(&data.stack_A);
		else if(!ft_strncmp(str, "pa\n", 3) && ft_save(&data.stack_A, &data.stack_B))
			pa(&data.stack_A, &data.stack_B);
		else if(!ft_strncmp(str, "rra\n", 4))
			rra(&data.stack_A);
		else if(!ft_strncmp(str, "sb\n", 3) && data.stack_B)
			sb(&data.stack_B);
		else if(!ft_strncmp(str, "rb\n", 3) && data.stack_B)
			rb(&data.stack_B);
		else if(!ft_strncmp(str, "pb\n", 3) && data.stack_A)
			pb(&data.stack_B, &data.stack_A);
		else if(!ft_strncmp(str, "rrb\n", 4) && data.stack_B)
			rrb(&data.stack_B);	
		else if(!ft_strncmp(str, "rr\n", 3) && (data.stack_B && data.stack_A))
			rr(&data.stack_A, &data.stack_B);
		else if(!ft_strncmp(str, "rrr\n", 4) && (data.stack_B && data.stack_A))
			rrr(&data.stack_A, &data.stack_B);
		else
		{
			ft_error();	
		}
		free(str);
	}
	if(ft_isSort(data.stack_A, &data) && ft_lst_len(data.stack_B) == 1)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	ft_free_stack(&data.stack_A);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:13:11 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 20:16:27 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_while(char *str, t_data *data)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(&data->stack_a);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(&data->stack_a);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(&data->stack_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(&data->stack_b);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(&data->stack_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(&data->stack_b, &data->stack_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(&data->stack_b);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(&data->stack_a, &data->stack_b);
	else
		ft_error();
}

void	ft_move(t_data *data)
{
	char	*str;
	
	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		ft_while(str, data);
		str = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc == 1)
		return (0);
	data.arr = NULL;
	data.len = 0;
	init_stack(argv + 1, &data, argc);
	i = ft_lst_len(data.stack_a);
	ft_move(&data);
	if (ft_is_sorted(data.stack_a) && ft_lst_len(data.stack_a) == i)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	ft_free_stack(&data.stack_a);
}

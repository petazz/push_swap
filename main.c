/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:10:57 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 16:24:50 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_error();
	data.arr = NULL;
	data.len = 0;
	init_stack(argv + 1, &data, argc);
	ft_sort(&data);
	ft_min(data.stack_a, &data);
	ft_set_head(&data.stack_a, &data);
	ft_free_stack(&data.stack_a);
}

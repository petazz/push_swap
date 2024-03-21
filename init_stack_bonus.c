/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:14:23 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 16:25:02 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_valid(char *str)
{
	unsigned long	num;
	int				sign;
	int				i;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		i++;
	}
	while (str[i] && num < 2147483648)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	if ((sign == 1 && num > 2147483648) || (sign == -1 && num > 2147483648))
		return (0);
	return (1);
}

int	ft_repeat(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init_stack(char **argv, t_data *data, int argc)
{
	char	*str;
	int		i;

	i = 0;
	data->stack_b = NULL;
	data->arr = malloc(ft_strlen_ps(argv) * sizeof(int));
	if (!data->arr)
		ft_error();
	str = ft_strjoin_ps(argv, argc);
	argv = ft_split(str, ' ');
	free(str);
	while (argv[i])
	{
		if (!ft_valid(argv[i]))
			ft_error();
		data->arr[i] = ft_atoi(argv[i]);
		i++;
	}
	ft_free_split(argv);
	data->len = i;
	if (!ft_repeat(data->arr, data->len))
		ft_error();
	data->stack_a = list_generator(data->arr, data->len);
	free(data->arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:10:51 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 15:40:03 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_ps(char **argv)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			j++;
			num++;
		}
		i++;
	}
	return (num);
}

char	*ft_strjoin_ps(char **argv, int argc)
{
	int		i;
	int		j;
	int		s;
	char	*str;

	i = 0;
	s = 0;
	str = malloc((ft_strlen_ps(argv) + argc));
	if (!str)
		return (NULL);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			str[s] = argv[i][j];
			s++;
			j++;
		}
		str[s++] = ' ';
		i++;
	}
	str[s] = '\0';
	return (str);
}

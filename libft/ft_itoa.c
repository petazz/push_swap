/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:50:48 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/15 19:03:38 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(long number)
{
	int	len;

	len = 1;
	if (number < 0)
	{
		number *= -1;
		len++;
	}
	while (number > 9)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	number;
	char	*str;
	int		len;

	number = (long)n;
	len = ft_len(number);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	while (number > 9)
	{
		str[--len] = (number % 10) + '0';
		number = number / 10;
	}
	if (number > 0)
		str[--len] = number + '0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:37:05 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/15 17:37:05 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		inicio;
	int		final;
	char	*str;

	i = 0;
	inicio = 0;
	final = ft_strlen(s1);
	while (s1[inicio] && ft_strchr(set, s1[inicio]))
		inicio++;
	while (final > inicio && ft_strchr(set, s1[final - 1]))
		final--;
	str = malloc(sizeof(char) * (final - inicio + 1));
	if (!str)
		return (0);
	while (inicio < final)
	{
		str[i] = s1[inicio];
		i++;
		inicio++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:03:11 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/15 19:09:18 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size_nd;
	char	*hs;
	char	*nd;

	hs = (char *)haystack;
	nd = (char *)needle;
	size_nd = ft_strlen(nd);
	i = 0;
	if (size_nd == 0 || haystack == needle)
		return (hs);
	while (i < len && hs[i] != '\0')
	{
		j = 0;
		while (hs[i + j] != '\0' && nd[j] != '\0' && i + j < len
			&& hs[i + j] == nd[j])
		{
			j++;
			if (j == size_nd)
				return (hs + i);
		}
		i++;
	}
	return (0);
}

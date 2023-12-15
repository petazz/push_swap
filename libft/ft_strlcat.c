/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:58:39 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/14 18:00:52 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;
	size_t	res;
	char	*s;

	i = 0;
	s = (char *)src;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(s);
	if (lendst >= dstsize)
		res = dstsize + lensrc;
	else
		res = lensrc + lendst;
	while (s[i] && (lendst + 1) < dstsize)
	{
		dst[lendst] = s[i];
		lendst++;
		i++;
	}
	dst[lendst] = '\0';
	return (res);
}

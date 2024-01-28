/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:08:06 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/14 18:00:59 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	j;

	srcsize = ft_strlen(src);
	j = 0;
	if (dstsize < 1)
		return (srcsize);
	while (src[j] && j + 1 < dstsize)
	{
		dst[j] = src[j];
		j++;
	}
	if (j < dstsize)
		dst[j] = '\0';
	return (srcsize);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:34:07 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/14 17:57:59 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d == 0 && s == 0)
		return (0);
	if (s > d)
		ft_memcpy(dest, src, len);
	else
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	return (dest);
}

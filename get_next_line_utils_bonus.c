/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:58:37 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/11 12:03:01 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen_gnl(char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strdup_gnl(char *s1)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = ft_strlen_gnl(s1) + 1;
	p = malloc(sizeof(char) * len);
	i = -1;
	if (!p)
		return (0);
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = ft_strdup_gnl("");
		if (!s1)
			return (0);
	}
	str = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!str)
		return (ft_free_gnl(s1));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen_gnl(s))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (ft_strlen_gnl(s) - start < len)
		len = ft_strlen_gnl(s) - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (start < ft_strlen_gnl(s) && i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

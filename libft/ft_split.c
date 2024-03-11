/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:06:15 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/09 19:37:04 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	wordcount;
	int	i;

	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			wordcount++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (wordcount);
}

static int	size_word(char const *s, int i, char c)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static char	**ft_free(char **matrix)
{
	int	t;

	t = 0;
	while (matrix[t])
	{
		free(matrix[t]);
		t++;
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		wordcounts;
	int		size;
	char	**matrix;

	wordcounts = wordcount(s, c);
	j = -1;
	i = 0;
	matrix = malloc(sizeof(char *) * (wordcounts + 1));
	if (!matrix)
		return (NULL);
	while (++j < wordcounts)
	{
		while (s[i] == c)
			i++;
		size = size_word(s, i, c);
		matrix[j] = ft_substr(s, i, size);
		if (!matrix[j])
			return (ft_free(matrix));
		i = i + size;
	}
	matrix[j] = NULL;
	return (matrix);
}

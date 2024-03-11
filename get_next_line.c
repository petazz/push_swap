/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:00:07 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/11 12:04:24 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_free_gnl(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*ft_read(int fd, char *estatic)
{
	int		nbytes;
	char	*buffer;

	nbytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_gnl(estatic));
	buffer[0] = '\0';
	while (nbytes > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		nbytes = read (fd, buffer, BUFFER_SIZE);
		if (nbytes > 0)
		{
			buffer[nbytes] = '\0';
			estatic = ft_strjoin_gnl(estatic, buffer);
		}
	}
	free(buffer);
	if (nbytes == -1)
		return (ft_free_gnl(estatic));
	return (estatic);
}

char	*ft_get_line(char *estatic)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(estatic, '\n');
	len = (ptr - estatic) + 1;
	line = ft_substr_gnl(estatic, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_new_estatic(char *estatic)
{
	char	*new_estatic;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(estatic, '\n');
	if (!ptr)
	{
		new_estatic = NULL;
		return (ft_free_gnl(estatic));
	}
	else
		len = (ptr - estatic) + 1;
	if (!estatic[len])
		return (ft_free_gnl(estatic));
	new_estatic = ft_substr_gnl(estatic, len, ft_strlen_gnl(estatic) - len);
	ft_free_gnl(estatic);
	if (!new_estatic)
		return (NULL);
	return (new_estatic);
}

char	*get_next_line(int fd)
{
	static char	*estatic;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_gnl(estatic));
	estatic = ft_read (fd, estatic);
	if (!estatic)
		return (NULL);
	line = ft_get_line(estatic);
	if (!line)
		return (ft_free_gnl(estatic));
	estatic = ft_new_estatic(estatic);
	return (line);
}
/* int main(void) 
{
	int fd = open("archivo.txt", O_RDONLY);
	int fd2 = open("archivo2.txt", O_RDONLY);
	char *line;
	
//	atexit(leaks);
	line = get_next_line(fd);
	printf("line: %s\n", line);
	free (line);
	line = get_next_line(fd);
	printf("line2: %s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("line3: %s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("line4: %s\n", line);
	free(line); 
}   */
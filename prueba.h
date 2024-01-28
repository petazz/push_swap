#ifndef PRUEBA_H
# define PRUEBA_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "libft.h"

typedef struct s_data
{
	int len;
	int *arr;
} t_data;

typedef struct s_node
{
	int n;
	struct s_node *next;
	struct s_node *prev;
} t_node;

char	*ft_strjoin_ps(char **argv, int argc);
int		ft_strlen_ps(char **argv);
int		ft_valid(char *str);
void	ft_error();
int		ft_strlen_int(int *c);
t_node	*listGenerator(int *arr, int len);
t_node	*newNode(int n);
void	init_stack(char **argv, t_data *data, int argc);
void	sa(t_node *head);

#endif
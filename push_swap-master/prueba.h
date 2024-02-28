#ifndef PRUEBA_H
# define PRUEBA_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int position;
	int n;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_data
{
	int len;
	int *arr;
	t_node *stack_A;
	t_node *stack_B;
	t_node *last;
} t_data;



char	*ft_strjoin_ps(char **argv, int argc);
int		ft_strlen_ps(char **argv);
int		ft_valid(char *str);
void	ft_error();
int		ft_strlen_int(int *c);
t_node	*listGenerator(int *arr, int len);
void	init_stack(char **argv, t_data *data, int argc);
void	ft_push(t_node **head, int n);
int		ft_pop(t_node **head);
void	sx(t_node **head);
void	px(t_node **dst, t_node **src);
void	rrx(t_node **head);
void	rx(t_node **head);
int		ft_isSort(t_node *head, t_data *data);
void	ft_sort(t_data *data);
int		ft_lst_len(t_node *head);
void	ft_above_average(t_data *data, int average);
int		ft_average(t_node *head, int size_A);
void	ft_besties(t_node **head_A, t_node **head_B);


#endif
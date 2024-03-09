#ifndef PRUEBA_H
# define PRUEBA_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int n;
	int position;
	int cost_bestie;
	int cost_node;
	int	total_cost;
	int	bestie_position;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_data
{
	int len;
	int *arr;
	int	positionMin;
	t_node *cheapest;
	t_node *bestie;
	t_node *stack_A;
	t_node *stack_B;
	t_node *last;
} t_data;


//parseo
char	*ft_strjoin_ps(char **argv, int argc);
int		ft_strlen_ps(char **argv);
int		ft_valid(char *str);
void	ft_error();
int		ft_strlen_int(int *c);

//init_stack
t_node	*listGenerator(int *arr, int len);
void	init_stack(char **argv, t_data *data, int argc);
void	ft_push(t_node **head, int n);
int		ft_pop(t_node **head);

//movements_A
void	sa(t_node **head);
void	pa(t_node **dst, t_node **src);
void	rra(t_node **head);
void	ra(t_node **head);
void	rrr(t_node **head_A, t_node **head_B);

//movements_B
void	sb(t_node **head);
void	pb(t_node **dst, t_node **src);
void	rrb(t_node **head);
void	rb(t_node **head);
void	rr(t_node **head_A, t_node **head_B);

int		ft_isSort(t_node *head, t_data *data);
void	ft_sort(t_data *data);
int		ft_lst_len(t_node *head);
void	ft_above_average(t_data *data, long average);
long	ft_average(t_node *head, int size_A);
int		ft_besties(t_node *head_A, t_node *head_B, t_data *data);
int		ft_calculate_top(t_node **head);
void	ft_positions(t_node **head);
void	ft_calculate_cost(t_node **head_A, t_node **head_B, t_data *data);
void	ft_total_cost(t_node *head_B);
void	ft_cheapest_node(t_node *head_B, t_data *data);
void	ft_move_node_top(t_node **cheapest, t_data *data);
void	ft_move_bestie_top(t_node **ft_besties, t_data *data);
void	ft_set_bestie(int position, t_node *head_A, t_data *data);

void	ft_min(t_node *head_A, t_data *data);
void	ft_set_head(t_node **head_A, t_data *data);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:42:01 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:30 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// buffer gnl
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// estructura node
typedef struct s_node
{
	int				n;
	int				position;
	int				cost_bestie;
	int				cost_node;
	int				total_cost;
	int				bestie_position;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// estructura data
typedef struct s_data
{
	int				len;
	int				*arr;
	int				position_min;
	t_node			*cheapest;
	t_node			*bestie;
	t_node			*stack_a;
	t_node			*stack_b;
	t_node			*last;
}					t_data;

// parseo
char				*ft_strjoin_ps(char **argv, int argc);
int					ft_strlen_ps(char **argv);
int					ft_valid(char *str);
void				ft_error(void);
int					ft_strlen_int(int *c);

// init_stack
t_node				*list_generator(int *arr, int len);
void				init_stack(char **argv, t_data *data, int argc);
void				ft_push(t_node **head, int n);
int					ft_pop(t_node **head);

// movements_A
void				sa(t_node **head);
void				pa(t_node **dst, t_node **src);
void				rra(t_node **head);
void				ra(t_node **head);
void				rrr(t_node **head_a, t_node **head_b);

// movements_B
void				sb(t_node **head);
void				pb(t_node **dst, t_node **src);
void				rrb(t_node **head);
void				rb(t_node **head);
void				rr(t_node **head_a, t_node **head_b);

// sort
int					ft_is_sorted(t_node *head);
void				ft_sort(t_data *data);
int					ft_lst_len(t_node *head);
void				ft_above_average(t_data *data, long average);
long				ft_average(t_node *head);

// cost
int					ft_besties(t_node *head_a, t_node *head_b, t_data *data);
int					ft_calculate_top(t_node **head);
void				ft_positions(t_node **head);
void				ft_calculate_cost(t_node **head_a, t_node **head_b,
						t_data *data);
void				ft_total_cost(t_node *head_b);
void				ft_cheapest_node(t_node *head_b, t_data *data);
void				ft_move_node_top(t_node **cheapest, t_data *data);
void				ft_move_bestie_top(t_node **ft_besties, t_data *data);
void				ft_set_bestie(int position, t_node *head_a, t_data *data);

// utils
void				ft_min(t_node *head_a, t_data *data);
int					ft_set_head(t_node **head_a, t_data *data);
char				**ft_free_split(char **matrix);
void				ft_free_stack(t_node **stack);
void				ss(t_node **head_a, t_node **head_b);

// checker
char				*ft_free_gnl(char *str);
char				*ft_strdup_gnl(char *s1);
size_t				ft_strlen_gnl(char *c);
char				*ft_strchr_gnl(char *s, int c);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_file_read_(char *estatic, int fd);
char				*get_next_line(int fd);
char				*ft_substr_gnl(char *s, unsigned int start, size_t len);
void				ft_while(char *str, t_data *data);
void				ft_move(t_data *data);

#endif
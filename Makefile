# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 18:45:00 by pgonzal2          #+#    #+#              #
#    Updated: 2024/03/21 20:02:44 by pgonzal2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIBFT_DIR	= libft
# LIBFT_PATH = libft/libft.a


# SRCS = 	main.c init_stack.c join.c stackGenerator.c movements_A.c \
# 		movements_B.c sort.c cost.c utils.c utils_2.c get_next_line.c \
# 		get_next_line_utils.c utils_cost.c
		 
# BONUS = checker_bonus.c init_stack_bonus.c movements_A_bonus.c \
# 		movements_B_bonus.c utils_bonus.c stackGenerator_bonus.c join_bonus.c \ 
# 		get_next_line.c get_next_line_utils.c utils_2_bonus.c sort_bonus.c \ 
# 		cost_bonus.c utils_cost_bonus.c 

# CC = gcc -g
# CFLAGS= -Wall -Werror -Wextra
# OBJ = $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS:.c=.o)
# NAME = push_swap
# INCLUDES = -I . -I ${LIBFT_DIR}
# CHECKER = checker

# all: $(NAME)

# bonus:	$(CHECKER)

# %.o: %.c
# 	@${CC} ${FLAGS} $(INCLUDES) -c $^ -o $@

# $(NAME): $(OBJ)
# 	 @$(MAKE) -s all -C $(LIBFT_DIR)
# 	 @$(CC) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

# clean: 
# 	make -sC $(LIBFT_DIR) clean
# 	rm -rf $(OBJ) $(BONUS_OBJS)
	
# fclean: clean
# 	make -sC $(LIBFT_DIR) fclean
# 	rm -f $(NAME) 

# re: fclean all

# $(CHECKER):	 $(BONUS_OBJS)
# 		@$(MAKE) -s all -C $(LIBFT_DIR)
# 		$(CC) $(INCLUDES)  $(BONUS_OBJS) $(LIBFT_PATH) -o $(CHECKER)


# .PHONY: all clean fclean re bonus

LIBFT_DIR = libft
LIBFT_PATH = libft/libft.a

SRCS = main.c init_stack.c join.c stackGenerator.c movements_A.c \
    movements_B.c sort.c cost.c utils.c utils_2.c  \
    utils_cost.c
		 
BONUS = checker_bonus.c init_stack_bonus.c movements_A_bonus.c \
    movements_B_bonus.c utils_bonus.c stackGenerator_bonus.c join_bonus.c \
    get_next_line_bonus.c get_next_line_utils_bonus.c utils_2_bonus.c sort_bonus.c \
    cost_bonus.c utils_cost_bonus.c 

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra -g
OBJ = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
NAME = push_swap
INCLUDES = -I . -I ${LIBFT_DIR}
CHECKER = checker_bonus

all: $(NAME)

bonus: $(CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(NAME): $(OBJ)
	@$(MAKE) -s all -C $(LIBFT_DIR)
	@$(CC) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

clean: 
	@make -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ) $(BONUS_OBJS)
	
fclean: clean
	@make -sC $(LIBFT_DIR) fclean
	@rm -f $(NAME) 

re: fclean all

$(CHECKER): $(BONUS_OBJS)
	@$(MAKE) -s all -C $(LIBFT_DIR)
	@$(CC) $(INCLUDES) $(BONUS_OBJS) $(LIBFT_PATH) -o $(CHECKER)

.PHONY: all clean fclean re bonus

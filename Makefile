# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: usuario <usuario@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 18:45:00 by pgonzal2          #+#    #+#              #
#    Updated: 2024/02/21 18:12:57 by usuario          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	= libft
LIBFT_PATH = libft/libft.a


SRCS = 	main.c init_stack.c join.c stackGenerator.c movements.c sort.c
CC = gcc -g
CFLAGS= -Wall -Werror -Wextra
OBJ = $(SRCS:.c=.o)
NAME = push_swap
INCLUDES = -I . -I ${LIBFT_DIR}

all: $(NAME)

%.o: %.c
	@${CC} ${FLAGS} $(INCLUDES) -c $^ -o $@

$(NAME): $(OBJ)
	 @$(MAKE) -s all bonus -C $(LIBFT_DIR)
	 @$(CC) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

clean: 
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re 
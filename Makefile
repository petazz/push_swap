# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 18:45:00 by pgonzal2          #+#    #+#              #
#    Updated: 2024/03/08 21:02:28 by pgonzal2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	= libft
LIBFT_PATH = libft/libft.a


SRCS = 	main.c init_stack.c join.c stackGenerator.c movements_A.c movements_B.c sort.c cost.c utils.c utils_2.c
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
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ)
	
fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re 
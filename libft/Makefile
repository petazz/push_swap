# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 16:02:50 by pgonzal2          #+#    #+#              #
#    Updated: 2024/01/23 22:27:34 by pgonzal2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c	\
		ft_tolower.c ft_toupper.c ft_bzero.c ft_strrchr.c ft_strncmp.c \
		ft_memmove.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_itoa.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_split.c ft_strmapi.c 

CC = gcc
CFLAGS= -Wall -Werror -Wextra -g
OBJ = $(SRCS:.c=.o)
NAME = libft.a

BONUS =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ) $(BONUS_OBJS)
fclean: clean
	rm -rf $(NAME) 

re: fclean all

bonus:	$(OBJ) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJ) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
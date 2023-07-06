# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:31:43 by lboulang          #+#    #+#              #
#    Updated: 2023/04/04 18:39:43 by lboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c\
ft_putstr.c\
ft_putchar.c\
ft_strlen.c\
ft_nbr.c\
ft_print_ptr.c\

OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

NAME = libftprintf.a

$(NAME):$(OBJ)
	@ar rcs $(NAME) $(OBJ)
	
all: $(NAME)

clean : 
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
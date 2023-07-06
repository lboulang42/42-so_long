# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:31:43 by lboulang          #+#    #+#              #
#    Updated: 2023/04/04 18:36:29 by lboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c\
ft_isalpha.c\
ft_isdigit.c\
ft_strdup.c\
ft_strlen.c\
ft_toupper.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_tolower.c\
ft_substr.c\
ft_memset.c\
ft_bzero.c\
ft_memchr.c\
ft_memcmp.c\
ft_memmove.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_memcpy.c\
ft_strnstr.c\
ft_strncmp.c\
ft_strchr.c\
ft_strrchr.c\
ft_calloc.c\
ft_strjoin.c\
ft_putstr_fd.c\
ft_putchar_fd.c\
ft_putnbr_fd.c\
ft_putendl_fd.c\
ft_striteri.c\
ft_strmapi.c\
ft_split.c\
ft_itoa.c\
ft_strtrim.c

BONUS = ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstlast.c\
ft_lstadd_back.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstclear.c\
ft_lstmap.c

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = ${BONUS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
NAME = libft.a

$(NAME):$(OBJ)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)
	
bonus : $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)


clean : 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
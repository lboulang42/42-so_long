# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:31:43 by lboulang          #+#    #+#              #
#    Updated: 2023/04/04 18:47:08 by lboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

NAME_BONUS = so_long_bonus

LIBFT = ./includes/libft/libft.a

PRINTF = ./includes/ft_printf/libftprintf.a

SRCS = ./srcs/mandatory/main.c\
	./srcs/mandatory/array_handler.c\
	./srcs/mandatory/map_checker.c\
	./srcs/mandatory/map_handler.c\
	./srcs/mandatory/map_pathfind.c\
	./srcs/mandatory/tools.c\
	./srcs/mandatory/game_handler.c\
	./srcs/mandatory/mlx_handler.c\
	./srcs/mandatory/moove_handler.c\
	./srcs/mandatory/clear.c\

SRCS_BONUS = ./srcs/bonus/main_bonus.c\
	./srcs/bonus/array_handler.c\
	./srcs/bonus/map_checker.c\
	./srcs/bonus/map_handler.c\
	./srcs/bonus/map_pathfind.c\
	./srcs/bonus/tools.c\
	./srcs/bonus/game_handler.c\
	./srcs/bonus/mlx_handler.c\
	./srcs/bonus/moove_handler.c\
	./srcs/bonus/bonus_shit_handler.c\
	./srcs/bonus/clear.c\

OBJS = ${SRCS:.c=.o }
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CFLAGS = -g3 -Wall -Werror -Wextra -I .
MLX_FLAGS =	-lm -lmlx -lXext -lX11

all: ${NAME}

$(NAME) : ${OBJS}
	@echo "\n\t\t\t | 📚  MAKING LIBFT 🔄 📚  |\t\t\n"
	@make --no-print-directory  -C ./includes/libft/
	@echo "\n\t\t\t | 📚  LIBFT MAKED ✅ 📚  |\n\n"
	
	@echo "\n\t\t\t | 🖨️  MAKING FT_PRINTF 🔄 🖨️  |\n"
	@make --no-print-directory  -C ./includes/ft_printf/
	@echo "\n\t\t\t | 🖨️  FT_PRINTF MAKED ✅ 🖨️  |\n\n"

	@echo "\n\t\t\t | 👾  MAKING SO_LONG 🔄 👾 🕹️  |\n"
	cc $(OBJS) ./includes/mlx/libmlx.a ./includes/mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${PRINTF} -o ${NAME}
	@echo "\n\t\t\t | 👾  SO_LONG MAKED ✅ 👾 🕹️  |\n\n"

bonus : ${OBJS_BONUS}
	@echo "\n\t\t\t | 📚  MAKING LIBFT 🔄 📚  |\t\t\n"
	@make --no-print-directory  -C ./includes/libft/
	@echo "\n\t\t\t | 📚  LIBFT MAKED ✅ 📚  |\n\n"
	
	@echo "\n\t\t\t | 🖨️  MAKING FT_PRINTF 🔄 🖨️  |\n"
	@make --no-print-directory  -C ./includes/ft_printf/
	@echo "\n\t\t\t | 🖨️  FT_PRINTF MAKED ✅ 🖨️  |\n\n"

	@echo "\n\t\t\t | 👾  MAKING SO_LONG_BONUS 🔄 👾 🎮  |\n"
	cc $(OBJS_BONUS) ./includes/mlx/libmlx.a ./includes/mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${PRINTF} -o ${NAME_BONUS}
	@echo "\n\t\t\t | 👾  SO_LONG_BONUS MAKED ✅ 👾 🎮  |\n\n"

clean : 
	@echo "\n\t\t\t | 📚  CLEANING LIBFT 🚮 📚  |\t\t\n"
	@make --no-print-directory clean -C ./includes/libft/
	@echo "\n\t\t\t | 📚  LIBFT CLEANED 🚯 📚  |\n\n"
	
	@echo "\n\t\t\t | 🖨️  CLEANING FT_PRINTF 🚮 🖨️  |\n"
	@make --no-print-directory clean -C ./includes/ft_printf/
	@echo "\n\t\t\t | 🖨️  FT_PRINTF CLEANED 🚯 🖨️  |\n\n"
	
	@echo "\n\t\t\t | 👾  CLEANING SO_LONG 🚮 👾 🕹️  |\n"
	rm -rf ${OBJS}
	@echo "\n\t\t\t | 👾  SO_LONG CLEANED 🚯 👾 🕹️  |\n\n"
	
	@echo "\n\t\t\t | 👾  CLEANING SO_LONG_BONUS 🚮 👾 🎮  |\n"
	rm -rf ${OBJS_BONUS}
	@echo "\n\t\t\t | 👾  SO_LONG_BONUS CLEANED 🚯 👾 🎮  |\n\n"
	
fclean : clean
	@echo "\n\t\t\t | 📚  FCLEANING LIBFT 🚮 📚  |\t\t\n"
	@make --no-print-directory fclean -C ./includes/libft/
	rm -f ${LIBFT}
	@echo "\n\t\t\t | 📚  LIBFT FCLEANED 🚯 📚  |\n\n"

	@echo "\n\t\t\t | 🖨️  FCLEANING FT_PRINTF 🚮 🖨️  |\n"
	@make --no-print-directory fclean -C ./includes/ft_printf/
	rm -f ${PRINTF}
	@echo "\n\t\t\t | 🖨️  FT_PRINTF FCLEANED 🚯 🖨️  |\n\n"
	@echo "\n\t\t\t | 👾  FCLEANING SO_LONG / SO_LONG_BONUS 🚮 👾 🎮  |\n"
	rm -f ${NAME} ${NAME_BONUS}
	@echo "\n\t\t\t | 👾  SO_LONG / SO_LONG_BONUS FCLEANED 🚯 👾 🎮  |\n\n"

re : fclean all

.PHONY	: all clean fclean re bonus
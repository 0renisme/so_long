# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 05:17:18 by orfreoua          #+#    #+#              #
#    Updated: 2021/10/25 05:17:21 by orfreoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/draw_map.c \
		./srcs/draw.c \
		./srcs/f_libft.c \
		./srcs/free.c \
		./srcs/ft_itoa.c \
		./srcs/game.c \
		./srcs/load_img.c \
		./srcs/main.c \
		./srcs/read.c \
		./srcs/utils.c \
		./srcs/load_map.c \

OBJS 		= ${SRCS:.c=.o}


PATH_MLX	= mlx
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

all: 		${NAME}

bonus: ${NAME} -DBONUS=1

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rramirez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 01:09:45 by rramirez          #+#    #+#              #
#    Updated: 2017/06/26 21:21:06 by rramirez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc

SRCS	= 	main.c\
			save_file.c\
			make_env.c\
			draw_pieces.c\
			translate.c\
			make_slope.c\
			file_check.c\
			ft_rotation.c\

OBJ 	=	${SRCS:.c=.o}

INCLUDE = -I fdf.h

LIBS = -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ):
	@$(CC) $(INCLUDE) -c $(SRCS) -g

$(NAME): $(OBJ)
	@make -C libft all
	@make -C minilibx
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	@make -C libft clean
	@make -C minilibx clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@make -C minilibx clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean

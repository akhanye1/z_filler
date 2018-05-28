# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zphakath <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 01:24:38 by zphakath          #+#    #+#              #
#    Updated: 2018/04/22 12:49:22 by zphakath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = get_piece.c get_plateau.c main.c player_info.c play_piece.c libft/libft.a \
		free_mem.c fitting.c fill_piece.c get_points.c close_plateau.c advantage.c

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	make re -C libft/
	gcc $(SRC) -o $(NAME)

clean:
	make clean -C libft/
	rm -f $(NAME)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_plateau.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:52:31 by zphakath          #+#    #+#             */
/*   Updated: 2018/05/30 16:42:35 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	set_piece_found(t_point *point, char piece_found, int y, int x)
{
	if (piece_found)
	{
		point->y = y;
		point->x = x;
	}
	else
		point->x = -1;
}

static	void	find_right(t_player *player, int dir, t_point *point)
{
	int		y;
	int		x;
	char	piece_found;

	y = point->y;
	x = player->p_width;
	if (player->plateau_piece[y][x] == player->piece_large)
	{
		point->x = -1;
		return ;
	}
	piece_found = FALSE;
	while (x > 0 && ((y < (player->p_height - 1) && dir == UP) ||
				(y > 0 && dir == DOWN)) && !piece_found)
	{
		x--;
		if (x == 0)
		{
			y = (dir == UP) ? y + 1 : y - 1;
			x = 0;
		}
		piece_found = (player->plateau_piece[y][x] == player->piece_large);
	}
	set_piece_found(point, piece_found, y, x);
}

static	void	find_left(t_player *player, int dir, t_point *point)
{
	int		y;
	int		x;
	char	piece_found;

	y = point->y;
	x = 0;
	if (player->plateau_piece[y][x] == player->piece_large)
	{
		point->x = -1;
		return ;
	}
	piece_found = FALSE;
	while (x < player->p_width && ((y < (player->p_height - 1) && dir == UP) ||
				(y > 0 && dir == DOWN)) && !piece_found)
	{
		x++;
		if (x == player->p_width)
		{
			y = (dir == UP) ? y + 1 : y - 1;
			x = 0;
		}
		piece_found = (player->plateau_piece[y][x] == player->piece_large);
	}
	set_piece_found(point, piece_found, y, x);
}

char	find_piece(t_player *player, t_point *point, int up_down, int left_right)
{
	if (left_right == LEFT)
		find_left(player, up_down, point);
	else
		find_right(player, up_down, point);
	return (point->x != -1);
}

void			close_plateau(t_player *player, t_point *point, int debug_fd)
{
	ft_putendl_fd("\n**** CLOSING PLATEAU ****", debug_fd);
	ft_putstr_fd("Second Priority : ", debug_fd);
	ft_putstr_fd((player->second_priority == LEFT) ? "Left" : "Right", debug_fd);
	ft_putchar_fd('\n', debug_fd);
	if (player->priority == UP)
		find_spot(player, point, UP, debug_fd);
	else if (player->priority == DOWN)
		find_spot(player, point, DOWN, debug_fd);
}

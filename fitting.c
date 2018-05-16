/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:10:50 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/22 13:03:30 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	no_enemy_piece(int x, int y, t_player *player, int debug_fd, char pieceat)
{
	char	found_valid_piece;

	found_valid_piece = (player->plateau_piece[y][x] == '.' ||
		player->plateau_piece[y][x] == player->piece_small ||
		player->plateau_piece[y][x] == player->piece_large);
	found_valid_piece = (!found_valid_piece) ? (pieceat == '.') : found_valid_piece;
	return (found_valid_piece);
}

static char	piece_overlap(int x, int y, t_player *player, int debug_fd, char pieceat)
{
	return ((player->plateau_piece[y][x] == player->piece_small ||
	player->plateau_piece[y][x] == player->piece_large) && pieceat == '*');
}

char	    place_piece_right_up(t_player *player, t_point *pp, int debug_fd)
{
	int	x;
	int	y;
	t_point	ps;
	int	overlap;
	int	startX;

	x = -1;
	y = -1;
	startX = pp->x;
	ps.x = 0;
	ps.y = 0;
	overlap = 0;
	while (ps.y < player->piece_height && overlap != 1)
	{
		while (++y < player->piece_height && ((y + pp->y) < player->p_height) &&
			((y + pp->y) > 0) && overlap < 2)
		{
			while (++x < player->piece_width && ((x + pp->x) > 0) && ((x + pp->x) < player->p_width) &&
				((x + pp->x) > 0) && no_enemy_piece(x + pp->x, y + pp->y, player, debug_fd, player->piece_piece[y][x]) &&
				overlap < 2)
			{
				if (piece_overlap(x + pp->x, y + pp->y, player, debug_fd, player->piece_piece[y][x]) &&
					overlap < 2)
				{
					overlap++;
				}
				ft_putstr_fd("{[", debug_fd);
				ft_putchar_fd(player->piece_piece[y][x], debug_fd);
				ft_putstr_fd("](", debug_fd);
				ft_putchar_fd(player->plateau_piece[y + pp->y][x + pp->x], debug_fd);
				ft_putstr_fd(")", debug_fd);
				ft_putnbr_fd(y, debug_fd);
				ft_putstr_fd("|", debug_fd);
				ft_putnbr_fd(y + pp->y, debug_fd);
				ft_putstr_fd(", ", debug_fd);
				ft_putnbr_fd(x, debug_fd);
				ft_putstr_fd("|", debug_fd);
				ft_putnbr_fd(x + pp->x, debug_fd);
				ft_putstr_fd("}  <", debug_fd);
				ft_putnbr_fd(overlap, debug_fd);
				ft_putstr_fd(">  ", debug_fd);
			}
			x = -1;
			ft_putchar_fd('\n', debug_fd);
		}
		if (overlap != 1)
		{
			overlap = 0;
			x = -1;
			y = -1;
			if (ps.x < player->piece_width)
			{
				ps.x++;
				if (player->second_priority == RIGHT)
					pp->x--;
				else
					pp->x++;
			}
			else
			{
				ps.x = 0;
				ps.y++;
				pp->x = startX;
				ft_putnbr_fd(pp->y, debug_fd);
				if (player->priority == DOWN)
					pp->y -= 1;
				else
					pp->y += 1;
			}
		}
	}
	if (overlap == 1)
		return (((pp->y + player->piece_height) <= player->p_height) &&
			(pp->x + player->piece_width) <= player->p_width);
	return (FALSE);
}

char	    place_piece_left_up(t_player *player, t_point *pp, int debug_fd)
{
	pp->x = (pp->x - player->piece_width) + 1;
	ft_putstr_fd("Left X : ", debug_fd);
	ft_putnbr_fd(pp->x, debug_fd);
	ft_putstr_fd("  Bottom : ", debug_fd);
	ft_putnbr_fd(pp->y, debug_fd);
	ft_putchar_fd('\n', debug_fd);
	return (place_piece_right_up(player, pp, debug_fd));
}

char	    place_piece_right_bottom(t_player *player, t_point *pp, int debug_fd)
{
	pp->y = (pp->y - player->piece_height) + 1;
	return (place_piece_right_up(player, pp, debug_fd));
}

char	    place_piece_left_bottom(t_player *player, t_point *pp, int debug_fd)
{
	pp->y = (pp->y - player->piece_height) + 1;
	pp->x = (pp->x - player->piece_width) + 1;
	return (place_piece_right_up(player, pp, debug_fd));
}

char	    place_piece(t_player *player, t_point *point, int debug_fd)
{
	ft_putstr_fd("Priority : ", debug_fd);
	ft_putstr_fd((player->priority == DOWN) ? "DOWN" : "UP", debug_fd);
	ft_putstr_fd(" | Second Priority : ", debug_fd);
	ft_putstr_fd((player->second_priority == LEFT) ? "LEFT" : "RIGHT", debug_fd);
	ft_putendl_fd((player->closed) ? " - closed" : " - Not closed", debug_fd);
	if (player->priority == DOWN && player->second_priority == RIGHT && !(player->closed))
		return (place_piece_right_up(player, point, debug_fd));
	else if (player->priority == DOWN && player->second_priority == LEFT && !(player->closed))
		return (place_piece_left_up(player, point, debug_fd));
	else if (player->priority == UP && player->second_priority == RIGHT && !(player->closed))
		return (place_piece_right_bottom(player, point, debug_fd));
	else if (player->priority == UP && player->second_priority == LEFT && !(player->closed))
		return (place_piece_left_bottom(player, point, debug_fd));
	else
		// return (place_piece_right_up(player, point, debug_fd));
		return (FALSE);
}

char	    close_place_piece(t_player *player, t_point *point, int debug_fd)
{
	ft_putstr_fd("Priority : ", debug_fd);
	ft_putstr_fd((player->priority == DOWN) ? "DOWN" : "UP", debug_fd);
	ft_putstr_fd(" | Second Priority : ", debug_fd);
	ft_putstr_fd((player->second_priority == LEFT) ? "LEFT" : "RIGHT", debug_fd);
	ft_putendl_fd((player->closed) ? " - closed" : " - Not closed", debug_fd);
	if (player->priority == DOWN && player->second_priority == RIGHT)
		return (place_piece_right_up(player, point, debug_fd));
	else if (player->priority == DOWN && player->second_priority == LEFT)
		return (place_piece_left_up(player, point, debug_fd));
	else if (player->priority == UP && player->second_priority == RIGHT)
		return (place_piece_right_bottom(player, point, debug_fd));
	else if (player->priority == UP && player->second_priority == LEFT)
		return (place_piece_left_bottom(player, point, debug_fd));
	else
		return (place_piece_right_up(player, point, debug_fd));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:10:50 by zphakath          #+#    #+#             */
/*   Updated: 2018/06/01 09:04:26 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_right_place(t_player *player, t_point *point)
{
	int	x;
	int y;
	int	direction;

	x = point->x;
	y = point->y;
	direction = player->second_priority;
	while ((x < player->p_width &&
			(player->plateau_piece[y][x] == player->piece_large ||
			player->plateau_piece[y][x] == player->piece_small) &&
			direction == RIGHT) ||
			(x > 0 && (player->plateau_piece[y][x] == player->piece_large ||
			player->plateau_piece[y][x] == player->piece_large) &&
			direction == LEFT))
	{
		x = (direction == RIGHT) ? x + 1 : x - 1;
	}
	x = (direction == RIGHT) ? x - 1 : x + 1;
	return (x);
}

void	change_side(t_player *player, t_point *point, t_point *o_point)
{
	player->second_priority = (player->second_priority == LEFT) ? RIGHT : LEFT;
	point->x = o_point->x;
	point->y = o_point->y;
	point->x = get_right_place(player, point);
}

char	piece_placed(t_player *player, t_point *point, int debug_fd)
{
	if (player->priority == DOWN && player->second_priority == RIGHT
			&& !(player->closed))
		return (place_piece_right_up(player, point, debug_fd));
	else if (player->priority == DOWN && player->second_priority == LEFT
			&& !(player->closed))
		return (place_piece_left_up(player, point, debug_fd));
	else if (player->priority == UP && player->second_priority == RIGHT
			&& !(player->closed))
		return (place_piece_right_bottom(player, point, debug_fd));
	else if (player->priority == UP && player->second_priority == LEFT
			&& !(player->closed))
		return (place_piece_left_bottom(player, point, debug_fd));
	return (FALSE);
}

char	place_piece(t_player *player, t_point *point, int debug_fd)
{
	int		num;
	char	placed;
	t_point	o_point;

	o_point.x = point->x;
	o_point.y = point->y;
	num = 0;
	while (num < 2)
	{
		if (!(placed = piece_placed(player, point, debug_fd)))
		{
			num++;
			change_side(player, point, &o_point);
		}
		if (placed)
			return (TRUE);
	}
	return (num < 2);
}

char	close_place_piece(t_player *player, t_point *point, int debug_fd)
{
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:24:05 by zphakath          #+#    #+#             */
/*   Updated: 2018/06/01 09:39:57 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	set_enemy_position(t_player *player, int y, int x)
{
	player->enemy.top.x = x;
	player->enemy.top.y = y;
	player->enemy.right.x = x;
	player->enemy.right.y = y;
	player->enemy.left.x = x;
	player->enemy.left.y = y;
	player->enemy.bottom.x = x;
	player->enemy.bottom.y = y;
}

static	char	scan_enemy_pieces(int debug_fd, t_player *player)
{
	int		plat_height;
	int		y;
	int		x;
	char	piece_found;

	plat_height = player->p_height;
	y = 2;
	piece_found = FALSE;
	while (y < (plat_height) && !piece_found)
	{
		x = 0;
		while (x < player->p_width && !piece_found)
		{
			if (player->plateau_piece[y][x] != player->piece_large &&
					player->plateau_piece[y][x] != '.')
			{
				set_enemy_position(player, y, x);
				get_pieces(debug_fd, player);
				piece_found = TRUE;
			}
			x++;
		}
		y++;
	}
	return (piece_found);
}

void			get_precise_piece(t_player *pl, int debug_fd, t_point *pnt)
{
	if (pl->priority == DOWN)
	{
		if (pl->second_priority == RIGHT)
		{
			pl->decision.bottom.x = get_right_piece(pl,
					pl->decision.bottom.y, pl->decision.bottom.x,
					debug_fd);
			pnt->x = pl->decision.bottom.x;
		}
		else
		{
			pl->decision.bottom.x = get_left_piece(pl,
					pl->decision.bottom.y, pl->decision.bottom.x,
					debug_fd);
			pnt->x = pl->decision.bottom.x;
		}
	}
	else
		get_precise_up(pl, pnt, debug_fd);
}

void			repeat_play(t_player *player, t_point *point, int debug_fd)
{
	get_advantage(debug_fd, player, point);
	get_precise_piece(player, debug_fd, point);
	if (place_piece(player, point, debug_fd))
		print_piece(point->y - 1, point->x);
	else
		close_plateau(player, point, debug_fd);
}

void			play_piece(t_player *player, int debug_fd)
{
	t_point point;
	t_point	spoint;

	point.x = 0;
	point.y = 0;
	spoint.y = 1;
	spoint.x = 0;
	fill_plateau(player, debug_fd);
	fill_piece(player, debug_fd);
	if (!player->numPlayed)
	{
		if (!scanforplay(debug_fd, player, &point, &spoint) ||
				!scan_enemy_pieces(debug_fd, player))
		{
			free_memory(player, debug_fd);
			ft_putendl("0 0");
		}
		repeat_play(player, &point, debug_fd);
	}
	else
	{
		get_pieces(debug_fd, player);
		repeat_play(player, &point, debug_fd);
	}
	free_memory(player, debug_fd);
}

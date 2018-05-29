/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:24:05 by zphakath          #+#    #+#             */
/*   Updated: 2018/05/29 17:12:07 by zphakath         ###   ########.fr       */
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

void			print_piece(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void			get_precise_piece(t_player *player, int debug_fd, t_point *point)
{
	if (player->priority == DOWN)
	{
		if (player->second_priority == RIGHT)
		{
			player->decision.bottom.x = get_right_piece(player,
					player->decision.bottom.y, player->decision.bottom.x,
					debug_fd);
			point->x = player->decision.bottom.x;
		}
		else
		{
			player->decision.bottom.x = get_left_piece(player,
					player->decision.bottom.y, player->decision.bottom.x,
					debug_fd);
			point->x = player->decision.bottom.x;
		}
	}
	else
		get_precise_up(player, point, debug_fd);
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

void			play_piece(t_player *player, int debug_fd, t_point *spoint)
{
	t_point point;

	point.x = 0;
	point.y = 0;
	fill_plateau(player, debug_fd);
	fill_piece(player, debug_fd);
	if (!player->numPlayed)
	{
		if (!scanforplay(debug_fd, player, &point, spoint) ||
				!scan_enemy_pieces(debug_fd, player))
		{
			free_memory(player, debug_fd);
			ft_putendl("0 0");
			exit(1);
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

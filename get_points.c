/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:09:39 by zphakath          #+#    #+#             */
/*   Updated: 2018/06/01 09:31:50 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	check_right(t_player *player, int y, int x, t_dcn *p_type)
{
	char	piece_found;

	piece_found = TRUE;
	while (++x < player->p_width && piece_found)
	{
		while (++y < player->p_height)
		{
			piece_found = (player->plateau_piece[y][x] == player->piece_large);
			if (piece_found)
			{
				p_type->right.x = x;
				p_type->right.y = y;
				break ;
			}
		}
		y = 0;
	}
}

static	void	check_left(t_player *player, int y, int x, t_dcn *p_type)
{
	char	piece_found;

	piece_found = TRUE;
	while (--x > 0 && piece_found)
	{
		while (++y < player->p_height)
		{
			piece_found = (player->plateau_piece[y][x] == player->piece_large);
			if (piece_found)
			{
				p_type->left.x = x;
				p_type->left.y = y;
				break ;
			}
		}
		y = 0;
	}
}

static	void	check_up(t_player *player, int y, int x, t_dcn *p_type)
{
	char	piece_found;

	piece_found = TRUE;
	while (--y > 0 && piece_found)
	{
		while (++x < player->p_width)
		{
			piece_found = (player->plateau_piece[y][x] == player->piece_large);
			if (piece_found)
			{
				p_type->top.x = x;
				p_type->top.y = y;
				break ;
			}
		}
		x = -1;
	}
}

static	void	check_bottom(t_player *player, int y, int x, t_dcn *p_type)
{
	char	piece_found;

	piece_found = TRUE;
	while (++y < player->p_height && piece_found)
	{
		while (++x < player->p_width)
		{
			piece_found = (player->plateau_piece[y][x] == player->piece_large);
			if (piece_found)
			{
				p_type->bottom.x = x;
				p_type->bottom.y = y;
				break ;
			}
		}
		x = -1;
	}
}

void			get_pieces(int debug_fd, t_player *player)
{
	int	y;
	int	x;

	x = player->enemy.right.x;
	y = 0;
	check_right(player, y, x, &player->enemy);
	x = player->enemy.left.x;
	check_left(player, y, x, &player->enemy);
	y = player->enemy.top.y;
	x = -1;
	check_up(player, y, x, &player->enemy);
	y = player->enemy.bottom.y;
	check_bottom(player, y, x, &player->enemy);
	x = player->decision.right.x;
	y = 0;
	check_right(player, y, x, &player->decision);
	x = player->decision.left.x;
	check_left(player, y, x, &player->decision);
	y = player->decision.top.y;
	x = -1;
	check_up(player, y, x, &player->decision);
	y = player->decision.bottom.y;
	check_bottom(player, y, x, &player->decision);
}

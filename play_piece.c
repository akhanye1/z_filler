/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:24:05 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/22 15:20:41 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	scan_enemy_pieces(int debug_fd, t_player *player)
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
			if (player->plateau_piece[y][x] != player->piece_small &&
				player->plateau_piece[y][x] != player->piece_large &&
				player->plateau_piece[y][x] != '.')
			{
				player->enemy.top.x = x;
				player->enemy.top.y = y;
				player->enemy.right.x = x;
				player->enemy.right.y = y;
				player->enemy.left.x = x;
				player->enemy.left.y = y;
				player->enemy.bottom.x = x;
				player->enemy.bottom.y = y;
				get_all_enemy_pieces(debug_fd, player);
				piece_found = TRUE;
			}
			x++;
		}
		y++;
	}
	return (piece_found);
}

void	get_advantage(int debug_fd, t_player *player, t_point *point)
{
	if (player->closed)
		return ;
	if (player->decision.bottom.y < player->enemy.top.y)
	{
		if (player->decision.bottom.y >= (player->p_height - 1))
			player->priority = UP;
		else
			player->priority = DOWN;
		ft_putendl_fd((player->priority == UP) ? "UP" : "DOWN", debug_fd);
	}
	else
	{
		if (player->decision.top.y <= 1)
			player->priority = DOWN;
		else
			player->priority = UP;
	}
	if (player->decision.right.x < player->enemy.left.x)
		player->second_priority = RIGHT;
	else
		player->second_priority = LEFT;
	if (player->priority == UP)
		point->y = player->decision.top.y;
	else if (player->priority == DOWN)
		point->y = player->decision.bottom.y;
	if (player->second_priority == RIGHT)
		point->x = player->decision.right.x;
	else if (player->second_priority == LEFT)
		point->x = player->decision.left.x;
	if ((player->decision.bottom.y >= (player->p_height - 1)) &&
		(player->decision.top.y <= 1))
		player->closed = TRUE;
}

void	print_piece(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int		get_right_piece(t_player *player, int y, int x, int debug_fd)
{
	while ((player->plateau_piece[y][x] == player->piece_small ||
		player->plateau_piece[y][x] == player->piece_large) &&
		x < player->p_width)
	{
		x++;
	}
	return (x - 1);
}

int		get_left_piece(t_player *player, int y, int x, int debug_fd)
{
	while ((player->plateau_piece[y][x] == player->piece_small ||
		player->plateau_piece[y][x] == player->piece_large) &&
		x > 0)
	{
		x--;
	}
	return (x + 1);
}

void	get_precise_piece(t_player *player, int debug_fd, t_point *point)
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
	{
		if (player->second_priority == RIGHT)
		{
			player->decision.top.x = get_right_piece(player,
				player->decision.top.y, player->decision.top.x,
				debug_fd);
			point->x = player->decision.top.x;
		}
		else
		{
			player->decision.top.x = get_left_piece(player,
				player->decision.top.y, player->decision.top.x,
				debug_fd);
			point->x = player->decision.top.x;
		}
	}
}

void	repeat_play(t_player *player, t_point *point, int debug_fd)
{
	get_advantage(debug_fd, player, point);
	get_precise_piece(player, debug_fd, point);
	if (place_piece(player, point, debug_fd))
		print_piece(point->y - 1, point->x);
	else
		close_plateau(player, point, debug_fd);
}

void	play_piece(t_player *player, int debug_fd, t_point *spoint)
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
		// get_advantage(debug_fd, player, &point);
		// get_precise_piece(player, debug_fd, &point);
		// if (place_piece(player, &point, debug_fd))
		// 	print_piece(point.y - 1, point.x);
		// else
		// 	close_plateau(player, &point, debug_fd);
	}
	else
	{
		get_all_enemy_pieces(debug_fd, player);
		get_player_pieces(debug_fd, player);
		repeat_play(player, &point, debug_fd);
	}
	free_memory(player, debug_fd);
	player->done_reading = 0;
	player->p_countdown = 0;
	player->piece_countdown = 0;
}

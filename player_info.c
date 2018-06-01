/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:13:14 by zphakath          #+#    #+#             */
/*   Updated: 2018/06/01 09:34:34 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_spot(t_player *player, t_point *point, int up_down, int debug_fd)
{
	int tries;
	int y;
	int check_side;

	tries = 0;
	y = (up_down == UP) ? 0 : player->p_height - 2;
	check_side = player->second_priority;
	while ((tries < 2) && ((y < (player->p_height - 1) && up_down == UP) ||
				(y > 0 && up_down == DOWN)))
	{
		point->y = y;
		if (find_piece(player, point, up_down, check_side))
		{
			y = point->y;
			if (close_place_piece(player, point, debug_fd))
			{
				print_piece(point->y - 1, point->x);
				check_tries(tries, player, check_side);
				return ;
			}
		}
		tries = fix_spot(player, &y, up_down, tries);
	}
	check_tries(tries, player, check_side);
	print_piece(0, 0);
}

int		fix_spot(t_player *player, int *y, int up_down, int tries)
{
	*y = (up_down == UP) ? *y + 1 : *y - 1;
	if ((*y == player->p_height && up_down == UP) ||
				(*y == 0 && up_down == DOWN))
	{
		*y = (up_down == UP) ? 0 : player->p_height - 2;
		player->second_priority = (player->second_priority == LEFT) ? RIGHT :
			LEFT;
		tries++;
	}
	return (tries);
}

void	check_tries(int tries, t_player *player, int check_side)
{
	if (tries > 0)
		player->second_priority = (check_side == LEFT) ? RIGHT : LEFT;
}

char	get_player_info(char *line, t_player *player, int debug_fd)
{
	int		len;

	len = ft_strlen("$$$ exec p");
	player->number = ft_atoi(line + len);
	ft_putstr_fd("Player Number : ", debug_fd);
	ft_putnbr_fd(player->number, debug_fd);
	ft_putchar_fd('\n', debug_fd);
	if (player->number == 1)
	{
		player->piece_large = 'O';
		player->piece_small = 'o';
	}
	else
	{
		player->piece_large = 'X';
		player->piece_small = 'x';
	}
	return (1);
}

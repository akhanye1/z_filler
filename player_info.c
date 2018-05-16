/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:13:14 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/22 13:13:15 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	ft_putstr_fd("Player Piece : ", debug_fd);
	ft_putchar_fd(player->piece_large, debug_fd);
	ft_putchar_fd('\n', debug_fd);
	return (1);
}

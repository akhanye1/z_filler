/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 11:12:32 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/22 15:18:29 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_memory(t_player *player, int debug_fd)
{
	int	i;

	i = 0;
	if (player->plateau_piece)
	{
		i = -1;
		while (player->plateau_piece[++i])
			free(player->plateau_piece[i]);
		free(player->plateau_piece);
		player->plateau_piece = NULL;
	}
	if (player->piece_piece)
	{
		i = -1;
		while (player->piece_piece[++i])
			free(player->piece_piece[i]);
		free(player->piece_piece);
		player->piece_piece = NULL;
	}
}

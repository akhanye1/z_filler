/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:36:27 by zphakath          #+#    #+#             */
/*   Updated: 2018/06/01 14:30:35 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_plateau(t_player *player, int debug_fd)
{
	char	**temp;
	int		i;
	t_line	*fr;
	t_line	*iter;

	i = 0;
	temp = (char**)malloc(sizeof(char*) * ((player->p_height) + 1));
	temp[player->p_height - 1] = NULL;
	iter = player->plateau;
	while (iter)
	{
		temp[i] = ft_strdup(iter->line + 4);
		i++;
		fr = iter;
		iter = iter->next;
		free(fr->line);
		fr->line = NULL;
		free(fr);
	}
	player->plateau = NULL;
	temp[i] = NULL;
	player->plateau_piece = temp;
}

void	fill_piece(t_player *player, int debug_fd)
{
	char	**temp;
	int		i;
	t_line	*fr;
	t_line	*iter;

	i = 0;
	temp = (char**)malloc(sizeof(char*) * ((player->piece_height) + 1));
	temp[player->piece_height - 1] = NULL;
	iter = player->piece_memory;
	player->piece_true_height = 0;
	while (iter)
	{
		temp[i++] = ft_strdup(iter->line);
		if (ft_strchr(iter->line, '*'))
			player->piece_true_height++;
		fr = iter;
		iter = iter->next;
		free(fr->line);
		fr->line = NULL;
		free(fr);
	}
	player->piece_memory = NULL;
	temp[i] = NULL;
	player->piece_height--;
	player->piece_piece = temp;
}

void	set_player_position(t_player *player, int y, int x)
{
	player->decision.top.x = x;
	player->decision.top.y = y;
	player->decision.right.x = x;
	player->decision.right.y = y;
	player->decision.left.x = x;
	player->decision.left.y = y;
	player->decision.bottom.x = x;
	player->decision.bottom.y = y;
	player->num_played = TRUE;
}

char	scanforplay(int debug_fd, t_player *player, t_point *point,
		t_point *spoint)
{
	int		y;
	int		x;
	char	piecefound;

	y = spoint->y;
	piecefound = FALSE;
	while (y < (player->p_height) && !piecefound)
	{
		x = 0;
		while (x < player->p_width && !piecefound)
		{
			if (player->plateau_piece[y][x] == player->piece_large)
			{
				if (!player->num_played)
					set_player_position(player, y, x);
				piecefound = TRUE;
				point->y = y;
				point->x = x;
			}
			x++;
		}
		y++;
	}
	return (piecefound);
}

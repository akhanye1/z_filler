/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:36:27 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/22 12:52:52 by zphakath         ###   ########.fr       */
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
	while (iter)
	{
		temp[i++] = ft_strdup(iter->line);
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

char	scanforplay(int debug_fd, t_player *player, t_point *point,
		t_point *spoint)
{
	int		platheight;
	int		y;
	int		x;
	int		startX;
	char	piecefound;
	int		plays;

	platheight = player->p_height;
	y = spoint->y;
	piecefound = FALSE;
	while (y < (platheight) && !piecefound)
	{
		x = 0;
		while (x < player->p_width && !piecefound)
		{
			if (player->plateau_piece[y][x] == player->piece_small ||
					player->plateau_piece[y][x] == player->piece_large)
			{
				if (!player->numPlayed)
				{
					player->decision.top.x = x;
					player->decision.top.y = y;
					player->decision.right.x = x;
					player->decision.right.y = y;
					player->decision.left.x = x;
					player->decision.left.y = y;
					player->decision.bottom.x = x;
					player->decision.bottom.y = y;
					player->numPlayed = TRUE;
				}
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

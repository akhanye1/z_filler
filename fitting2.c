/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 08:57:34 by zphakath          #+#    #+#             */
/*   Updated: 2018/06/01 09:07:22 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	place_piece_left_up(t_player *player, t_point *pp, int debug_fd)
{
	pp->x = (pp->x - player->piece_width) + 1;
	return (place_piece_right_up(player, pp, debug_fd));
}

char	place_piece_right_bottom(t_player *player, t_point *pp, int debug_fd)
{
	pp->y = (pp->y - player->piece_height) + 1;
	return (place_piece_right_up(player, pp, debug_fd));
}

char	place_piece_left_bottom(t_player *player, t_point *pp, int debug_fd)
{
	pp->y = (pp->y - player->piece_height) + 1;
	pp->x = (pp->x - player->piece_width) + 1;
	return (place_piece_right_up(player, pp, debug_fd));
}

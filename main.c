/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:42:56 by zphakath          #+#    #+#             */
/*   Updated: 2018/06/01 10:04:25 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	init_player(t_player *player)
{
	player->number = 0;
	player->p_height = 0;
	player->p_countdown = 0;
	player->plateau = NULL;
	player->piece_height = 0;
	player->piece_countdown = 0;
	player->piece_memory = NULL;
	player->done_reading = 0;
	player->num_played = 0;
	player->priority = RIGHT;
	player->closed = FALSE;
}

void			print_piece(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int				main(void)
{
	char		*line;
	int			fd;
	t_player	*player;

	fd = open("debug.txt", O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (!(player = (t_player*)malloc(sizeof(t_player))))
	{
		ft_putendl("0 0");
		return (EXIT_FAILURE);
	}
	init_player(player);
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl_fd("YYY", fd);
		if (ft_strstr(line, "$$$ exec p"))
			get_player_info(line, player, fd);
		if (ft_strstr(line, "Plateau") || player->p_countdown > 0)
			get_plateau(line, player, fd);
		if (ft_strstr(line, "Piece") || player->piece_countdown > 0)
			get_piece(line, player, fd);
		if (player->done_reading == 1)
		{
			play_piece(player, fd);
			ft_putendl_fd(">>>>>>>>>>>>", fd);
		}
	}
	ft_putendl_fd("<<<<<<<<<<", fd);
	ft_putendl_fd(line, fd);
	ft_putendl_fd("0 0", fd);
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:42:56 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/14 13:44:49 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_player(t_player *player)
{
	player->number = 0;
	player->p_height = 0;
	player->p_countdown = 0;
	player->plateau = NULL;
	player->piece_height = 0;
	player->piece_countdown = 0;
	player->piece_memory = NULL;
	player->done_reading = 0;
	player->numPlayed = 0;
	player->priority = RIGHT;
	player->closed = FALSE;
}

int	main(/*int ac, char **av**/)
{
	char	*line;
	char	*filename;
	char	*filename2;
	int		fd;
	int		rd;
	int		len;
	char	*symbol;
	t_player	*player;
	t_point		spoint;
	int		fd_debug;

	/*if (ac != 2) {
		ft_putendl("Usage: ./filler <filename>");
		return (EXIT_FAILURE);
	}
	if ((rd = open(av[1], O_RDONLY)) == -1) {
		ft_putendl("File cannot be open");
		return (EXIT_FAILURE);
	}*/
	rd = 0;
	filename = "debug.txt";
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (!(player = (t_player*)malloc(sizeof(t_player))))
	{
		ft_putendl("0 0");
		return (EXIT_FAILURE);
	}
	filename2 = "play.txt";
	fd_debug = open(filename2, O_CREAT | O_WRONLY | O_TRUNC, 0755);
	init_player(player);
	spoint.y = 1;
	spoint.x = 0;
	while (get_next_line(rd, &line) > 0)
	{
		ft_putendl_fd(line, fd_debug);
		if (ft_strstr(line, "$$$ exec p"))
			get_player_info(line, player, fd);
		if (ft_strstr(line, "Plateau") || player->p_countdown > 0)
		{
			//ft_putendl_fd(line, fd);
			get_plateau(line, player, fd);
		}
		if (ft_strstr(line, "Piece") || player->piece_countdown > 0)
		{
			//ft_putendl_fd(line, fd);
			get_piece(line, player, fd);
		}
		if (player->done_reading == 1)
		{
			play_piece(player, fd, &spoint);
			ft_putendl_fd("\n>>>>>>>>\n", fd);
		}
		//free(line);
	}
	ft_putendl_fd("0 0", fd);
	close(fd);
	return (0);

}

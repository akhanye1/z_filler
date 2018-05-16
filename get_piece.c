/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:00:13 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/22 15:00:24 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_height(char *line)
{
	int len;

	len = ft_strlen("Piece ");
	return (ft_atoi(line + len) + 1);
}

static int	get_width(char *line)
{
	int len;

	len = ft_strlen("Piece ");
	while (line[++len] && line[len] != ' ')
		;
	len++;
	return (ft_atoi(line + len));
}

void		add_piece_line(t_line **head, char *line)
{
	t_line	*temp;
	t_line	*iterator;

	if (!(temp = (t_line*)malloc(sizeof(t_line))))
		exit(EXIT_FAILURE);
	temp->line = line;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
		return ;
	}
	iterator = *head;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = temp;
}

char		get_piece(char *line, t_player *player, int debug_fd)
{

	if (ft_strstr(line, "Piece"))
	{
		player->piece_height = get_height(line);
		player->piece_width = get_width(line);
	}
	if (ft_strstr(line, "Piece"))
	{
		player->piece_countdown = player->piece_height;
		ft_putstr_fd("Piece Height : ", debug_fd);
		ft_putnbr_fd(player->piece_height, debug_fd);
		ft_putstr_fd("\nPiece Width : ", debug_fd);
		ft_putnbr_fd(player->piece_width, debug_fd);
		ft_putchar_fd('\n', debug_fd);
	}
	if (ft_strstr(line, "Piece"))
		return (1);
	add_piece_line(&player->piece_memory, line);
	player->piece_countdown--;
	if (player->piece_countdown == 1)
		player->done_reading = 1;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plateau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:23:33 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/14 09:59:22 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_height(char *line)
{
	int len;

	len = ft_strlen("Plateau ");
	return (ft_atoi(line + len) + 1);
}

static int	get_width(char *line)
{
	int len;

	len = ft_strlen("Plateau ");
	while (line[++len] && line[len] != ' ')
		;
	len++;
	return (ft_atoi(line + len));
}

void		add_line(t_line **head, char *line)
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

char		get_plateau(char *line, t_player *player, int debug_fd)
{

	if (player->p_height == 0 && ft_strstr(line, "Plateau"))
	{
		player->p_height = get_height(line);
		player->p_width = get_width(line);
	}
	if (ft_strstr(line, "Plateau"))
		player->p_countdown = player->p_height;
	if (ft_strstr(line, "Plateau"))
		return (1);
	add_line(&player->plateau, line);
	player->p_countdown--;
	return (1);
}

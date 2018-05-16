/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:02:24 by zphakath          #+#    #+#             */
/*   Updated: 2018/01/10 15:39:34 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	join_lines(char **line, char **container, char *buff)
{
	int		index;
	char	*temp;
	char	*temp1;

	index = ft_strchr(buff, '\n') - buff;
	if (*line == NULL)
		*line = ft_strsub(buff, 0, index);
	else
	{
		temp = *line;
		temp1 = ft_strsub(buff, 0, index);
		*line = ft_strjoin(*line, temp1);
		free(temp);
		free(temp1);
	}
	*container = ft_strdup(buff + (index + 1));
	return (1);
}

static int	join_from_save(char **line, char **container, char *buff)
{
	ft_strcpy(buff, *container);
	ft_strdel(container);
	return (join_lines(line, container, buff));
}

static void	combine_text(char **line, char *buff)
{
	char *temp;

	if (*line == NULL)
		*line = ft_strdup(buff);
	else
	{
		temp = *line;
		*line = ft_strjoin(*line, buff);
		free(temp);
	}
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char *container = NULL;
	int			byte;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	*line = NULL;
	if (container)
	{
		if (ft_strchr(container, '\n'))
			return (join_from_save(line, &container, buff));
		*line = ft_strdup(container);
		ft_strdel(&container);
	}
	while ((byte = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte] = '\0';
		if (!ft_strchr(buff, '\n'))
			combine_text(line, buff);
		else
			return (join_lines(line, &container, buff));
	}
	if (*line && ft_strlen(*line) > 0)
		return (1);
	return (byte == -1) ? -1 : 0;
}

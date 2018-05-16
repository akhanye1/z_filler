/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:22:19 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 14:33:32 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	char	*tr;
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	tr = ft_strdup(s);
	if (!tr)
		return (NULL);
	else
	{
		i = 0;
		while (tr[i] == ' ' || tr[i] == '\n' || tr[i] == '\t')
			i++;
		tr = ft_strcpy(tr, tr + i);
		i = ft_strlen(tr) - 1;
		while ((tr[i] == ' ' || tr[i] == '\n' || tr[i] == '\t') && i >= 0)
		{
			tr[i] = '\0';
			i--;
		}
		ret = ft_strdup(tr);
		free(tr);
		return (ret);
	}
}

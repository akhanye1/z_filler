/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:18:08 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:21:09 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (s1[i] != '\0')
		i++;
	len = i;
	while (s2[j] != '\0')
	{
		s1[len + j] = s2[j];
		j++;
	}
	s1[len + j] = '\0';
	return (s1);
}

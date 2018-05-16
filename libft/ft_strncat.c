/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:39:40 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:21:37 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	len = i;
	while (s2[j] != '\0' && j != (int)n)
	{
		s1[len + j] = s2[j];
		j++;
	}
	s1[len + j] = '\0';
	return (s1);
}

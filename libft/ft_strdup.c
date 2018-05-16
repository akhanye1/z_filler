/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 23:30:18 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:18:19 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char const *str)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	if (!(copy = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	while (str[j] != '\0')
	{
		copy[j] = str[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

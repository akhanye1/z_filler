/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:13:09 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:23:12 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *src, int c)
{
	char	*temp;
	int		i;
	int		len;

	len = ft_strlen(src) + 1;
	temp = (char *)src;
	i = 0;
	while (len)
	{
		if (temp[i] == (char)c)
			return (temp + i);
		i++;
		len--;
	}
	return (NULL);
}

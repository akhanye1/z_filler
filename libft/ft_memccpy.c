/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:01:16 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:14:59 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	temp = (unsigned char*)dst;
	temp2 = (unsigned char*)src;
	while (i < n)
	{
		temp[i] = temp2[i];
		if (temp2[i] == (unsigned char)c)
			return (temp + i + 1);
		i++;
	}
	return (NULL);
}

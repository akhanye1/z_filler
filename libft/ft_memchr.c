/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:39:43 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:16:19 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(void const *src, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (void*)src;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return ((void*)temp + i);
		i++;
	}
	return (NULL);
}

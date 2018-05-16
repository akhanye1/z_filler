/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:40:47 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:12:36 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	temp1 = (unsigned char*)dst;
	temp2 = (unsigned char*)src;
	if (n == 0)
		return (dst);
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	dst = (void *)temp1;
	return (dst);
}

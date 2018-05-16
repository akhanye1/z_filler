/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 12:11:52 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:15:45 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp1;
	const char	*temp2;

	temp1 = (char*)dst;
	temp2 = (char*)src;
	if (dst > src)
	{
		while (len--)
		{
			temp1[len] = temp2[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return ((void*)temp1);
}

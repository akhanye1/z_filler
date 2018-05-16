/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 07:47:53 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:22:19 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	dstlen = i;
	if ((size - i) == 0)
		return (i + srclen);
	while (src[i - dstlen] && i < size - 1)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	if (dstlen < size)
		dst[i] = '\0';
	return (dstlen + srclen);
}

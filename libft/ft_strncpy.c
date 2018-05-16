/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:03:32 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:20:11 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && dest[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	i = 0;
	while (i < len && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

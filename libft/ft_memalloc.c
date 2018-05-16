/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:06:25 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:50:07 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *s;

	s = (char *)malloc(sizeof(char) * size);
	if (s == NULL)
	{
		return (NULL);
	}
	ft_memset(s, 0, size);
	return (s);
}

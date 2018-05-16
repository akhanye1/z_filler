/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:28:14 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:24:23 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *src, int c)
{
	char	*t;
	int		i;

	t = (char *)src;
	i = ft_strlen(src);
	if (src == NULL)
		return (0);
	while (i >= 0)
	{
		if (t[i] == (char)c)
			return (t + i);
		i--;
	}
	return (NULL);
}

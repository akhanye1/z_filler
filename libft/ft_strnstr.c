/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:11:34 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 14:54:09 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	char	*big1;
	char	*little1;

	big1 = (char *)big;
	little1 = (char *)lit;
	if (*little1 == '\0')
		return ((char *)big1);
	i = ft_strlen(little1);
	while (*big1 != '\0' && len-- >= i)
	{
		if (*big1 == *little1 && ft_strncmp(big1, little1, i) == 0)
			return ((char *)big1);
		big1++;
	}
	return (NULL);
}

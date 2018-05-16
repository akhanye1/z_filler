/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 08:51:44 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:54:20 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*temp;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(temp = ft_strdup(s)))
		return (NULL);
	while (temp[i] != '\0')
	{
		temp[i] = f(temp[i]);
		i++;
	}
	return (temp);
}

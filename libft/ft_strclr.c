/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:59 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:52:01 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			s[i] = '\0';
			i++;
		}
	}
}
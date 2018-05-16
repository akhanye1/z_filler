/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 12:57:35 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 14:33:58 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lengthofint(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	n = n / 10;
	len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*temp;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(temp = (char *)malloc(sizeof(char) * (lengthofint(n) + 1))))
		return (NULL);
	len = lengthofint(n);
	temp[len] = '\0';
	if (n < 0)
	{
		temp[0] = '-';
		n = -n;
	}
	temp[--len] = (n % 10) + '0';
	n = n / 10;
	while (n)
	{
		--len;
		temp[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:47:11 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/14 13:45:28 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		trim(const char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '0'
			|| s[i] == '\r' || s[i] == '\f' || s[i] == '\v')
		i++;
	return (i);
}

int				ft_atoi(const char *s)
{
	int answer;
	int	i;
	int	neg;

	i = trim(s);
	answer = 0;
	neg = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = 1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		answer = answer * 10 + s[i] - 48;
		i++;
	}
	if (neg)
		return (-answer);
	return (answer);
}

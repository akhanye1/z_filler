/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 11:26:12 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/16 15:04:39 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*find;
	t_list		*iter;

	if (!alst || !*alst)
		return ;
	iter = *alst;
	while (iter)
	{
		find = iter->next;
		ft_lstdelone(&iter, del);
		iter = find;
	}
	*alst = NULL;
}

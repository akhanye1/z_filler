/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 11:48:45 by zphakath          #+#    #+#             */
/*   Updated: 2017/07/29 15:00:00 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_list;
	t_list		*prev_list;

	prev_list = f(lst);
	new_list = prev_list;
	while (lst->next != NULL)
	{
		prev_list->next = f(lst->next);
		prev_list = prev_list->next;
		lst = lst->next;
	}
	return (new_list);
}

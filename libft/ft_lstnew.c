/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:40:54 by zphakath          #+#    #+#             */
/*   Updated: 2017/08/16 14:58:46 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mylist;

	if (!(mylist = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(mylist->content = (t_list *)ft_memalloc(sizeof(t_list))))
			return (NULL);
		ft_memcpy(mylist->content, content, content_size);
		mylist->content_size = content_size;
	}
	else
	{
		mylist->content = NULL;
		mylist->content_size = 0;
	}
	mylist->next = NULL;
	return (mylist);
}

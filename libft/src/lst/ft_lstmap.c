/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:36:20 by abosch            #+#    #+#             */
/*   Updated: 2019/04/10 16:51:03 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	**tmp;

	if (!lst)
		return (NULL);
	newlist = f(lst);
	tmp = &newlist;
	while (lst->next)
	{
		lst = lst->next;
		tmp = &(*tmp)->next;
		*tmp = f(lst);
	}
	return (newlist);
}

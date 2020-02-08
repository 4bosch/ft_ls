/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:56:36 by abosch            #+#    #+#             */
/*   Updated: 2020/02/07 13:56:37 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/list.h"

void	ft_lstinsert(t_list *lst, t_list *new)
{
	t_list	*next;

	if (lst == NULL || new == NULL)
		return ;
	next = lst->next;
	lst->next = new;
	new->next = next;
}

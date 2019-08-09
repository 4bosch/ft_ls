/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:48:16 by abosch            #+#    #+#             */
/*   Updated: 2019/04/12 15:21:58 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"
#include "ft/list.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	tmp->next = NULL;
	if (content)
	{
		if (!(tmp->content = ft_memalloc(content_size)))
		{
			free(tmp);
			return (NULL);
		}
		ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	else if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	return (tmp);
}

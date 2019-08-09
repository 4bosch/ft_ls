/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:50:17 by abosch            #+#    #+#             */
/*   Updated: 2019/04/23 17:47:22 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/list.h"
#include "ft/tmp.h"

void	ft_lstswap(t_list *lst, int a, int b)
{
	void	*data;
	int		len;
	t_list	*tmp1;
	t_list	*tmp2;

	len = ft_lstlen(lst);
	if (a + 1 > len || b + 1 > len || a < 0 || b < 0)
		ft_puterr("Error in parameters : wrong index", 2);
	else
	{
		tmp1 = ft_lstgeti(lst, a);
		tmp2 = ft_lstgeti(lst, b);
		data = tmp1->content;
		tmp1->content = tmp2->content;
		tmp2->content = data;
	}
}

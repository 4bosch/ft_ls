/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:14:49 by abosch            #+#    #+#             */
/*   Updated: 2018/11/10 12:32:58 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

void	*ft_memalloc(size_t size)
{
	void *tmp;

	if (!(tmp = malloc(size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}

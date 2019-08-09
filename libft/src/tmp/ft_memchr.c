/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:10:50 by abosch            #+#    #+#             */
/*   Updated: 2018/11/15 16:26:42 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t cnt;

	cnt = -1;
	while (++cnt < n)
		if (((unsigned char*)s)[cnt] == (unsigned char)c && n != cnt)
			return ((void*)s + cnt);
	return (NULL);
}

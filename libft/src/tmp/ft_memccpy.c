/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:18:04 by abosch            #+#    #+#             */
/*   Updated: 2018/11/15 16:33:39 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t cnt;

	cnt = -1;
	while (++cnt < n)
		if (((unsigned char*)src)[cnt] == (unsigned char)c)
		{
			ft_memcpy(dst, src, cnt + 1);
			return (dst + cnt + 1);
		}
	ft_memcpy(dst, src, n);
	return (NULL);
}

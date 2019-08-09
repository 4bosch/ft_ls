/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:03:03 by abosch            #+#    #+#             */
/*   Updated: 2018/11/08 11:27:45 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (src - dst > 0)
		return (ft_memcpy(dst, src, len));
	while (len--)
		((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	return (dst);
}

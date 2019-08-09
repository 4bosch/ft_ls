/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:31:35 by abosch            #+#    #+#             */
/*   Updated: 2018/11/09 10:58:12 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t res;
	size_t len_dst;

	len_dst = ft_strlen(dst);
	res = ft_strlen(src);
	res += (len_dst >= size ? size : len_dst);
	dst += len_dst;
	while (*src && ++len_dst < size)
		*dst++ = *src++;
	*dst = '\0';
	return (res);
}

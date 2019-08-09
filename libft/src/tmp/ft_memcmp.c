/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:28:18 by abosch            #+#    #+#             */
/*   Updated: 2018/11/14 16:59:49 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	while (--n && ((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
		i++;
	return (((unsigned char*)s1)[i] - (((unsigned char*)s2)[i]));
}

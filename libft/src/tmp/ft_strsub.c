/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:22:47 by abosch            #+#    #+#             */
/*   Updated: 2018/11/22 17:17:16 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*tmp;

	if (!s || !(tmp = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (len--)
		tmp[i++] = s[start++];
	return (tmp);
}

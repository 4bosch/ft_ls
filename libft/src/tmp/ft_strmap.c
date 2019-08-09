/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:20:59 by abosch            #+#    #+#             */
/*   Updated: 2018/11/10 12:40:54 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

char		*ft_strmap(const char *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	if (!s)
		return (NULL);
	if (!(tmp = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
		tmp[i++] = f(*s++);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:48:05 by abosch            #+#    #+#             */
/*   Updated: 2018/11/10 12:41:47 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		i;

	if (!s)
		return (NULL);
	if (!(tmp = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
	{
		tmp[i] = f(i, *s++);
		i++;
	}
	return (tmp);
}

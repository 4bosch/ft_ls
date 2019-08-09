/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:42:49 by abosch            #+#    #+#             */
/*   Updated: 2018/11/15 17:04:01 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

static char		*ft_strrev(char *begin)
{
	char		*str_rev;
	int			i;

	i = ft_strlen(begin);
	if (!(str_rev = ft_strnew(i)))
		return (NULL);
	while (*begin)
		str_rev[--i] = *begin++;
	return (str_rev);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			size;
	long int	tmp;

	size = 1;
	tmp = n;
	while (n /= 10)
		size++;
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (tmp < 0)
	{
		str[size] = '-';
		tmp = -tmp;
	}
	while (tmp)
	{
		str[n++] = (tmp % 10) + '0';
		tmp /= 10;
	}
	if (n != size)
		str[n++] = '0';
	return (ft_strrev(str));
}

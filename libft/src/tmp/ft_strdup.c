/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:11:32 by abosch            #+#    #+#             */
/*   Updated: 2018/11/22 17:24:10 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

char		*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	if (!(res = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}

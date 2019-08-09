/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:39:22 by abosch            #+#    #+#             */
/*   Updated: 2019/04/18 17:46:23 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*res;

	if ((res = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	ft_strdel((char**)&s1);
	ft_strdel((char**)&s2);
	return ((char*)res);
}

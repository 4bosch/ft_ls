/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:45:25 by abosch            #+#    #+#             */
/*   Updated: 2018/11/14 17:37:10 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int len;

	if (*needle == '\0')
		return ((char*)haystack);
	i = -1;
	len = ft_strlen(needle);
	while (haystack[++i])
		if (ft_strncmp(haystack + i, needle, len) == 0)
			return ((char*)haystack + i);
	return (NULL);
}

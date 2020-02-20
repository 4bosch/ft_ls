/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curly_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:50:09 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:50:11 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/curly_utils.h"

#include <string.h>

size_t	skip_to_colsing_curly(char **str)
{
	size_t	i;

	i = 0;
	while ((*str)[i] != '}' && (*str)[i] != '\0')
		++i;
	if ((*str)[i] == '\0')
		i = 0;
	return (i);
}

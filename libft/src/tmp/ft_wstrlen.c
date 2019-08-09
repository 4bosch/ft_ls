/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:43:19 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/15 21:05:41 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"
#include <string.h>
#include <wchar.h>

size_t			ft_wstrlen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
		++len;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_utfelen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:15:37 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/16 11:31:04 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"
#include <stdint.h>

int8_t	ft_wchar_utfelen(wchar_t c)
{
	if (c < 127)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else
		return (4);
}

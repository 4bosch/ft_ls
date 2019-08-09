/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_utfe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 21:38:32 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/16 11:25:24 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

static void		wchar_two(char **str, wchar_t c)
{
	unsigned char one;
	unsigned char two;

	one = 192 + ((c & 1984) >> 6);
	two = 128 + (c & 63);
	(*str)[0] = one;
	(*str)[1] = two;
	*str += 2;
}

static void		wchar_three(char **str, wchar_t c)
{
	unsigned char one;
	unsigned char two;
	unsigned char three;

	one = 224 + ((c & 64440) >> 12);
	two = 128 + ((c & 4032) >> 6);
	three = 128 + (c & 63);
	(*str)[0] = one;
	(*str)[1] = two;
	(*str)[2] = three;
	*str += 3;
}

static void		wchar_four(char **str, wchar_t c)
{
	unsigned char one;
	unsigned char two;
	unsigned char three;
	unsigned char four;

	one = 240 + ((c & 917504) >> 18);
	two = 128 + ((c & 126976) >> 12);
	three = 128 + ((c & 4032) >> 6);
	four = 128 + (c & 63);
	(*str)[0] = one;
	(*str)[1] = two;
	(*str)[2] = three;
	(*str)[3] = four;
	*str += 4;
}

size_t			ft_wstr_utfe(wchar_t *str, char **res)
{
	size_t	tmp;

	tmp = ft_wstr_utfelen(str);
	*res = ft_strnew(tmp);
	while (*str != '\0')
	{
		if (*str < 127)
		{
			**res = *str;
			++(*res);
		}
		else if (*str < 2048)
			wchar_two(res, *str);
		else if (*str < 65536)
			wchar_three(res, *str);
		else
			wchar_four(res, *str);
		++str;
	}
	**res = '\0';
	*res -= tmp;
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 21:27:20 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/10 15:39:31 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

#include "internal/output.h"
#include "internal/type_utils.h"

#include <stdlib.h>

void	type_cc(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	wchar_t		c;

	c = va_arg(ap, wchar_t);
	conv.len = ft_wchar_utfe(c, &conv.str);
	spec->flags &= ~(F_HASH | F_PLUS | F_BLANK | F_PRECI);
	spec->precision = 0;
	write_spec(buf, spec, &conv);
	free(conv.str);
}

void	type_ss(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	wchar_t		*wide;
	char		null[7];

	wide = va_arg(ap, wchar_t*);
	conv.len = ft_wstr_utfe(wide, &conv.str);
	if (conv.str == NULL)
	{
		conv.str = ft_strcpy(null, "(null)");
		conv.len = ft_strlen(conv.str);
	}
	spec->flags &= ~(F_PLUS | F_HASH | F_BLANK);
	if (spec->precision < conv.len && spec->flags & F_PRECI)
	{
		conv.len = ft_utfecut_index(conv.str, spec->precision);
		spec->precision = conv.len;
	}
	else
		spec->precision = conv.len;
	write_spec(buf, spec, &conv);
	free(conv.str);
}

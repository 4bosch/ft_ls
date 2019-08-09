/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:24:56 by abosch            #+#    #+#             */
/*   Updated: 2019/04/10 15:29:53 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

#include "internal/integers.h"
#include "internal/output.h"
#include "internal/type_utils.h"

#include <stdlib.h>
#include <string.h>

void	type_di(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	intmax_t	nbr;
	char		str[21];

	nbr = get_cast_arg(ap, spec->size);
	conv.str = ft_llitosa_base(nbr, 10, str);
	if (nbr < 0)
	{
		++conv.str;
		spec->flags |= F_NEG;
	}
	conv.len = ft_strlen(conv.str);
	if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	spec->flags &= ~F_HASH;
	if (spec->flags & F_PRECI && nbr == 0)
		conv.len = 0;
	if (spec->flags & F_PRECI)
		spec->flags &= ~F_ZERO;
	write_spec(buf, spec, &conv);
	if (spec->flags & F_NEG)
		--conv.str;
	if (spec->flags & F_QUOTE)
		free(conv.str);
}

void	type_u(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	size_t		nbr;
	char		str[21];

	nbr = get_cast_arg_unsigned(ap, spec->size);
	conv.str = ft_lluitosa_base(nbr, 10, str);
	conv.len = ft_strlen(conv.str);
	if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	spec->flags &= ~(F_HASH | F_PLUS | F_BLANK);
	if (spec->flags & F_PRECI)
	{
		if (nbr == 0)
			conv.len = 0;
		spec->flags &= ~F_ZERO;
	}
	write_spec(buf, spec, &conv);
	if (spec->flags & F_QUOTE)
		free(conv.str);
}

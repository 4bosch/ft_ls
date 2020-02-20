/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:52:39 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:52:40 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "internal/floats.h"
#include "internal/integers.h"
#include "internal/output.h"
#include "internal/percent.h"

#include <stdlib.h>

void	type_f(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	char		err[5];
	double		nbr;

	if (spec->size == SIZE_LLL)
	{
		type_ff(ap, spec, buf);
		return ;
	}
	nbr = va_arg(ap, double);
	if (!(spec->flags & F_PRECI))
		spec->precision = 6;
	if ((conv.str = ftoa(nbr, spec->precision)) == NULL)
		conv.str = ft_strcpy(err, "(-1)");
	else if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	conv.len = ft_strlen(conv.str);
	if (!(spec->flags & F_HASH) && spec->precision == 0)
		conv.str[conv.len - 1] = '\0';
	write_percent(spec, &conv, buf);
	free(conv.str);
}

void	type_ff(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string		conv;
	char			err[5];
	long double		nbr;

	if (spec->size == SIZE_L)
	{
		type_f(ap, spec, buf);
		return ;
	}
	nbr = va_arg(ap, long double);
	if (!(spec->flags & F_PRECI))
		spec->precision = 6;
	if ((conv.str = ftoa(nbr, spec->precision)) == NULL)
		conv.str = ft_strcpy(err, "(-1)");
	else if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	conv.len = ft_strlen(conv.str);
	if (!(spec->flags & F_HASH) && spec->precision == 0)
		conv.str[conv.len - 1] = '\0';
	write_percent(spec, &conv, buf);
	free(conv.str);
}

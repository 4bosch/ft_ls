/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:52:14 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:52:15 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/args.h"
#include "internal/integers.h"
#include "internal/percent.h"
#include "internal/specifier.h"

#include <string.h>

void	get_spec_flags(t_spec *spec, char **str)
{
	while (**str == '-' || **str == '+' || **str == '0' || **str == ' '
			|| **str == '#' || **str == '\'')
	{
		if (**str == '-')
			spec->flags |= F_MINUS;
		else if (**str == '+')
		{
			spec->flags |= F_PLUS;
			spec->flags &= ~F_BLANK;
		}
		else if (**str == '#')
			spec->flags |= F_HASH;
		else if (**str == '0' && ((spec->flags & F_MINUS) == 0))
			spec->flags |= F_ZERO;
		else if (**str == ' ' && ((spec->flags & F_PLUS) == 0))
			spec->flags |= F_BLANK;
		else if (**str == '\'')
			spec->flags |= F_QUOTE;
		(*str)++;
	}
}

void	get_spec_precision(t_spec *spec, char **str)
{
	if (**str == '.')
	{
		++(*str);
		spec->flags |= F_PRECI;
		spec->precision = get_number(str);
	}
}

char	get_spec_size_one(char **str, char size)
{
	if (**str == 'l')
		size = SIZE_L;
	else if (**str == 'h')
		size = SIZE_H;
	else if (**str == 'L')
		size = SIZE_LLL;
	else if (**str == 'j')
		size = SIZE_J;
	else if (**str == 'z')
		size = SIZE_Z;
	if (size != 0)
		*str += 1;
	return (size);
}

char	get_spec_size_two(char **str, char size)
{
	if ((*str)[0] == 'l' && (*str)[1] == 'l')
		size = SIZE_LL;
	else if ((*str)[0] == 'h' && (*str)[1] == 'h')
		size = SIZE_HH;
	if (size != 0)
		*str += 2;
	return (size);
}

void	get_specifier(t_spec *spec, char **str, va_list ap)
{
	spec->flags = 0;
	spec->width = 0;
	spec->precision = 0;
	spec->size = 0;
	get_spec_flags(spec, str);
	while (**str == '*' || (**str >= '0' && **str <= '9'))
		spec->width = switch_number_star(ap, str);
	if (spec->width < 0)
	{
		spec->flags |= F_MINUS;
		spec->width = -spec->width;
	}
	if (**str == '.')
	{
		++(*str);
		spec->flags |= F_PRECI;
		spec->precision = switch_number_star(ap, str);
		if (spec->precision < 0)
			spec->flags &= ~F_PRECI;
	}
	if ((spec->size = get_spec_size_two(str, spec->size)) == 0)
		spec->size = get_spec_size_one(str, spec->size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:49:58 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:49:59 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/integers.h"
#include "internal/percent.h"

#include <stdarg.h>
#include <string.h>
#include <stdint.h>

int		get_star(va_list ap, char **str)
{
	int		nbr;

	(*str)++;
	nbr = va_arg(ap, int);
	return (nbr);
}

int		switch_number_star(va_list ap, char **str)
{
	if (**str == '*')
		return (get_star(ap, str));
	else
		return (get_number(str));
}

void	get_arg(va_list og, va_list ap, char **str)
{
	char	*bak;
	int		n;

	bak = *str;
	n = get_number(str);
	if (**str == '$')
	{
		(*str)++;
		va_copy(ap, og);
		while (n-- > 1)
			va_arg(ap, void*);
	}
	else
		*str = bak;
}

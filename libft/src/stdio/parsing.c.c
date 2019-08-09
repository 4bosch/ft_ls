/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:26:45 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/10 15:27:00 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/shared.h"

#include "internal/args.h"
#include "internal/data.h"
#include "internal/output.h"
#include "internal/specifier.h"

#include <unistd.h>

t_func	get_function_type(char c)
{
	int		i;

	i = 0;
	while (g_typetab[i].type != c && g_typetab[i].type != '\0')
		++i;
	return (g_typetab[i].func);
}

void	use_function(va_list og, va_list ap, char **str, t_buf *buf)
{
	t_spec		spec;
	t_func		function;

	get_arg(og, ap, str);
	get_specifier(&spec, str, ap);
	function = get_function_type(**str);
	if (function != 0)
		function(ap, &spec, buf);
	else
		type_default(**str, &spec, buf);
}

int		parsing(va_list ap, char *str)
{
	va_list		og;
	t_buf		buf;

	buf.index = 0;
	buf.read = 0;
	va_copy(og, ap);
	while (*str)
	{
		if (buf.index == BUFF_SIZE)
		{
			print_buf(&buf);
			buf.read += 1;
		}
		if (*str != '%')
		{
			buf.data[buf.index++] = *str;
			buf.read += 1;
		}
		else if (*str++ == '%')
			use_function(og, ap, &str, &buf);
		++str;
	}
	write(1, buf.data, buf.index);
	return (buf.read);
}

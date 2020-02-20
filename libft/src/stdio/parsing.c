/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:52:01 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:52:05 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/parsing.h"

#include "internal/curly.h"
#include "internal/percent.h"

#include <unistd.h>

static void		choose(va_list og, va_list ap, char **fmt, t_buf *buf)
{
	if (**fmt == '%')
		percent(og, ap, fmt, buf);
	else if ((*fmt)[1] == '{')
	{
		++(*fmt);
		buf->data[buf->index++] = **fmt;
		buf->read += 1;
	}
	else if (**fmt == '{')
		curly(fmt, buf);
}

int				parsing(int fd, char *fmt, va_list ap)
{
	va_list		og;
	t_buf		buf;

	buf.index = 0;
	buf.read = 0;
	buf.fd = fd;
	va_copy(og, ap);
	while (*fmt != '\0')
	{
		if (buf.index == BUFF_SIZE)
			print_buf(&buf);
		if (*fmt != '%' && *fmt != '{')
		{
			buf.data[buf.index++] = *fmt;
			buf.read += 1;
		}
		else
			choose(og, ap, &fmt, &buf);
		++fmt;
	}
	write(buf.fd, buf.data, buf.index);
	return (buf.read);
}

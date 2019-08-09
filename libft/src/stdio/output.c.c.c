/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:41:45 by abosch            #+#    #+#             */
/*   Updated: 2019/04/10 15:26:31 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"
#include "internal/output.h"
#include "internal/type_utils.h"

#include <string.h>
#include <unistd.h>

void	print_buf(t_buf *buf)
{
	write(1, buf->data, buf->index);
	buf->index = 0;
}

void	write_char(t_buf *buf, char c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		buf->data[buf->index] = c;
		++buf->index;
		if (buf->index == BUFF_SIZE)
		{
			print_buf(buf);
			buf->index = 0;
		}
	}
	buf->read += len;
}

void	write_str(t_buf *buf, char *str, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		buf->data[buf->index] = str[i];
		buf->index++;
		if (buf->index == BUFF_SIZE)
		{
			print_buf(buf);
			buf->index = 0;
		}
	}
	buf->read += len;
}

void	write_spec(t_buf *buf, t_spec *spec, t_string *conv)
{
	get_diff(spec, conv->len);
	if (spec->flags & F_MINUS)
	{
		put_prefix(buf, spec);
		put_preci(buf, spec, conv);
		write_str(buf, conv->str, conv->len);
		put_width(buf, spec, conv->len);
		return ;
	}
	if (spec->flags & F_ZERO)
	{
		put_prefix(buf, spec);
		put_width(buf, spec, conv->len);
	}
	else
	{
		put_width(buf, spec, conv->len);
		put_prefix(buf, spec);
	}
	put_preci(buf, spec, conv);
	write_str(buf, conv->str, conv->len);
}

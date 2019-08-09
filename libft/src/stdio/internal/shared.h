/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:26:35 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/19 18:09:24 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include <stdarg.h>

/*
** CONSTANTS
*/
# define BUFF_SIZE	1024
# define F_MINUS	1
# define F_PLUS		2
# define F_ZERO		4
# define F_BLANK	8
# define F_HASH		16
# define F_QUOTE	32
# define F_PRECI	64
# define F_NEG		128

# define SIZE_H		1
# define SIZE_HH	2
# define SIZE_L		3
# define SIZE_LL	4
# define SIZE_LLL	4
# define SIZE_J		5
# define SIZE_Z		6

typedef struct		s_buf
{
	int				read;
	int				index;
	char			data[BUFF_SIZE];
}					t_buf;

typedef struct		s_spec
{
	char			flags;
	char			size;
	int				diff;
	int				width;
	char			*prefix;
	int				prefix_len;
	int				precision;
}					t_spec;

typedef struct		s_string
{
	char			*str;
	int				len;
}					t_string;

typedef void		(*t_func)(va_list ap, t_spec *, t_buf *);

typedef struct		s_typefunc
{
	char			type;
	t_func			func;
}					t_typefunc;

/*
** SHARED_H
*/
#endif

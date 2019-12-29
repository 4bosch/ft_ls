/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:17:52 by abosch            #+#    #+#             */
/*   Updated: 2019/04/10 17:24:33 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H
# include <stdarg.h>

int				ft_printf(const char *restrict fmt, ...);
int				ft_dprintf(int fd, const char *restrict fmt, ...);
int				ft_vdprintf(int fd, const char *restrict fmt, va_list ap);

#endif

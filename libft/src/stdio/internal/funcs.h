/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:26:58 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/19 12:39:05 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H
# include "shared.h"
# include "output.h"

void	type_c(va_list ap, t_spec *spec, t_buf *buf);
void	type_cc(va_list ap, t_spec *spec, t_buf *buf);
void	type_s(va_list ap, t_spec *spec, t_buf *buf);
void	type_ss(va_list ap, t_spec *spec, t_buf *buf);
void	type_r(va_list ap, t_spec *spec, t_buf *buf);
void	type_p(va_list ap, t_spec *spec, t_buf *buf);

void	type_di(va_list ap, t_spec *spec, t_buf *buf);
void	type_u(va_list ap, t_spec *spec, t_buf *buf);
void	type_o(va_list ap, t_spec *spec, t_buf *buf);
void	type_u(va_list ap, t_spec *spec, t_buf *buf);
void	type_x(va_list ap, t_spec *spec, t_buf *buf);
void	type_xx(va_list ap, t_spec *spec, t_buf *buf);
void	type_b(va_list ap, t_spec *spec, t_buf *buf);
void	type_bb(va_list ap, t_spec *spec, t_buf *buf);

void	type_f(va_list ap, t_spec *spec, t_buf *buf);

void	type_default(char letter, t_spec *spec, t_buf *buf);

void	type_k(va_list ap, t_spec *spec, t_buf *buf);

/*
** SPECIFIER_H
*/
#endif

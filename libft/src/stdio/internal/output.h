/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:48:45 by abosch            #+#    #+#             */
/*   Updated: 2019/03/19 15:48:30 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H
# include "shared.h"
# include <string.h>

void	print_buf(t_buf *buf);
void	write_str(t_buf *buf, char *str, size_t len);
void	write_char(t_buf *buf, char c, size_t len);
void	write_spec(t_buf *buf, t_spec *spec, t_string *conv);

/*
** SPECIFIER_H
*/
#endif

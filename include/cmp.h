/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:42:33 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:43:00 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMP_H
# define CMP_H

# include "libft.h"
# include "shared.h"
# include "dir.h"

int			name_cmp(t_list *e1, t_list *e2);
int			time_cmp(t_list *e1, t_list *e2);
int			rname_cmp(t_list *e1, t_list *e2);
int			rtime_cmp(t_list *e1, t_list *e2);
int			dname_cmp(t_list *e1, t_list *e2);

#endif

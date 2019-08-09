/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:16:14 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/19 12:38:23 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "funcs.h"
# include "shared.h"

t_typefunc g_typetab[] =
{
	{'c', &type_c},
	{'C', &type_cc},
	{'s', &type_s},
	{'S', &type_ss},
	{'r', &type_r},
	{'p', &type_p},
	{'d', &type_di},
	{'i', &type_di},
	{'o', &type_o},
	{'u', &type_u},
	{'x', &type_x},
	{'X', &type_xx},
	{'b', &type_b},
	{'B', &type_bb},
	{'f', &type_f},
	{'k', &type_k},
	{'\0', 0}
};

/*
** DATA_H
*/
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:43:25 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:45:04 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIR_H
# define DIR_H

# include "shared.h"
# include "libft.h"
# include "option.h"

void	create_dir(char *name, int path_len, int name_len, t_list **list);
void	make_dir(char *name, int path_len, int name_len, t_dir **dir);
void	move_dir(t_list **input, t_list **dir);

#endif

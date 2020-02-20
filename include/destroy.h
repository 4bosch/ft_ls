/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:43:16 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:43:17 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY_H
# define DESTROY_H

# include "libft.h"
# include "file.h"
# include "dir.h"

void	destroy_dir(t_list *dir);
void	destroy_files(t_list **tab_files);

#endif

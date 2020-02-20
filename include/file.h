/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:43:39 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:43:41 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <sys/errno.h>

# include "shared.h"
# include "libft.h"
# include "option.h"
# include "dir.h"

int	create_file(char *path, char *name, t_list **list, int16_t option);

#endif

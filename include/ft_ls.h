/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:43:48 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:43:49 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>

# include "shared.h"
# include "libft.h"
# include "file.h"
# include "print.h"
# include "option.h"
# include "cmp.h"
# include "destroy.h"

void	ft_ls(char **av, int ac);

#endif

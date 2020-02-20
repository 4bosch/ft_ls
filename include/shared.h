/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:44:22 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:47:02 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct	s_file
{
	char		*name;
	struct stat	sbuf;
	int			path_len;
	int			name_len;
}				t_file;

typedef struct	s_dir
{
	char		*name;
	int			path_len;
	int			name_len;
}				t_dir;

#endif

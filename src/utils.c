/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:20:37 by abosch            #+#    #+#             */
/*   Updated: 2019/10/02 16:23:48 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h> /////////////////////////DELETE

t_file		*create_file(char *name)
{
	t_file	*ret;

	if (!(ret = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	ret->name = ft_strnew(ft_strlen(name));
	ft_strcpy(ret->name, name);
	lstat(name, &(ret->sbuf));
	return (ret);
}

int			name_cmp(t_list e1, t_list e2)
{
	return((ft_strcmp(((t_file*)e1.content)->name, ((t_file*)e2.content)->name) < 0) ? 1 : 0);
}

int			time_cmp(t_list e1, t_list e2)
{
	int diff;

	diff = ((t_file*)e1.content)->sbuf.st_mtimespec.tv_sec - ((t_file*)e2.content)->sbuf.st_mtimespec.tv_sec;
	if (diff == 0)
	{
		diff = ((t_file*)e1.content)->sbuf.st_mtimespec.tv_nsec - ((t_file*)e2.content)->sbuf.st_mtimespec.tv_nsec;
		if (diff == 0)
			return (name_cmp(e1, e2));
		else if (diff > 0)
			return (1);
		else
			return (0);
	}
	else if (diff > 0)
		return (1);
	else
		return (0);
}

int			rname_cmp(t_list e1, t_list e2)
{
	return (name_cmp(e2, e1));
}

int			rtime_cmp(t_list e1, t_list e2)
{
	return (time_cmp(e2, e1));
}

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

int			name_sort(t_list e1, t_list e2)
{
	char	*name1;
	char	*name2;

	name1 = ((t_file*)e1.content)->name;
	name2 = ((t_file*)e2.content)->name;
	if (ft_strcmp(name1, name2) < 0)
		return (1);
	else
		return (0);
}

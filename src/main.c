/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:20:18 by abosch            #+#    #+#             */
/*   Updated: 2019/10/02 16:54:19 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// CAS D'ERREUR : opendir, closedir, readdir
// MALLOC A GERER : lstnew, create_file

int			main(int ac, char **av)
{
	int16_t	options;
	t_list	*dir;
	int		len;

	options = 0;
	dir = get_options(ac, av, &options);
	len = ft_lstlen(dir);
	if (len == 1)
	{
		list_files(((t_dir*)dir->content)->name, options);
	}
	else
	{
		ft_lstquicksort(&dir, &dname_cmp);
		while (dir != NULL)
		{
			ft_printf("%s:\n", ((t_dir*)dir->content)->name);
			list_files(((t_dir*)dir->content)->name, options);
			if (dir->next != NULL)
				ft_printf("\n");
			dir = dir->next;
		}
	}
	return (1);
}

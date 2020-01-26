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


static void	printone(char *name, int16_t opt)
{
	t_list	*file;
	t_list	*tab[2];

	file = NULL;
	create_file("./", name, &file, opt);
	tab[0] = file;
	tab[1] = NULL;
	if (opt & O_LFORMAT)
		print_files(tab, 0, 0);
	else
		print_files(tab, 1, 0);
}

int			main(int ac, char **av)
{
	int16_t	options;
	t_list	*dir;
	int		len;

	options = 0;
	dir = NULL;
	get_options(ac, av, &options, &dir);
	len = ft_lstlen(dir);
	if (len == 1)
	{
		if (is_dir(D(dir)->name))
			list_files(D(dir)->name, D(dir)->name_len + D(dir)->path_len, options);
		else
			printone(D(dir)->name, options);
	}
	else
	{
		ft_lstquicksort(&dir, &dname_cmp);
		while (dir != NULL)
		{
			if (is_dir(D(dir)->name))
			{
				ft_printf("%.*s:\n", D(dir)->name_len, D(dir)->name + D(dir)->path_len);
				list_files(D(dir)->name, D(dir)->name_len + D(dir)->path_len, options);
			}
			else
				printone(D(dir)->name, options);
			if (dir->next != NULL)
				ft_printf("\n");
			dir = dir->next;
		}
	}
	return (0);
}

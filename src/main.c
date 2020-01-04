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

static int	is_dir(char *path)
{
	struct stat sbuf;

	lstat(path, &sbuf);
	if ((sbuf.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else
		return (0);
}

static void	printone(char *name, int16_t opt)
{
	t_list	*file;
	t_list	*tab[2];

	file = NULL;
	create_file("", name, &file, opt);
	tab[0] = file;
	tab[1] = NULL;
	if (opt & O_LFORMAT)
		print_files(tab, 0);
	else
		print_files(tab, 1);
}

int			main(int ac, char **av)
{
	int16_t	options;
	t_list	*dir;
	int		len;

	options = 0;
	get_options(ac, av, &options, &dir);
	len = ft_lstlen(dir);
	if (len == 1)
	{
		if (!is_dir(((t_dir*)dir->content)->name))
			printone(((t_dir*)dir->content)->name, options);
		else
			list_files(((t_dir*)dir->content)->name, options);
	}
	else
	{
		ft_lstquicksort(&dir, &dname_cmp);
		while (dir != NULL)
		{
			ft_printf("%.*s:\n", ((t_dir*)dir->content)->name_len,
				((t_dir*)dir->content)->name + ((t_dir*)dir->content)->path_len);
			if (!is_dir(((t_dir*)dir->content)->name))
				printone(((t_dir*)dir->content)->name, options);
			else
				list_files(((t_dir*)dir->content)->name, options);
			if (dir->next != NULL)
				ft_printf("\n");
			dir = dir->next;
		}
	}
	return (0);
}

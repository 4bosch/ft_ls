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

static t_list	**sort(t_list **files, int16_t opt)
{
	if (opt & O_REVERSE)
	{
		if (opt & O_TIME)
			return (ft_lstquicksorttab(files, &rtime_cmp));
		else
			return (ft_lstquicksorttab(files, &rname_cmp));
	}
	else
	{
		if (opt & O_TIME)
			return (ft_lstquicksorttab(files, &time_cmp));
		else
			return (ft_lstquicksorttab(files, &name_cmp));
	}
}

static void		list_files(char *path, int16_t opt)
{
	DIR				*dirp;
	struct dirent	*ret;
	t_list			*files;
	t_list			**tab_files;

	files = NULL;
	if(!(dirp = opendir(path)))
		return ;		//Cas erreur a implementer
	create_file(readdir(dirp)->d_name, &files, opt);
	while ((ret = readdir(dirp)))
		create_file(ret->d_name, &files, opt);
	tab_files = sort(&files, opt);
	//ft_printf("after sort\n");
	if (opt & O_LFORMAT) 
		print_files(tab_files, 0);
	else	// si long format 
		print_files(tab_files, 1);
	if(closedir(dirp) == -1)
		return ;		//cas erreur a implementer
}


int			main(int ac, char **av)
{
	int16_t	options;
	t_list	*dir;
	int		len;

	options = 0;
	dir = get_options(ac, av, &options);
	len = ft_lstlen(dir);
	if (len == 1)
		list_files((char*)dir->content, options);
	else
	{
		//ft_lstquicksort(&dir, &dname_cmp);
		while (dir != NULL)
		{
			ft_printf("%s:\n", (char*)dir->content);
			list_files((char*)dir->content, options);
			if (dir->next != NULL)
				ft_printf("\n");
			dir = dir->next;
		}
	}
	return (0);
}

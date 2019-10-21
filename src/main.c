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
#include "option.h"

// CAS D'ERREUR : opendir, closedir, readdir
// MALLOC A GERER : lstnew, create_file

static t_list	**sort(t_list *files, int16_t opt)
{
	if (opt & O_REVERSE)
	{
		if (opt & O_TIME)
			return (ft_lstquicksort(&files, &rtime_cmp));
		else
			return (ft_lstquicksort(&files, &rname_cmp));
	}
	else
	{
		if (opt & O_TIME)
			return (ft_lstquicksort(&files, &time_cmp));
		else
			return (ft_lstquicksort(&files, &name_cmp));
	}
}

static void		list_files(char *path, int16_t opt)
{
	DIR				*dirp;
	struct dirent	*ret;
	t_list			*files;
	t_list			**tab_files;

	if(!(dirp = opendir(path)))
		return ;		//Cas erreur a implementer
	files = ft_lstnew(create_file(readdir(dirp)->d_name), sizeof(t_file));
	while ((ret = readdir(dirp)))
		ft_lstadd(&files, ft_lstnew(create_file(ret->d_name), sizeof(t_file)));
	//parse option pour selectionner la fonction de comparaison qui convient
	tab_files = sort(files, opt);
	if (opt & O_LFORMAT) //si pas long format
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

	options = 0;
	dir = get_options(ac, av, &options);
	printf("%d\n", options);
	list_files((char*)dir->content, options);
}

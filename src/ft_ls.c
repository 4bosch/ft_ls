/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
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
void	list_files(char *path)
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
	tab_files = ft_lstquicksort(&files, &name_cmp);
	if (1) //si pas long format
		print_files(tab_files, 1);
	else	// si long format 
		print_files(tab_files, 0);
	if(closedir(dirp) == -1)
		return ;		//cas erreur a implementer
}

int		main(int ac, char **av)
{
	if (ac == 1)  //ls sans args
	{
		list_files("./");
	}
	else	//ls avec args
		return (1);
	if (av[0][0] == 0)
		return (0);
	return (0);
}

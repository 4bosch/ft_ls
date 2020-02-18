/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:26:42 by abosch            #+#    #+#             */
/*   Updated: 2020/02/18 13:26:46 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destroy.h"

void		destroy_dir(t_list *dir)
{
	t_list *del;

	while (dir != NULL)
	{
		del = dir;
		dir = dir->next;
		free(((t_dir*)del->content)->name);
		free(del->content);
		free(del);
	}
}

void		destroy_files(t_list **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
	{
		free(((t_file*)tab[i]->content)->name);
		free(tab[i]->content);
		free(tab[i]);
	}
	free(tab);
}

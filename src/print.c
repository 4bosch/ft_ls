/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:20:27 by abosch            #+#    #+#             */
/*   Updated: 2019/10/02 16:53:28 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	long_print(t_file *file)
{
	file = NULL;
}

void		print_files(t_list **tab, char bool)
{
	int i;

	i = -1;
	if (bool)
		while (tab[++i] != NULL)
			ft_printf("%s\n", ((t_file*)tab[i]->content)->name);
	else
		while (tab[++i] != NULL)
			long_print((t_file*)tab[i]->content);
}

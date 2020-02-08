/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:20:18 by abosch            #+#    #+#             */
/*   Updated: 2020/02/08 17:15:09 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// CAS D'ERREUR : opendir, closedir, readdir
// MALLOC A GERER : lstnew, create_file

int	g_status = 0;

int			main(int ac, char **av)
{
	ft_ls(av, ac);
	//ft_printf("%zu :|:  %zu\n",  sizeof(t_file), sizeof(t_dir));
	while(1);
	return (g_status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:20:27 by abosch            #+#    #+#             */
/*   Updated: 2020/02/18 15:56:32 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	init_max(t_max *max)
{
	max->nlink = 0;
	max->user = 0;
	max->group = 0;
	max->size = 0;
	max->sum = 0;
}

static int	ilen(size_t nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	fill_max(t_list **tab, t_max *max)
{
	int		i;
	size_t	len;

	i = -1;
	while (tab[++i] != NULL)
	{
		if (max->nlink < ((t_file*)tab[i]->content)->sbuf.st_nlink)
			max->nlink = ((t_file*)tab[i]->content)->sbuf.st_nlink;
		len = ft_strlen(getpwuid(((t_file*)tab[i]->content)->sbuf.st_uid)
			->pw_name);
		if (max->user < len)
			max->user = len;
		len = ft_strlen(getgrgid(((t_file*)tab[i]->content)->sbuf.st_gid)
			->gr_name);
		if (max->group < len)
			max->group = len;
		if (max->size < ((t_file*)tab[i]->content)->sbuf.st_size)
			max->size = ((t_file*)tab[i]->content)->sbuf.st_size;
	}
	max->nlink = ilen(max->nlink);
	max->size = ilen(max->size);
	i = -1;
	while (tab[++i] != NULL)
		max->sum += ((t_file *)tab[i]->content)->sbuf.st_blocks;
}

void		print_files(t_list **tab, char dir, int16_t opt)
{
	int		i;
	t_max	max;

	i = -1;
	if (tab == NULL)
		return ;
	else if (!(O_LFORMAT & opt))
	{
		while (tab[++i] != NULL)
			ft_printf("%s\n", ((t_file*)tab[i]->content)->name +
				((t_file*)tab[i]->content)->path_len);
	}
	else
	{
		init_max(&max);
		fill_max(tab, &max);
		if (dir)
			ft_printf("total %llu\n", max.sum);
		while (tab[++i] != NULL)
			long_print((t_file*)tab[i]->content, max);
	}
	destroy_files(tab);
}

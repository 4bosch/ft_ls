/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:20:37 by abosch            #+#    #+#             */
/*   Updated: 2019/10/02 16:23:48 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	create_file(char *name, t_list **list, int16_t opt)
{
	t_file	*file;
	char	linkbuf[1024];
	int		r;

	if (!(opt & O_ALL) && *name == '.')
		return ;
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		ft_puterr("Malloc failed\n", 2);
	lstat(name, &(file->sbuf));
	if ((opt & O_LFORMAT) && ((file->sbuf.st_mode & S_IFMT) == S_IFLNK))
	{
		r = readlink(file->name, linkbuf, 1024);
		if (r < 0)
		{
			ft_puterr("ft_ls: readlink: ", 2);
			ft_puterr(strerror(errno), 2);
			ft_putchar('\n');
		}
		linkbuf[r] = '\0';
		file->name = ft_strnew(ft_strlen(name) + r + 5);
		file->name = ft_strcpy(file->name, name);
		file->name = ft_strcat(ft_strcat(file->name, " -> "), linkbuf);
	}
	else
	{
		file->name = ft_strnew(ft_strlen(name));
		ft_strcpy(file->name, name);
	}
	if (*list == NULL)
		*list = ft_lstnew(file, sizeof(t_file));
	else
		ft_lstadd(list, ft_lstnew(file, sizeof(t_file)));
}


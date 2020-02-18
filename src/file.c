/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:02 by abosch            #+#    #+#             */
/*   Updated: 2020/02/18 15:54:26 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

static void	fill_file(char *path, char *name, t_file *file)
{
	file->path_len = ft_strlen(path);
	file->name_len = ft_strlen(name);
	file->name = ft_strnew(file->name_len + file->path_len + 1);
	ft_strcpy(file->name, path);
	ft_strcat(file->name, name);
}

static int	file_status(t_file *file)
{
	extern int	g_status;

	if ((lstat(file->name, &file->sbuf)) == -1)
	{
		ft_printerr("ft_ls: %s: %s\n", file->name + file->path_len,
			strerror(errno));
		free(file->name);
		free(file);
		g_status = 1;
		return (1);
	}
	return (0);
}

void		create_file(char *path, char *name, t_list **list, int16_t opt)
{
	t_file	*file;

	if (!(opt & O_ALL) && !(opt & O_ONEFILE) && *name == '.')
		return ;
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		ft_puterr("Malloc failed\n", 2);
	fill_file(path, name, file);
	if (file_status(file))
		return ;
	if (*list == NULL)
		*list = ft_lstnew(file, sizeof(t_file));
	else
		ft_lstadd(list, ft_lstnew(file, sizeof(t_file)));
	free(file);
}

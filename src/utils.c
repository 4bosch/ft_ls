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
#include "shared.h"
#include <errno.h>

static void	status(char *path, char *name, t_file *file)
{
	char	*tmp;
	uint8_t	off;

	off = 0;
	file->path_len = ft_strlen(path);
	file->name_len = ft_strlen(name);
	tmp = ft_strnew(file->name_len + file->path_len + 1);
	ft_strcpy(tmp, path);
	if (ft_strcmp("./", path) != 0)
	{
		ft_strcat(tmp, "/");
		file->path_len++;
	}
	else
		off = 2;
	ft_strcat(tmp, name);
	if((lstat(tmp, &file->sbuf)) == -1)
		perror(strerror(errno));
	file->name = ft_strnew(file->path_len + file->name_len - off);
	ft_strcpy(file->name, tmp + off);
	file->path_len -= off;
	free(tmp);
}

void		create_file(char *path, char *name, t_list **list, int16_t opt)
{
	t_file	*file;
	char	linkbuf[1024];
	char	*tmp;
	int		r;

	if (!(opt & O_ALL) && *name == '.')
		return ;
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		ft_puterr("Malloc failed\n", 2);
	status(path, name, file);
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
		tmp = ft_strnew(ft_strlen(file->name) + r + 5);
		ft_strcpy(tmp, file->name);
		ft_strcat(ft_strcat(tmp, " -> "), linkbuf);
		free(file->name);
		file->name = tmp;
		file->name_len += r + 5;
	}
	if (*list == NULL)
		*list = ft_lstnew(file, sizeof(t_file));
	else
		ft_lstadd(list, ft_lstnew(file, sizeof(t_file)));
}

void		create_dir(char *name, int path_len, int name_len, t_list **list)
{
	t_dir	*dir;

	if (!(dir = (t_dir*)malloc(sizeof(t_dir))))
		ft_puterr("Malloc failed\n", 2);
	dir->path_len = path_len;
	dir->name_len = name_len;
	if (ft_strcmp("./", name) == 0)
	{
		dir->name = ft_strnew(2);
		ft_strcpy(dir->name, name);
	}
	else
	{
		dir->name = ft_strnew(dir->path_len + dir->name_len + 1);
		ft_strncpy(dir->name, name, dir->path_len + dir->name_len);
		ft_strcat(dir->name, "/");
	}
	if (*list == NULL)
		*list = ft_lstnew(dir, sizeof(t_dir));
	else
		ft_lstadd(list, ft_lstnew(dir, sizeof(t_dir)));
}

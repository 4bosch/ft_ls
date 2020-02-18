/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:54:53 by abosch            #+#    #+#             */
/*   Updated: 2020/02/18 14:48:19 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dir.h"

static void	file2dir(t_list **dir)
{
	t_list	*lst;
	t_dir	*tmp;

	lst = *dir;
	while (lst != NULL)
	{
		make_dir(((t_file*)lst->content)->name, ((t_file*)lst->content)
			->path_len, ((t_file*)lst->content)->name_len, &tmp);
		free(((t_file*)lst->content)->name);
		free(lst->content);
		lst->content = tmp;
		lst = lst->next;
	}
}

void		move_dir(t_list **input, t_list **dir)
{
	t_list		*prev;
	t_list		*curr;
	t_list		*next;

	curr = *input;
	prev = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		if (S_ISDIR(((t_file*)curr->content)->sbuf.st_mode))
		{
			if (prev != NULL)
				prev->next = next;
			else
				*input = next;
			ft_lstadd(dir, curr);
			curr = next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	file2dir(dir);
}

void		make_dir(char *name, int path_len, int name_len, t_dir **dir)
{
	if (!(*dir = (t_dir*)malloc(sizeof(t_dir))))
		ft_puterr("Malloc failed\n", 2);
	(*dir)->path_len = path_len;
	(*dir)->name_len = name_len;
	if (ft_strcmp("./", name) == 0)
	{
		(*dir)->name = ft_strnew(2);
		ft_strcpy((*dir)->name, name);
	}
	else
	{
		if (name[path_len + name_len] != '/')
		{
			(*dir)->name = ft_strnew((*dir)->path_len + (*dir)->name_len + 1);
		}
		else
			(*dir)->name = ft_strnew((*dir)->path_len + (*dir)->name_len);
		ft_strncpy((*dir)->name, name, (*dir)->path_len + (*dir)->name_len);
	}
}

void		create_dir(char *name, int path_len, int name_len, t_list **list)
{
	t_dir	*dir;

	make_dir(name, path_len, name_len, &dir);
	if (*list == NULL)
		*list = ft_lstnew(dir, sizeof(t_dir));
	else
		ft_lstadd(list, ft_lstnew(dir, sizeof(t_dir)));
	free(dir);
}

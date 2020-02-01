#include "dir.h"

void		move_dir(t_list **input, t_list **dir)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *input;
	while (tmp->next != NULL)
	{
		next = tmp->next;
		if (S_ISDIR(((t_file*)next->content)->sbuf.st_mode))
		{
			ft_lstadd(dir, next);
			tmp->next = next->next;
		}
		tmp = next;
	}
	if (S_ISDIR(((t_file*)(*input)->content)->sbuf.st_mode))
	{
		ft_lstadd(dir, *input);
		*input = (*input)->next;
	}
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
		if (name[path_len + name_len] != '/')
			dir->name = ft_strnew(dir->path_len + dir->name_len + 1);
		else
			dir->name = ft_strnew(dir->path_len + dir->name_len);
		ft_strncpy(dir->name, name, dir->path_len + dir->name_len);
	}
	if (*list == NULL)
		*list = ft_lstnew(dir, sizeof(t_dir));
	else
		ft_lstadd(list, ft_lstnew(dir, sizeof(t_dir)));
}

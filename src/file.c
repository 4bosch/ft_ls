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

	if((lstat(file->name, &file->sbuf)) == -1)
	{
		ft_printerr("ft_ls: %s: %s\n", file->name + file->path_len, strerror(errno));
		free(file->name);
		free(file);
		g_status = 1;
		return (1);
	}
	return (0);
}

static void	linkinfo(t_file *file)
{
	char	linkbuf[1024];
	char	*tmp;
	int		r;

		r = readlink(file->name, linkbuf, 1024);
		if (r < 0)
			ft_printerr("ft_ls: readlink: %s\n", strerror(errno));
		linkbuf[r] = '\0';
		tmp = ft_strnew(ft_strlen(file->name) + r + 5);
		ft_strcpy(tmp, file->name);
		ft_strcat(ft_strcat(tmp, " -> "), linkbuf);
		free(file->name);
		file->name = tmp;
		file->name_len += r + 5;
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
	if ((opt & O_LFORMAT) && (S_ISLNK(file->sbuf.st_mode)))
		linkinfo(file);
	if (*list == NULL)
		*list = ft_lstnew(file, sizeof(t_file));
	else
		ft_lstadd(list, ft_lstnew(file, sizeof(t_file)));
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
}

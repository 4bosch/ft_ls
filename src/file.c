#include "file.h"

static void	fill_file(char *path, char *name, t_file *file)
{
	file->path_len = ft_strlen(path);
	file->name_len = ft_strlen(name);
	file->name = ft_strnew(file->name_len + file->path_len + 1);
	ft_strcpy(file->name, path);
	ft_strcat(file->name, name);
	if((lstat(file->name, &file->sbuf)) == -1)
		perror(strerror(errno));
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

	if (!(opt & O_ALL) && *name == '.')
		return ;
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		ft_puterr("Malloc failed\n", 2);
	fill_file(path, name, file);
	if ((opt & O_LFORMAT) && ((file->sbuf.st_mode & S_IFMT) == S_IFLNK))
		linkinfo(file);
	if (*list == NULL)
		*list = ft_lstnew(file, sizeof(t_file));
	else
		ft_lstadd(list, ft_lstnew(file, sizeof(t_file)));
}

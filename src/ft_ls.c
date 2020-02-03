#include "ft_ls.h"

static t_list   **sort(t_list *files, int16_t opt)
{
	if (opt & O_REVERSE)
	{
		if (opt & O_TIME)
			return (ft_lstquicksorttab(files, &rtime_cmp));
		else
			return (ft_lstquicksorttab(files, &rname_cmp));
	}
	else
	{
		if (opt & O_TIME)
			return (ft_lstquicksorttab(files, &time_cmp));
		else
			return (ft_lstquicksorttab(files, &name_cmp));
	}
}

void     		list_files(char *path, int pathlen, int16_t opt)
{
	DIR             *dirp;
	struct dirent   *ret;
	t_list          *files;
	t_list          **tab_files;

	files = NULL;
	if (path[pathlen - 1] != '/')
		path[pathlen] = '/';
	if(!(dirp = opendir(path)))
	{
		ft_printerr("ft_ls: %.*s: %s\n", ft_strlen(path) - 1, path, strerror(errno));
		exit(1);
	}
	while ((ret = readdir(dirp)))
		create_file(path, ret->d_name, &files, opt);
	if (files == NULL)
		return ;
	tab_files = sort(files, opt);
	if (opt & O_LFORMAT)
		print_files(tab_files, 0, 1);
	else
		print_files(tab_files, 1, 1);
	if(closedir(dirp) == -1)
		return ;
}

static void print_inputf(t_list *files, int16_t opt)
{
	t_list  **tab;

	if (files == NULL)
		return ;
	tab = sort(files, opt);
	ft_printf("len input : %d\n", ft_lstlen(files));
	if (opt & O_LFORMAT)
		print_files(tab, 0, 0);
	else
		print_files(tab, 1, 0);
}

void			ft_ls(char **av, int ac)
{
	int16_t	options;
	t_list	*dir;
	t_list	*input;

	options = 0;
	dir = NULL;
	input = NULL;
	get_options(ac, av, &options, &input);
	move_dir(&input, &dir);
	print_inputf(input, options);
	ft_printf("1\n");
	ft_lstquicksort(&dir, &dname_cmp);
	while (dir != NULL)
	{
			ft_printf("%.*s:\n", D(dir)->name_len, D(dir)->name + D(dir)->path_len);
			list_files(D(dir)->name, D(dir)->name_len + D(dir)->path_len, options);
		if (dir->next != NULL)
			ft_printf("\n");
		dir = dir->next;
	}
}

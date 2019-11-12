#include "ft_ls.h"

static t_list   **sort(t_list **files, int16_t opt)
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

void     list_files(char *path, int16_t opt)
{
    DIR             *dirp;
    struct dirent   *ret;
    t_list          *files;
    t_list          **tab_files;

    files = NULL;
    if(!(dirp = opendir(path)))
		ft_puterr(strerror(errno), 2);
    create_file(path, readdir(dirp)->d_name, &files, opt);
    while ((ret = readdir(dirp)))
	{
        create_file(path, ret->d_name, &files, opt);
	}
    tab_files = sort(&files, opt);
    if (opt & O_LFORMAT)
        print_files(tab_files, 0);
    else    // si long format
        print_files(tab_files, 1);
    if(closedir(dirp) == -1)
        return ;        //cas erreur a implementer
}

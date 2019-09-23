#include "ft_ls.h"

void	list_files(char *path)
{
	DIR				*dirp;
	struct dirent	*ret;
	t_list			*files;

	if(!(dirp = opendir(path)))
		return ;		//Cas erreur a implementer
		files = ft_lstnew(create_file(readdir(dirp)->d_name), sizeof(t_file));
	while ((ret = readdir(dirp)))
			ft_lstadd(&files, ft_lstnew(create_file(ret->d_name), sizeof(t_file)));
	//fonction de sort
	if (1) //si pas long format
	print_files(files);
	else	// si long format 
		return ; //print_long_files(files);
	if(closedir(dirp) == -1)
		return ;		//cas erreur a implementer
}

int		main(int ac, char **av)
{
	if (ac == 1)  //ls sans args
	{
		list_files("./");
	}
	else	//ls avec args
		return (1);
	if (av[0][0] == 0)
		return (0);
	return (0);
}

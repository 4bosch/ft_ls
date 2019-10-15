# include "print.h"

static void	permissions(t_file *file)
{
	if ((file->sbuf.st_mode & S_IFMT) == S_IFREG)
        ft_printf("-");
	else if ((file->sbuf.st_mode & S_IFMT) == S_IFSOCK)
        ft_printf("s");
    else if ((file->sbuf.st_mode & S_IFMT) == S_IFLNK)
        ft_printf("l");
    else if ((file->sbuf.st_mode & S_IFMT) == S_IFBLK)
        ft_printf("b");
    else if ((file->sbuf.st_mode & S_IFMT) == S_IFDIR)
        ft_printf("d");
    else if ((file->sbuf.st_mode & S_IFMT) == S_IFCHR)
        ft_printf("c");
	else
		ft_printf("p");
    ft_printf((file->sbuf.st_mode & S_IRUSR) ? "r" : "-");
    ft_printf((file->sbuf.st_mode & S_IWUSR) ? "w" : "-");
    ft_printf((file->sbuf.st_mode & S_IXUSR) ? "x" : "-");
    ft_printf((file->sbuf.st_mode & S_IRGRP) ? "r" : "-");
    ft_printf((file->sbuf.st_mode & S_IWGRP) ? "w" : "-");
    ft_printf((file->sbuf.st_mode & S_IXGRP) ? "x" : "-");
    ft_printf((file->sbuf.st_mode & S_IROTH) ? "r" : "-");
    ft_printf((file->sbuf.st_mode & S_IWOTH) ? "w" : "-");
    ft_printf((file->sbuf.st_mode & S_IXOTH) ? "x" : "-");
}

void		long_print(t_file *file, t_max max)
{
	permissions(file);
	ft_printf("  %*d %*s  %*s  %*lld %s\n",max.nlink, file->sbuf.st_nlink, max.user, getpwuid(file->sbuf.st_uid)->pw_name, max.group, getgrgid(file->sbuf.st_gid)->gr_name, max.size, file->sbuf.st_size, file->name);
}

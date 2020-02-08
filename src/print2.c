/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:42 by abosch            #+#    #+#             */
/*   Updated: 2020/02/07 13:55:44 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

#include <time.h>

#define TEN_MILENIA 253402297200
#define SIX_MONTHS 15778800


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
	time_t	now;
	time_t	mtime;
	char	*date;

	now = time(0);
	mtime = file->sbuf.st_mtimespec.tv_sec;
	permissions(file);
	ft_printf("  %*d %*s  %*s  %*lld ",max.nlink, file->sbuf.st_nlink,
			max.user, getpwuid(file->sbuf.st_uid)->pw_name, max.group,
			getgrgid(file->sbuf.st_gid)->gr_name, max.size,
			file->sbuf.st_size);
	date = ctime(&mtime) + 4;
	if (mtime >= TEN_MILENIA)
		ft_printf("%.7s %.5s ", date, date + 20);
	else if ((now - mtime) > SIX_MONTHS
			|| (now < mtime))
		ft_printf("%.7s%5.4s ", date, date + 16);
	else
		ft_printf("%.7s%5.5s ", date, date + 7);
	ft_printf("%s\n", file->name + file->path_len);
}

#include "option.h"

#include <stdio.h> ///////////////////DELETE

static void	active_options(char op, int16_t *opt)
{
	if (op == 'l')
		*opt |= O_LFORMAT;
	else if (op == 'r')
		*opt |= O_REVERSE;
	else if (op == 'R')
		*opt |= O_RECURSIVE;
	else if (op == 't')
		*opt |= O_TIME;
	else if (op == 'a')
		*opt |= O_ALL;
	else if (op == '1')
		*opt |= O_ONE;
	else
	{
		ft_printerr("ft_ls: illegal option -- %c\nusage: ft_ls [-alrRt] [file ...]\n", op);
		exit(1);
	}
}

void			get_options(int ac, char **av, int16_t *opt, t_list **dir)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac && av[i][0] == '-' && (av[i][1] != '-' || (av[i][1] == '-' && av[i][2] != '\0')))
	{
		j = 0;
		while (av[i][++j] != '\0')
			active_options(av[i][j], opt);
	}
	if (i == ac)
	{
		create_dir("./", 0, 2, dir);
		return ;
	}
	else if (av[i][1] == '-')
		i++;
	while (i < ac)
	{
		create_dir(av[i], 0, ft_strlen(av[i]), dir);
		i++;
	}
}

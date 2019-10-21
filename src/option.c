#include "option.h"

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
			else
			{
				ft_putstr_fd("ft_ls: illegal option -- ", 2);
				ft_putchar_fd(op, 2);
				ft_putstr_fd("\nusage: ft_ls [-alrRt] [file ...]\n", 2);
				exit(0);
			}
}

t_list		*get_options(int ac, char **av, int16_t *opt)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac && av[i][0] == '-')
	{
		j = 0;
		while (av[i][++j] != '\0')
			active_options(av[i][j], opt);
	}	
	return (ft_lstnew(ft_strdup("./"), sizeof(char) * 3));
}

#include "option.h"
#include "utils.h"

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

static void	namelen(char *s, int *path, int *name)
{
	int	i;
	int	slash;
	int	word;

	i = -1;
	slash = 0;
	word = 1;
	while (s[++i] != '\0')
	{
		if (s[i] == '/')
			slash++;	
		if (s[i] == '/' && s[i + 1] != '\0' && s[i + 1] != '/')
			word++;
	}
	if (word == 1 && slash == 0)
		*name = i;
	else if (word == 1 && slash == 1)
		*name = i - 1;
	else
	{
		i = -1;
		while (s[++i] != '\0' && word != 1)
		{
			if (s[i] == '/')
			{
				slash--;
				word--;
			}
		}
		*path = i;
		if (word == 1 && slash == 0)
			*name = ft_strlen(s + i);
		else
			*name = ft_strlen(s + i) - slash;
	}
}

void			get_options(int ac, char **av, int16_t *opt, t_list **dir)
{
	int		i;
	int		j;
	int		len;

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
	*dir = NULL;
	while (i < ac)
	{
		len = 0;
		namelen(av[i], &len, &j);
		create_dir(av[i], len, j, dir);
		i++;
	}
}

#include "otpion.h"

void    get_options(int ac, char **av, int16_t *opt)
{
    int	i;
	int	j;

    i = 0;
    while (++i < ac && ac[i][0] != '-')
	{
		j = 0;
		while (ac[i][++j] != NULL)
		{
			if (ac[i][j] == 'l')
				opt |= O_LFORMAT;
			else if (ac[i][j] == 'R')
				opt |= O_RECURSIVE;
			else if (ac[i][j] == 't')
				opt |= O_TIME;
			else if (ac[i][j] == 'r')
				opt |= O_REVERSE;
			else if (ac[i][j] == 'a')
				opt |= O_ALL;
			else
				ft_printf("ft_ls: illegal options -- %c\nusage:	ft_ls [-aRrTt] [file...]\n", ac[i][j]);
		}
	}
	while (i < ac)
}

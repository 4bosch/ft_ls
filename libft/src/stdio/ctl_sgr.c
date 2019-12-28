#include "internal/curly.h"

#include <stdint.h>

void	ctl_sgr_code(t_escseq *seq, char **str, t_buf *buf)
{
	t_string	res;
	int8_t		i;
	char		tab[5];

	tab[0] = '[';
	i = 1;
	while ((*str)[i] >= '0' && (*str)[i] <= '9' && i < 4)
	{
		tab[i] = (*str)[i];
		++i;
	}
	(*str) += i;
	tab[i++] = 'm';
	res.str = tab;
	res.len = i;
	write_curly(seq, &res, str, buf);
}

void	ctl_reset(t_escseq *seq, char **str, t_buf *buf)
{
	t_string	res;
	char		tab[3];

	tab[0] = '[';
	tab[1] = '0';
	tab[2] = 'm';
	res.str = tab;
	res.len = 3;
	write_curly(seq, &res, str, buf);
}

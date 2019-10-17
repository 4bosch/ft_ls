#ifndef OPTION_H
# define OPTION_H
# include <types.h>

# define O_LFORMAT 1
# define O_RECURSIVE 2
# define O_TIME 4
# define O_REVERSE 16
# define O_ALL 32

void	get_options(int ac, char **av, int16_t *opt);

#endif

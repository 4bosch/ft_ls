#ifndef OPTION_H
# define OPTION_H
# include <stdint.h>

# include "libft.h"
# include "file.h"

# define O_LFORMAT 1
# define O_RECUR 2
# define O_TIME 4
# define O_REVERSE 16
# define O_ALL 32
# define O_ONE 64
# define O_ONEFILE 128
# define O_HEADER 256

void	get_options(int ac, char **av, int16_t *opt, t_list **dir);

#endif

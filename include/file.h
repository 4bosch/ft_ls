#ifndef FILE_H
# define FILE_H

# include <sys/errno.h>

# include "shared.h"
# include "libft.h"
# include "option.h"
# include "dir.h"

int	create_file(char *path, char *name, t_list **list, int16_t option);

#endif

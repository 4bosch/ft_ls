#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <stdio.h>
# include <sys/errno.h>
# include "shared.h"
# include "libft.h"
# include "option.h"

void	create_file(char *path, char *name, t_list **list, int16_t option);
void	create_dir(char *name,int path_len, int name_len, t_list **list);
int	is_dir(char *path);

#endif

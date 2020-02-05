#ifndef UTILS_H
# define UTILS_H

# include "shared.h"
# include "libft.h"

void	create_dir(char *name,int path_len, int name_len, t_list **list);
void	make_dir(char *name, int path_len, int name_len, t_dir **dir);
void	move_dir(t_list **input, t_list **dir);

#endif

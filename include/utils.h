#ifndef UTILS_H
# define UTILS_H
# include "shared.h"
# include "libft.h"

t_file		*create_file(char *name);
int			name_cmp(t_list e1, t_list e2);
int			time_cmp(t_list e1, t_list e2);
int			rname_cmp(t_list e1, t_list e2);
int			rtime_cmp(t_list e1, t_list e2);

#endif

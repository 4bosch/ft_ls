#ifndef PRINT_H
# define PRINT_H
# include "shared.h"
# include "libft.h"
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <pwd.h>

typedef struct		s_max
{
	int	nlink;
	int	user;
	int	group;
	int	size;
	int	name;
}			t_max;

void	print_files(t_list **tab, char c);

#endif

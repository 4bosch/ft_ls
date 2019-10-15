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
	size_t		nlink;
	size_t		user;
	size_t		group;
	long long	size;
}			t_max;

void	print_files(t_list **tab, char c);

#endif

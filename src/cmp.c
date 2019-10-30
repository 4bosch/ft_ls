#include "cmp.h"

int			name_cmp(t_list e1, t_list e2)
{
	return((ft_strcmp(((t_file*)e1.content)->name, ((t_file*)e2.content)->name) < 0) ? 1 : 0);
}

int			time_cmp(t_list e1, t_list e2)
{
	int diff;

	diff = ((t_file*)e1.content)->sbuf.st_mtimespec.tv_sec - ((t_file*)e2.content)->sbuf.st_mtimespec.tv_sec;
	if (diff == 0)
	{
		diff = ((t_file*)e1.content)->sbuf.st_mtimespec.tv_nsec - ((t_file*)e2.content)->sbuf.st_mtimespec.tv_nsec;
		if (diff == 0)
			return (name_cmp(e1, e2));
		else if (diff > 0)
			return (1);
		else
			return (0);
	}
	else if (diff > 0)
		return (1);
	else
		return (0);
}

int			rname_cmp(t_list e1, t_list e2)
{
	return (name_cmp(e2, e1));
}

int			rtime_cmp(t_list e1, t_list e2)
{
	return (time_cmp(e2, e1));
}

int			dname_cmp(t_list e1, t_list e2)
{
	return ((ft_strcmp((char*)e1.content, (char*)e2.content) < 0) ? 1 : 0);
}

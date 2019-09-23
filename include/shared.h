#ifndef SHARED_H
# define SHARED_H
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_file
{
	char		*name;
	struct stat	sbuf;
}				t_file;

#endif

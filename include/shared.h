#ifndef SHARED_H
# define SHARED_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# define F(f) ((t_file*)f->content)
# define D(d) ((t_dir*)d->content)

typedef struct s_file
{
	char		*name;
	struct stat	sbuf;
	int			path_len;
	int			name_len;
}				t_file;

typedef struct s_dir
{
	char		*name;
	int			path_len;
	int			name_len;
}				t_dir;

#endif

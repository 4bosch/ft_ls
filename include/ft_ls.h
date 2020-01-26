#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>

# include "shared.h"
# include "libft.h"
# include "file.h"
# include "print.h"
# include "option.h"
# include "cmp.h"

void     list_files(char *path, int path_len, int16_t opt);

#endif

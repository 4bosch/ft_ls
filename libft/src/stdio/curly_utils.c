#include "internal/curly_utils.h"

#include <string.h>

size_t	skip_to_colsing_curly(char **str)
{
	size_t	i;

	i = 0;
	while ((*str)[i] != '}' && (*str)[i] != '\0')
		++i;
	if ((*str)[i] == '\0')
		i = 0;
	return (i);
}

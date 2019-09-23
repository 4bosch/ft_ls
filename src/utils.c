#include "utils.h"

t_file		*create_file(char *name)
{
	t_file	*ret;

	if (!(ret = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	ret->name = ft_strnew(ft_strlen(name));
	ft_strcpy(ret->name, name);
	lstat(name, &(ret->sbuf));
	return (ret);
}

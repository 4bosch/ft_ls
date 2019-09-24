#include "ft/list.h"

void	ft_lstsort(t_list **lst, int (*cmp)(t_list *e1, t_list *e2))
{
	if (lst == NULL && cmp(NULL, NULL))
		return ;
}

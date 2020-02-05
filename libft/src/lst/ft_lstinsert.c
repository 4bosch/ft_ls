#include "ft/list.h"

void	ft_lstinsert(t_list *lst, t_list *new)
{
	t_list	*next;

	if (lst == NULL || new == NULL)
		return ;
	next = lst->next;
	lst->next = new;
	new->next = next;
}

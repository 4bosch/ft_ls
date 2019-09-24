#include "print.h"

void	print_files(t_list *lst, char c)
{
	while (lst != NULL)
	{
		if (c)
			ft_printf("%s\n", ((t_file*)(lst->content))->name);
		else
			continue ;
		lst = lst->next;
	}
}

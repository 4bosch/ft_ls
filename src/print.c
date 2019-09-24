#include "print.h"

void	print_files(t_list *lst, char c)
{
	if (c)
	{
		while (lst != NULL)
		{
			ft_printf("%s\n", ((t_file*)(lst->content))->name);
			lst = lst->next;
		}
	}
	else
	{
		return ;
	}
}

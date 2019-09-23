#include "print.h"

void	print_files(t_list *lst)
{
	while (lst != NULL)
	{
		ft_printf("%s\n", ((t_file*)(lst->content))->name);
		lst = lst->next;
	}
}

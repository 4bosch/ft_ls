#include "libft.h"

void	ft_lstquicksort(t_list **lst, int (*cmp)(t_list *e1, t_list *e2))
{
	t_list	**tab;
	int		i;
	int		len;

	if (lst != NULL)
	{
		len = ft_lstlen(*lst);
		tab = ft_lstquicksorttab(*lst, cmp);
		i = -1;
		while (++i < len - 1)
			tab[i]->next = tab[i + 1];
		tab[len - 1]->next = NULL;
		*lst = tab[0];
	}
	else
		ft_printerr("Your list equal NULL\n");
}

#include "ft/list.h"

static t_list	*lst2tab(t_list *lst)
{
	t_list	*tab;
	int		i;

	if (!(tab = (t_list*)malloc(ft_lstlen(lst) * sizeof(t_list))))
		return (NULL);		//CAS D'ERREUR A GERER
	i = 0;
	while (lst != NULL)
	{
		tab[i++] = *lst;
		lst = lst->next;
	}
	return (tab);
}

static void		swap(t_list *e1, t_list *e2)
{
	t_list	tmp;
	
	tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

static int		partition(t_list *tab, int low, int high, int (*cmp)(t_list e1, t_list e2))
{
	t_list	pivot;
	int		i;
	int		j;
   
	pivot = tab[high];
	i = low - 1;
	j = low - 1;
	while (++j <= high)
	{
		if (cmp(tab[j], pivot))
			swap(&tab[++i], &tab[j]);
	}
	swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

static void		quicksort(t_list *tab, int low, int high, int (*cmp)(t_list e1, t_list e2))
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(tab, low, high, cmp);
		quicksort(tab, low, pivot - 1, cmp);
		quicksort(tab, pivot + 1, high, cmp);
	}
}


void			ft_lstquicksort(t_list **lst, int (*cmp)(t_list e1, t_list e2))
{
	t_list	*tab;

	if (lst != NULL && cmp != NULL)
	{
		tab = lst2tab(*lst);
		quicksort(tab, 0, ft_lstlen(*lst), cmp);
	}
}

#include "ft/list.h"
//////////////////////////////////?DELETTE CA 
#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
typedef struct	s_file
{
	char		*name;
	struct stat	sbuf;
}				t_file;

static t_list	*lst2tab(t_list *lst)
{
	t_list	*tab;
	int		i;

	if (!(tab = (t_list*)malloc(ft_lstlen(lst) * sizeof(t_list))))
		return (NULL);		//CAS D'ERREUR A GERER
	i = 0;
	while (lst != NULL)
	{
		tab[i] = *lst;
		lst = lst->next;
		i++;
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
	int		smaller;
	int		j;
   
	pivot = tab[high];
	smaller = low - 1;
	j = low - 1;
	while (++j <= high)
		if (cmp(tab[j], pivot))
			swap(&tab[++smaller], &tab[j]);
	swap(&tab[smaller + 1], &tab[high]);
	return (smaller + 1);
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
		int i = -1;
		int end = ft_lstlen(*lst);
		tab = lst2tab(*lst);
		while (++i < end)
			printf("%s\n", ((t_file*)tab[i].content)->name);
		printf("\n\n");
		quicksort(tab, 0, ft_lstlen(*lst) - 1, cmp);
		i = -1;
		while (++i < end)
			printf("%s\n", ((t_file*)tab[i].content)->name);
	}
	printf("\n\n\n");
}

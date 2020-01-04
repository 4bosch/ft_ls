/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstquicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:20:09 by abosch            #+#    #+#             */
/*   Updated: 2019/10/02 16:52:59 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/list.h"

#include "ft/stdio.h" //////////////////////////REMOVE
#include "shared.h"

static t_list	**lst2tab(t_list *lst)
{
	t_list	**tab;
	int		i;

	if (!(tab = (t_list**)malloc(ft_lstlen(lst) * (sizeof(t_list*) + 1))))
		return (NULL);		//CAS D'ERREUR A GERER
	i = 0;
	while (lst != NULL)
	{
		tab[i] = lst;
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

static int		partition(t_list **tab, int low, int high, int (*cmp)(t_list *e1, t_list *e2))
{
	int		i;
	int		j;

	i = low;
	j = low;
	while (++j <= high)
		if (cmp(tab[j], tab[low]))
			swap(tab[++i], tab[j]);
	swap(tab[i], tab[low]);
	return (i);	
}

static void		quicksort(t_list **tab, int low, int high, int (*cmp)(t_list *e1, t_list *e2))
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(tab, low, high, cmp);
		quicksort(tab, low, pivot - 1, cmp);
		quicksort(tab, pivot + 1, high, cmp);
	}
}


t_list			**ft_lstquicksorttab(t_list *lst, int (*cmp)(t_list *e1, t_list *e2))
{
	t_list	**tab;
	int		len;

	if (lst != NULL && cmp != NULL)
	{
		if ((len = ft_lstlen(lst)) <= 0)
			return (NULL); //cas d'erreur a gerer
		tab = lst2tab(lst);
		quicksort(tab, 0, len - 1, cmp);
		tab[len] = NULL;
		return (tab);
	}
	else
		return (NULL); //Cas d'erreur potentiellement inexistant
}

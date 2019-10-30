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

static int		partition(t_list **tab, int low, int high, int (*cmp)(t_list e1, t_list e2))
{
	t_list	*pivot;
	int		smaller;
	int		j;
   
	pivot = tab[high];
	smaller = low - 1;
	j = low - 1;
	while (++j <= high)
		if (cmp(*tab[j], *pivot))
			swap(tab[++smaller], tab[j]);
	swap(tab[smaller + 1], tab[high]);
	return (smaller + 1);
}

static void		quicksort(t_list **tab, int low, int high, int (*cmp)(t_list e1, t_list e2))
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(tab, low, high, cmp);
		quicksort(tab, low, pivot - 1, cmp);
		quicksort(tab, pivot + 1, high, cmp);
	}
}


t_list			**ft_lstquicksorttab(t_list **lst, int (*cmp)(t_list e1, t_list e2))
{
	t_list	**tab;
	t_list	*tmp;
	int		len;

	ft_printf("=============== quicksort tab ============\n");
	if (lst != NULL && cmp != NULL)
	{
		ft_printf("les pointeurs ne sont pas null cool\n");
		ft_printf("\n---------- LIST -----------\n");
		tmp = *lst;
		while (tmp != NULL)
		{
			ft_printf("add |%p| |%s|\n",tmp, ((t_file*)tmp->content)->name);
			ft_printf("next : %p\n", tmp->next);
			tmp = tmp->next;
		}
		ft_printf("----------------FIN-------------\n");
		
		if ((len = ft_lstlen(*lst)) <= 0)
			return (NULL); //cas d'erreur a gerer
		ft_printf("\nla longueur est %d\n\n", len);
		tab = lst2tab(*lst);
		quicksort(tab, 0, len - 1, cmp);
		tab[len] = NULL;
		return (tab);
	}
	else
		return (NULL); //Cas d'erreur potentiellement inexistant
}

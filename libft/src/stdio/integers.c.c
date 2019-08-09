/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:50:07 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/10 15:26:16 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/integers.h"
#include "ft/tmp.h"
#include "internal/shared.h"

#include <stdlib.h>

int		get_number(char **str)
{
	int		nbr;

	nbr = 0;
	while (**str >= '0' && **str <= '9')
	{
		nbr *= 10;
		nbr += (**str - 48);
		if (nbr < 0)
			return (0);
		(*str)++;
	}
	return (nbr);
}

char	*nbr_grouping(t_string *conv, char sep, unsigned int size)
{
	char	*new;
	size_t	i;
	size_t	j;
	int		nsep;

	i = 0;
	while (conv->str[i] != '.' && conv->str[i] != '\0')
		++i;
	nsep = ((i / (float)size) > (i / size)) ? i / size : i / size - 1;
	if ((new = ft_strnew(conv->len + nsep)) == NULL)
		return (NULL);
	ft_strcpy(new + i + nsep, conv->str + i);
	j = -1;
	while (++j < size && --i > 0)
	{
		new[i + nsep] = conv->str[i];
		if (j == size - 1 && i > 0)
		{
			j = -1;
			new[i + --nsep] = sep;
		}
	}
	new[i] = conv->str[i];
	return (new);
}

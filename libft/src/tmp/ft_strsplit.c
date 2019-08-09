/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:27:29 by abosch            #+#    #+#             */
/*   Updated: 2018/11/14 19:00:57 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

static int	is_separator(char c, char sep)
{
	return (c == sep);
}

static int	countword(char *s, char sep)
{
	int	new_word;
	int	cnt;

	new_word = 1;
	cnt = 0;
	while (*s)
	{
		if (!is_separator(*s, sep) && new_word)
		{
			cnt++;
			new_word = 0;
		}
		if (is_separator(*s++, sep) && !new_word)
			new_word = 1;
	}
	return (cnt);
}

static int	wordlen(char *s, char sep)
{
	int	i;

	i = -1;
	while (s[++i] != '\0' && s[i] != sep)
		;
	return (i);
}

static char	*storedata(char *s, char sep, int word_len)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!(tmp = ft_strnew(word_len)))
		return (NULL);
	while (s[++i] != '\0' && !is_separator(s[i], sep))
		tmp[i] = s[i];
	tmp[i] = '\0';
	return (tmp);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	int		i;
	int		cnt;
	int		word_len;

	if (!s)
		return (NULL);
	nb_word = countword((char*)s, c);
	if (!(tab = (char**)(malloc(sizeof(char*) * (nb_word + 1)))))
		return (NULL);
	i = -1;
	cnt = 0;
	while (s[++i] != '\0' && cnt < nb_word)
	{
		while (is_separator(s[i], c))
			i++;
		word_len = wordlen((char*)(s + i), c);
		tab[cnt] = storedata((char*)(s + i), c, word_len);
		i += word_len - 1;
		cnt++;
	}
	tab[cnt] = 0;
	return (tab);
}

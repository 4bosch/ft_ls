/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:24 by abosch            #+#    #+#             */
/*   Updated: 2020/02/18 17:52:22 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"

static void	active_options(char op, int16_t *opt)
{
	if (op == 'l')
		*opt |= O_LFORMAT;
	else if (op == 'r')
		*opt |= O_REVERSE;
	else if (op == 'R')
		*opt |= O_RECUR;
	else if (op == 't')
		*opt |= O_TIME;
	else if (op == 'a')
		*opt |= O_ALL;
	else if (op == '1')
		*opt |= O_ONE;
	else
	{
		ft_printerr("ft_ls: illegal option -- %c\n"
			"usage: ft_ls [-alrRt] [file ...]\n", op);
		exit(1);
	}
}

static int	parse_option(int ac, char **av, int16_t *opt)
{
	int i;
	int	j;

	i = 0;
	*opt = 0;
	*opt |= O_ONEFILE;
	while (++i < ac && (av[i][0] == '-' && av[i][1] != '\0'))
	{
		if (ft_strcmp(av[i], "--") == 0)
		{
			i++;
			break ;
		}
		j = 0;
		while (av[i][++j] != '\0')
			active_options(av[i][j], opt);
	}
	return (i);
}

void		get_input(int ac, char **av, int16_t *opt, t_list **input)
{
	int		i;
	int		j;
	t_file	*tmp;

	i = parse_option(ac, av, opt);
	if (i == ac)
	{
		create_file("", "./", input, *opt);
		return ;
	}
	j = 0;
	while (i < ac)
	{
		if (!create_file("", av[i], input, *opt))
		{
			tmp = (t_file*)(*input)->content;
			if (!(*opt & O_LFORMAT) && S_ISLNK(tmp->sbuf.st_mode))
				stat(tmp->name, &(tmp->sbuf));
		}
		if (j > 0)
			*opt |= O_HEADER;
		i++;
		j++;
	}
}

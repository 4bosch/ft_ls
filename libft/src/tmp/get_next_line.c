/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:46:03 by abosch            #+#    #+#             */
/*   Updated: 2019/04/09 17:10:54 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

static int		get_line(char **line, char **s)
{
	if (!ft_strlen(*s))
		return (0);
	if (ft_strchr(*s, '\n'))
	{
		if (!(*line = ft_strsub(*s, 0, ft_strlen(*s) -
						ft_strlen(ft_strchr(*s, '\n')))))
			return (-1);
		ft_strcpy(*s, ft_strchr(*s, '\n') + 1);
		return (1);
	}
	else if (!(*line = ft_strdup(*s)))
		return (-1);
	ft_strdel(s);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUF_SIZE + 1];
	int			ret;
	char		*tmp;
	static char	*save[OPEN_MAX];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = save[fd];
		if (!(save[fd] = ft_strjoin(save[fd], buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	return (get_line(line, &save[fd]));
}

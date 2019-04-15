/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:25:18 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 18:06:01 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fd_cpy(char **dst, char *src, int i)
{
	char			*tmp;

	src[i] = '\0';
	if ((tmp = ft_strjoin(*dst, src)) == NULL)
	{
		if (*dst)
			ft_memdel((void **)dst);
		return (-1);
	}
	if (*dst)
		ft_memdel((void **)dst);
	*dst = tmp;
	return (0);
}

static int		ft_line(char **dst, char **src)
{
	char			*tmp;

	if (*src == '\0')
	{
		ft_memdel((void **)src);
		return (0);
	}
	if ((tmp = ft_strchr(*src, '\n')) != NULL)
		tmp[0] = '\0';
	else
	{
		if ((*dst = ft_strdup(*src)) == NULL)
			return (-1);
		ft_memdel((void **)src);
		return (1);
	}
	if ((*dst = ft_strdup(*src)) == NULL)
		return (-1);
	(tmp[1] != '\0') ? (ft_strcpy(*src, ++tmp)) : ft_memdel((void **)src);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*arr[100];
	char			*buf;
	int				i;

	if (fd < 0 || fd >= 100 || !line)
		return (-1);
	if (arr[fd] == NULL)
	{
		if ((buf = ft_memalloc(1024 + 1)) == NULL)
			return (-1);
		while ((i = read(fd, buf, 1024)) > 0)
			if (ft_fd_cpy(&arr[fd], buf, i) == -1)
				return (-1);
		if (i < 0)
		{
			ft_memdel((void **)&buf);
			if (arr[fd])
				ft_memdel((void **)&arr[fd]);
			return (i);
		}
		ft_memdel((void **)&buf);
	}
	*line = NULL;
	return (ft_line(line, &arr[fd]));
}

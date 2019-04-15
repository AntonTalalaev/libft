/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:01:56 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 14:55:53 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_putchar_tool_two(int c, int fd)
{
	unsigned char	chr;

	if (c < 2097152)
	{
		chr = 240 + c / 32768;
		write(fd, &chr, 1);
		c %= 32768;
		chr = 128 + c / 4096;
		write(fd, &chr, 1);
		c %= 4096;
		chr = 128 + c / 64;
		write(fd, &chr, 1);
		chr = 128 + c % 64;
		write(fd, &chr, 1);
		return (4);
	}
	return (-1);
}

static int		ft_putchar_tool_one(int c, int fd)
{
	unsigned char	chr;

	if (c < 65536)
	{
		chr = 224 + c / 4096;
		write(fd, &chr, 1);
		c %= 4096;
		chr = 128 + c / 64;
		write(fd, &chr, 1);
		chr = 128 + c % 64;
		write(fd, &chr, 1);
		return (3);
	}
	return (ft_putchar_tool_two(c, fd));
}

int				ft_putchar_fd(int c, int fd)
{
	unsigned char	chr;

	if (c <= 255)
	{
		write(fd, &c, 1);
		return (1);
	}
	if (c < 2048)
	{
		chr = 192 + c / 64;
		write(fd, &chr, 1);
		chr = 128 + c % 64;
		write(fd, &chr, 1);
		return (2);
	}
	return (ft_putchar_tool_one(c, fd));
}

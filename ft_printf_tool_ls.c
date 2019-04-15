/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_ls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 17:11:49 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_conversion_ls_tool_getlen(const int *src)
{
	int				len;
	int				x;
	int				a;

	x = 0;
	a = 0;
	if (g_flags.precision != -1)
	{
		x = g_flags.precision;
		while ((x -= ft_ucharlen(src[a])) >= 0)
			a++;
		len = a;
	}
	else
		len = ft_ustrlen(src);
	return (len);
}

static int			ft_conversion_ls_tool_two(const int *src, char *tmp, int i)
{
	int				x;
	int				a;

	a = 0;
	if (i > 0 && g_flags.minus == -1)
		g_flags_global.counter += ft_putstr(tmp);
	while (src[a] != '\0')
	{
		if ((x = ft_putchar(src[a++])) == -1)
		{
			g_flags_global.counter = -1;
			return (-1);
		}
		g_flags_global.counter += x;
	}
	if (i > 0 && g_flags.minus == 1)
		g_flags_global.counter += ft_putstr(tmp);
	return (0);
}

static int			ft_conversion_ls_tool_one(const int *src, char *tmp,
		int len, int i)
{
	int				x;
	int				a;

	a = 0;
	if (i > 0 && g_flags.minus == -1)
		g_flags_global.counter += ft_putstr(tmp);
	while (a < len)
	{
		if ((x = ft_putchar(src[a++])) == -1)
		{
			g_flags_global.counter = -1;
			return (-1);
		}
		g_flags_global.counter += x;
	}
	if (i > 0 && g_flags.minus == 1)
		g_flags_global.counter += ft_putstr(tmp);
	return (0);
}

static int			ft_conversion_ls_tool_tree(const int *src,
		char **tmp, int len)
{
	int				i;
	int				x;

	i = 0;
	x = 0;
	if (g_flags.width != -1)
	{
		if (g_flags.precision != -1)
			while (i < len)
				x += ft_ucharlen(src[i++]);
		else
			x = len;
		if ((i = g_flags.width - x) > 0)
		{
			ft_memdel((void *)tmp);
			((*tmp = ft_strnew(i)) == NULL) ? exit(-1) : 0;
			(g_flags.zero == -1) ? ft_memset(*tmp, ' ', i) :
				ft_memset(*tmp, '0', i);
		}
	}
	return (i);
}

void				ft_conversion_ls(char **output, const int *src)
{
	int				i;
	char			*tmp;
	int				len;

	if (src == NULL)
	{
		ft_conversion_s(output, "(null)");
		return ;
	}
	((tmp = ft_strnew(1)) == NULL) ? exit(-1) : 0;
	g_flags_global.counter += ft_putstr(*output);
	len = ft_conversion_ls_tool_getlen(src);
	i = ft_conversion_ls_tool_tree(src, &tmp, len);
	if (g_flags.precision != -1)
		if (ft_conversion_ls_tool_one(src, tmp, len, i) == -1)
			return ;
	if (g_flags.precision == -1)
		if (ft_conversion_ls_tool_two(src, tmp, i) == -1)
			return ;
	ft_memdel((void **)&tmp);
	ft_memdel((void **)output);
	((*output = ft_strnew(1)) == NULL) ? exit(-1) : 0;
}

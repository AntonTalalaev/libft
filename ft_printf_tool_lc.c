/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_lc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 17:08:27 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_conversion_lc_tool(char *tmp, int i)
{
	if (g_flags.minus == -1)
	{
		g_flags_global.counter += ft_putstr_fd(tmp,
				g_flags_global.dest_file);
		g_flags_global.counter +=
			ft_putchar_fd(i, g_flags_global.dest_file);
	}
	else
	{
		g_flags_global.counter +=
			ft_putchar_fd(i, g_flags_global.dest_file);
		g_flags_global.counter +=
			ft_putstr_fd(tmp, g_flags_global.dest_file);
	}
}

void					ft_conversion_lc(char **output, int i)
{
	char				*tmp;
	int					a;

	((tmp = ft_strnew(1)) == NULL) ? exit(-1) : 0;
	if (g_flags.width != -1)
	{
		if ((a = g_flags.width - 1) > 0)
		{
			ft_memdel((void **)&tmp);
			((tmp = ft_strnew(a)) == NULL) ? exit(-1) : 0;
			ft_memset(tmp, ' ', a);
		}
	}
	g_flags_global.counter += ft_putstr_fd(*output,
			g_flags_global.dest_file);
	ft_conversion_lc_tool(tmp, i);
	ft_memdel((void **)output);
	ft_memdel((void **)&tmp);
}

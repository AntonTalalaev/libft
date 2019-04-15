/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 16:47:12 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_conversion_c_tool_width(char **str)
{
	int					i;
	char				*tmp;

	i = 0;
	if ((i = g_flags.width - 1) > 0)
	{
		if ((tmp = ft_strnew(i)) == NULL)
			exit(-1);
		(g_flags.zero == -1) ? ft_memset(tmp, ' ', i) :
		ft_memset(tmp, '0', i);
		if (g_flags.minus == -1)
			*str = ft_strcat_free(&tmp, str);
		else
			*str = ft_strcat_free(str, &tmp);
		if (*str == NULL)
			exit(-1);
	}
}

void					ft_conversion_c_tool_notprintable(char *output,
		char *str, char chr)
{
	g_flags_global.counter +=
		ft_putstr_fd(output, g_flags_global.dest_file);
	if (g_flags.minus == -1)
	{
		g_flags_global.counter +=
			ft_putstr_fd(str, g_flags_global.dest_file);
		g_flags_global.counter +=
			ft_putchar_fd(chr, g_flags_global.dest_file);
	}
	else
	{
		g_flags_global.counter +=
			ft_putchar_fd(chr, g_flags_global.dest_file);
		g_flags_global.counter +=
			ft_putstr_fd(str, g_flags_global.dest_file);
	}
}

void					ft_conversion_c(char **output, int i)
{
	unsigned char		chr;
	char				*str;

	chr = i;
	if ((str = ft_strnew(1)) == NULL)
		exit(-1);
	str[0] = chr;
	if (g_flags.width != -1)
		ft_conversion_c_tool_width(&str);
	if (chr >= ' ' && chr != 127)
	{
		if ((*output = ft_strcat_free(output, &str)) == NULL)
			exit(-1);
	}
	else
	{
		ft_conversion_c_tool_notprintable(*output, str, chr);
		ft_memdel((void **)output);
		ft_memdel((void **)&str);
	}
}

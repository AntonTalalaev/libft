/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_flag_adder2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:07:30 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/14 20:09:13 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_flag_adder_tool_six(const char *chr)
{
	if (chr[0] == 'c' && chr[1] == 'o' && chr[2] == 'l' && chr[3] == 'o' &&
			chr[4] == 'r' && chr[5] == ':')
	{
		g_flags_global.add_color = 1;
		if (chr[6] == 'o' && chr[7] == 'f' && chr[8] == 'f')
		{
			ft_strcpy(&g_flags_global.color[0], "\x1b[0m\0");
			return (9);
		}
		if (chr[6] == 'r')
			ft_strcpy(&g_flags_global.color[0], "\x1b[31m");
		if (chr[6] == 'b')
			ft_strcpy(&g_flags_global.color[0], "\x1b[36m");
		if (chr[6] == 'g')
			ft_strcpy(&g_flags_global.color[0], "\x1b[32m");
		if (chr[6] != 'r' && chr[6] != 'b' && chr[6] != 'g')
			return (6);
		return (7);
	}
	return (0);
}

int						ft_flag_adder_tool_five(const char *chr, va_list ap)
{
	if (chr[0] == 'f' && chr[1] == 'i' && chr[2] == 'l' && chr[3] == 'e')
	{
		g_flags_global.dest_file = va_arg(ap, int);
		return (4);
	}
	if (chr[0] == 'c' && chr[1] == 'a' && chr[2] == 's' && chr[3] == 'e' &&
			chr[4] == ':')
	{
		if (chr[5] == 'u' && chr[6] == 'p')
		{
			g_flags_global.up_low_case = 2;
			return (7);
		}
		if (chr[5] == 'o' && chr[6] == 'f' && chr[7] == 'f')
			g_flags_global.up_low_case = 0;
		if (chr[5] == 'l' && chr[6] == 'o' && chr[7] == 'w')
			g_flags_global.up_low_case = 1;
		return (8);
	}
	return (ft_flag_adder_tool_six(chr));
}

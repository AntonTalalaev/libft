/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_flag_adder.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:09:52 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/03 13:18:46 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_flag_adder_tool_one(const char *chr, va_list ap)
{
	if (chr[0] == 'n')
	{
		g_flags_global.dest_str = va_arg(ap, char *);
		return (1);
	}
	if (chr[0] == '\'')
		return (g_flags.grouping = 1);
	if (chr[0] == '#')
		return (g_flags.sharp = 1);
	if (chr[0] == '0')
		return (g_flags.zero = 1);
	if (chr[0] == '-')
		return (g_flags.minus = 1);
	if (chr[0] == '+')
		return (g_flags.plus = 1);
	if (chr[0] == ' ')
		return (g_flags.space = 1);
	return (0);
}

static int			ft_flag_adder_tool_two(const char *chr)
{
	int				i;

	i = 0;
	if (chr[0] != '0' && ft_isdigit(chr[0]))
	{
		g_flags.width = ft_atoi(chr);
		while (ft_isdigit(chr[i]))
			i++;
		return (i);
	}
	if (chr[0] == '.')
	{
		if (ft_isdigit(chr[1]))
		{
			g_flags.precision = ft_atoi(&chr[1]);
			while (ft_isdigit(chr[i + 1]))
				i++;
			return (i + 1);
		}
		g_flags.precision = 0;
		return (1);
	}
	return (0);
}

static int			ft_flag_adder_tool_three(const char *chr, va_list ap)
{
	int				i;

	i = 0;
	if (chr[0] == '*')
	{
		i = va_arg(ap, int);
		if (chr[-1] == '.')
		{
			if (i >= 0)
				g_flags.precision = i;
			else
				g_flags.precision = -1;
		}
		else
		{
			g_flags.width = i;
			if (g_flags.width < 0)
			{
				g_flags.minus = 1;
				g_flags.width = -g_flags.width;
			}
		}
		return (1);
	}
	return (0);
}

static int			ft_flag_adder_tool_four(const char *chr)
{
	if (chr[0] == 'z')
		g_flags.length[0] = 'z';
	if (chr[0] == 'h')
	{
		g_flags.length[0] = 'h';
		if (chr[1] == 'h')
			g_flags.length[1] = 'h';
	}
	if (chr[0] == 'l')
	{
		g_flags.length[0] = 'l';
		if (chr[1] == 'l')
			g_flags.length[1] = 'l';
	}
	if (chr[0] == 'j')
		g_flags.length[0] = 'j';
	if (chr[0] == 'L')
		g_flags.length[0] = 'L';
	if (g_flags.length[1] != '\0')
		return (2);
	if (g_flags.length[0] != '\0')
		return (1);
	return (0);
}

int					ft_flag_adder(const char *chr, va_list ap)
{
	int				a;

	if ((a = ft_flag_adder_tool_one(chr, ap)) > 0)
		return (a);
	if ((a = ft_flag_adder_tool_two(chr)) > 0)
		return (a);
	if ((a = ft_flag_adder_tool_three(chr, ap)) > 0)
		return (a);
	if ((a = ft_flag_adder_tool_four(chr)) > 0)
		return (a);
	if ((a = ft_flag_adder_tool_five(chr, ap)) > 0)
		return (a);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_di.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 16:48:20 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_conversion_di_tool_getstr(va_list ap)
{
	if (g_flags.length[0] == '\0')
		return (ft_itoa(va_arg(ap, int)));
	if (g_flags.length[0] == 'h' && g_flags.length[1] == '\0')
		return (ft_itoa((short)va_arg(ap, int)));
	if (g_flags.length[0] == 'h' && g_flags.length[1] == 'h')
		return (ft_itoa((signed char)va_arg(ap, int)));
	if (g_flags.length[0] == 'l' && g_flags.length[1] == '\0')
		return (ft_itoa(va_arg(ap, long)));
	if (g_flags.length[0] == 'l' && g_flags.length[1] == 'l')
		return (ft_itoa(va_arg(ap, long long int)));
	if (g_flags.length[0] == 'j' && g_flags.length[1] == '\0')
		return (ft_itoa(va_arg(ap, intmax_t)));
	if (g_flags.length[0] == 'z' && g_flags.length[1] == '\0')
		return (ft_itoa(va_arg(ap, size_t)));
	return (ft_itoa(va_arg(ap, int)));
}

static void			ft_conversion_di_tool_plus2(char **str)
{
	char			*tmp;
	int				i;

	if (str[0][0] != ' ')
	{
		if ((tmp = ft_strjoin("+", *str)) == NULL)
			exit(-1);
		ft_memdel((void **)str);
		*str = tmp;
	}
	else
	{
		i = 0;
		while (str[0][i] == ' ')
			i++;
		str[0][i - 1] = '+';
	}
}

static void			ft_conversion_di_tool_plus(char **str)
{
	char			*tmp;
	int				i;

	if (str[0][0] == '0' && str[0][1] != '\0')
	{
		if (g_flags.precision == -1)
			str[0][0] = '+';
		else
		{
			if ((tmp = ft_strnew(ft_strlen(*str) + 1)) == NULL)
				exit(-1);
			tmp[0] = '+';
			ft_strcpy(&tmp[1], *str);
			i = ft_strlen(tmp);
			if (g_flags.width > g_flags.precision)
				tmp[i - 1] = '\0';
			else
				tmp[i] = '\0';
			ft_memdel((void **)str);
			*str = tmp;
		}
	}
	else
		ft_conversion_di_tool_plus2(str);
}

static void			ft_conversion_di_tool_spase(char **str)
{
	char			*tmp;
	int				i;

	if (g_flags.precision == -1)
		i = 0;
	if ((str[0][0] == '0' || str[0][0] == ' ') && ((g_flags.width >
					g_flags.precision && g_flags.precision != -1) ||
						(g_flags.precision == -1 &&
							g_flags.width == (int)ft_strlen(*str))))
		str[0][0] = ' ';
	else
	{
		if ((tmp = ft_strjoin(" ", *str)) == NULL)
			exit(-1);
		ft_memdel((void **)str);
		*str = tmp;
	}
}

void				ft_conversion_di(char **output, va_list ap)
{
	char			*str;

	str = ft_conversion_di_tool_getstr(ap);
	if (str[0] == '-')
	{
		g_flags.space = -1;
		g_flags.plus = -1;
	}
	if (g_flags.precision != -1)
		g_flags.zero = -1;
	if (g_flags.grouping == 1)
		ft_conversion_di_tool_grouping(&str);
	if (g_flags.precision != -1)
		ft_conversion_di_tool_precision(&str);
	if (g_flags.width != -1)
		ft_conversion_di_tool_width(&str);
	if (g_flags.plus == 1)
		ft_conversion_di_tool_plus(&str);
	if (g_flags.space == 1 && str[0] != ' ')
		ft_conversion_di_tool_spase(&str);
	if ((*output = ft_strcat_free(output, &str)) == NULL)
		exit(-1);
}

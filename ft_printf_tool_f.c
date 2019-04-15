/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 17:05:48 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_conversion_f_tool_grouping(char **str)
{
	int				x;
	char			*tmp;
	char			*tmp2;

	x = ft_strlen(*str);
	if (x > 3)
	{
		((tmp2 = ft_strnew(1)) == NULL) ? exit(-1) : 0;
		while (x > 0)
		{
			if (x >= 3)
				x -= 3;
			else
				x = 0;
			if (x != 0)
				((tmp = ft_strjoin(",", str[x])) == NULL) ? exit(-1) : 0;
			else
				tmp = *str;
			((tmp2 = ft_strcat_free(&tmp, &tmp2)) == NULL) ? exit(-1) : 0;
			str[0][x] = '\0';
		}
		ft_memdel((void **)str);
		*str = tmp2;
	}
}

static void			ft_conversion_f_tool_width(char **str)
{
	int				x;
	char			*tmp;

	if ((g_flags.width != -1) && ((x = g_flags.width - ft_strlen(*str)) > 0))
	{
		((tmp = ft_strnew(x)) == NULL) ? exit(-1) : 0;
		if (g_flags.zero == 1 && g_flags.minus == -1)
			ft_memset(tmp, '0', x);
		else
			ft_memset(tmp, ' ', x);
		if (g_flags.minus == -1)
			((*str = ft_strcat_free(&tmp, str)) == NULL) ? exit(-1) : 0;
		else
			((*str = ft_strcat_free(str, &tmp)) == NULL) ? exit(-1) : 0;
	}
}

static void			ft_conversion_f_tool_space(char **str)
{
	char			*tmp;

	if (g_flags.space == 1 && str[0][0] != ' ')
	{
		if (str[0][0] == '0' && ft_isdigit(str[0][1]))
			str[0][0] = ' ';
		else
		{
			((tmp = ft_strjoin(" ", *str)) == NULL) ? exit(-1) : 0;
			ft_memdel((void **)str);
			*str = tmp;
		}
	}
}

static double		ft_conversion_f_tool_one(char **str, double i)
{
	char			*tmp;
	double			a;

	a = 1;
	if (i < 0)
	{
		i = -i;
		a = -1;
		((tmp = ft_uitoa(i)) == NULL) ? exit(-1) : 0;
		((*str = ft_strjoin("-", tmp)) == NULL) ? exit(-1) : 0;
		ft_memdel((void **)&tmp);
	}
	else
		((*str = ft_uitoa(i)) == NULL) ? exit(-1) : 0;
	if (g_flags.grouping == 1)
		ft_conversion_f_tool_grouping(str);
	ft_conversion_f_tool_getstr(str, i);
	return (a);
}

void				ft_conversion_f(char **output, va_list ap)
{
	char			*tmp;
	char			*str;
	double			i;

	i = va_arg(ap, double);
	if ((i != i) || (i == 1 / 0.0) || (i == -1 / 0.0))
	{
		g_flags.zero = -1;
		g_flags.precision = -1;
		(i != i) ? ft_conversion_s(output, "nan") : 0;
		(i == 1 / 0.0) ? ft_conversion_s(output, "inf") : 0;
		(i == -1 / 0.0) ? ft_conversion_s(output, "-inf") : 0;
		return ;
	}
	i = ft_conversion_f_tool_one(&str, i);
	ft_conversion_f_tool_width(&str);
	ft_conversion_f_tool_space(&str);
	if ((tmp = ft_strchr(str, '-')) && ft_strchr(tmp + 1, '-'))
	{
		ft_memset(str, '0', ft_strlen(str));
		str[1] = '.';
	}
	((*output = ft_strcat_free(output, &str)) == NULL) ? exit(-1) : 0;
}

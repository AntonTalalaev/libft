/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 17:07:18 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_conversion_f_tool_rounding(char **str, int x)
{
	int				i;

	i = ft_strchr_index(*str, '.');
	while ((i + g_flags.precision) < x)
	{
		(str[0][x] > '5') ? str[0][x - 1] = str[0][x - 1] + 1 : 0;
		str[0][x--] = '\0';
	}
	(str[0][x] == '.') ? str[0][x--] = '\0' : 0;
	while (str[0][x] > '9')
	{
		str[0][x] = '0';
		if (str[0][x - 1] != '.')
		{
			str[0][x - 1] = str[0][x - 1] + 1;
			x--;
		}
		else
		{
			str[0][x - 2] = str[0][x - 2] + 1;
			x -= 2;
		}
	}
}

static void			ft_conversion_f_tool_precision(char **str)
{
	int				x;
	char			*tmp;

	if (ft_strchr(*str, '.') != NULL)
	{
		if ((x = g_flags.precision - ft_strlen(ft_strchr(*str, '.') + 1)) > 0)
		{
			((tmp = ft_strnew(x)) == NULL) ? exit(-1) : 0;
			ft_memset(tmp, '0', x);
			((*str = ft_strcat_free(str, &tmp)) == NULL) ? exit(-1) : 0;
		}
	}
	else
	{
		((tmp = ft_strjoin(*str, ".")) == NULL) ? exit(-1) : 0;
		ft_memdel((void **)str);
		*str = tmp;
	}
}

void				ft_conversion_f_tool_getstr(char **str, double i)
{
	long int		x;
	char			*tmp;
	char			*tmp2;

	if (g_flags.plus == 1 && str[0][0] != '-')
	{
		((tmp = ft_strjoin("+", *str)) == NULL) ? exit(-1) : 0;
		ft_memdel((void **)str);
		*str = tmp;
	}
	((tmp = ft_strjoin(*str, ".")) == NULL) ? exit(-1) : 0;
	ft_memdel((void **)str);
	x = (long int)i;
	i = i - (double)x;
	i = i * (long double)1000000000000000000;
	((tmp2 = ft_uitoa(i)) == NULL) ? exit(-1) : 0;
	((*str = ft_strcat_free(&tmp, &tmp2)) == NULL) ? exit(-1) : 0;
	if (g_flags.precision == -1)
		g_flags.precision = 6;
	ft_conversion_f_tool_rounding(str, ft_strlen(*str));
	ft_conversion_f_tool_precision(str);
}

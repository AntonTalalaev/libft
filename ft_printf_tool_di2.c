/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_di2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:07:38 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 16:58:05 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_conversion_di_tool_grouping(char **str)
{
	char			*tmp;
	char			*tmp2;
	int				i;

	i = ft_strlen(*str);
	if (i > 3)
	{
		((tmp2 = ft_strnew(1)) == NULL) ? exit(-1) : 0;
		while (i > 0)
		{
			if (i >= 3)
				i -= 3;
			else
				i = 0;
			if (i != 0)
				tmp = ft_strjoin(",", str[i]);
			else
				tmp = *str;
			(tmp == NULL) ? exit(-1) : 0;
			str[0][i] = '\0';
			((tmp2 = ft_strcat_free(&tmp, &tmp2)) == NULL) ? exit(-1) : 0;
		}
		ft_memdel((void **)str);
		*str = tmp2;
	}
}

void				ft_conversion_di_tool_precision(char **str)
{
	char			*tmp;
	int				i;

	if (str[0][0] == '0' && str[0][1] == '\0' && g_flags.precision == 0)
		str[0][0] = '\0';
	else
	{
		if (str[0][0] == '-')
			i = g_flags.precision - ft_strlen(*str) + 1;
		else
			i = g_flags.precision - ft_strlen(*str);
		if (i > 0)
		{
			((tmp = ft_strnew(i)) == NULL) ? exit(-1) : 0;
			ft_memset(tmp, '0', i);
			((*str = ft_strcat_free(&tmp, str)) == NULL) ? exit(-1) : 0;
			if ((tmp = ft_strchr(*str, '-')) != NULL)
			{
				*tmp = '0';
				str[0][0] = '-';
			}
		}
	}
}

void				ft_conversion_di_tool_width(char **str)
{
	char			*tmp;
	int				i;

	if ((i = g_flags.width - ft_strlen(*str)) > 0)
	{
		((tmp = ft_strnew(i)) == NULL) ? exit(-1) : 0;
		if (g_flags.zero == 1 && g_flags.minus == -1)
			ft_memset(tmp, '0', i);
		else
			ft_memset(tmp, ' ', i);
		if (str[0][0] == '-' && tmp[0] == '0')
		{
			str[0][0] = '0';
			i = 1;
		}
		else
			i = 0;
		if (g_flags.minus == -1)
			((*str = ft_strcat_free(&tmp, str)) == NULL) ? exit(-1) : 0;
		else
			((*str = ft_strcat_free(str, &tmp)) == NULL) ? exit(-1) : 0;
		if (i == 1)
			str[0][0] = '-';
	}
}

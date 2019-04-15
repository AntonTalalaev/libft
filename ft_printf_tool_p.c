/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 17:18:10 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_conversion_p_tool_precision(char **str)
{
	int					i;
	char				*tmp;

	g_flags.zero = -1;
	if (str[0][0] == '0' && str[0][1] == '\0')
		str[0][0] = '\0';
	if ((i = g_flags.precision - ft_strlen(*str)) > 0)
	{
		((tmp = ft_strnew(i)) == NULL) ? exit(-1) : 0;
		ft_memset(tmp, '0', i);
		((*str = ft_strcat_free(&tmp, str)) == NULL) ? exit(-1) : 0;
	}
}

static int				ft_conversion_p_tool_width(char **output,
		char **str, int i)
{
	char				*tmp;
	char				*tmp2;

	tmp = ft_strnew(1);
	if ((i = g_flags.width - ft_strlen(*str)) > 2)
	{
		ft_memdel((void **)&tmp);
		((tmp = ft_strnew(i)) == NULL) ? exit(-1) : 0;
		if (g_flags.zero == 1)
		{
			ft_memset(tmp, '0', i);
			tmp[1] = 'x';
			((*str = ft_strcat_free(&tmp, str)) == NULL) ? exit(-1) : 0;
			((*output = ft_strcat_free(output, str)) == NULL) ? exit(-1) : 0;
			return (1);
		}
		ft_memset(tmp, ' ', i - 2);
	}
	((tmp2 = ft_strjoin("0x", *str)) == NULL) ? exit(-1) : 0;
	ft_memdel((void **)str);
	if (g_flags.minus == -1)
		((*str = ft_strcat_free(&tmp, &tmp2)) == NULL) ? exit(-1) : 0;
	else
		((*str = ft_strcat_free(&tmp2, &tmp)) == NULL) ? exit(-1) : 0;
	return (0);
}

void					ft_conversion_p(char **output, void *p)
{
	char				*tmp;
	char				*str;
	unsigned long		n;

	n = (unsigned long)p;
	((str = ft_decimal_converter("0123456789abcdef", n)) == NULL) ?
		exit(-1) : 0;
	if (g_flags.precision != -1)
		ft_conversion_p_tool_precision(&str);
	if (g_flags.width != -1)
	{
		if (ft_conversion_p_tool_width(output, &str, 0) == 1)
			return ;
	}
	else
	{
		((tmp = ft_strjoin("0x", str)) == NULL) ? exit(-1) : 0;
		ft_memdel((void **)&str);
		str = tmp;
	}
	((*output = ft_strcat_free(output, &str)) == NULL) ? exit(-1) : 0;
}

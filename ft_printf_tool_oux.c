/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_ouxX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 17:24:47 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_conversion_oux_tool_u(char **output, char **str,
		char *tmp, char *tmp2)
{
	int				i;

	i = 0;
	while (*str[i] != '\0')
		i++;
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
				((tmp = ft_strjoin(",", str[i])) == NULL) ? exit(-1) : 0;
			else
				((tmp = *str) == NULL) ? exit(-1) : 0;
			*str[i] = '\0';
			((tmp2 = ft_strcat_free(&tmp, &tmp2)) == NULL) ? exit(-1) : 0;
		}
		*str = tmp2;
	}
	((*output = ft_strcat_free(output, str)) == NULL) ? exit(-1) : 0;
	return (0);
}

static uintmax_t	ft_conversion_oux_tool_getnum(char type, va_list ap)
{
	if (type == 'U' || type == 'O')
		ft_strcpy(g_flags.length, "l");
	if (g_flags.length[0] == '\0' || type == 'b')
		return (va_arg(ap, unsigned int));
	if (g_flags.length[0] == 'z' && g_flags.length[1] == '\0')
		return (va_arg(ap, size_t));
	if (g_flags.length[0] == 'h' && g_flags.length[1] == '\0')
		return ((unsigned short)va_arg(ap, unsigned int));
	if (g_flags.length[0] == 'h' && g_flags.length[1] == 'h')
		return ((unsigned char)va_arg(ap, unsigned int));
	if (g_flags.length[0] == 'l' && g_flags.length[1] == '\0')
		return (va_arg(ap, unsigned long));
	if (g_flags.length[0] == 'l' && g_flags.length[1] == 'l')
		return (va_arg(ap, unsigned long long));
	if (g_flags.length[0] == 'j')
		return (va_arg(ap, uintmax_t));
	return (0);
}

static void			ft_conversion_oux_tool_one(char type, char **str)
{
	char			*tmp;
	int				i;

	i = 0;
	if (g_flags.precision != -1 && g_flags.precision > (i = ft_strlen(*str)))
	{
		i = g_flags.precision - i;
		((tmp = ft_strnew(i)) == NULL) ? exit(-1) : 0;
		ft_memset(tmp, '0', i);
		((*str = ft_strcat_free(&tmp, str)) == NULL) ? exit(-1) : 0;
	}
	if ((type == 'x' || type == 'X') && g_flags.sharp == 1 &&
			!((str[0][0] == '0' && str[0][1] == '\0') || str[0][0] == '\0'))
	{
		if (type == 'x')
			((tmp = ft_strjoin("0x", *str)) == NULL) ? exit(-1) : 0;
		else
			((tmp = ft_strjoin("0X", *str)) == NULL) ? exit(-1) : 0;
		ft_memdel((void **)str);
		*str = tmp;
	}
}

static void			ft_conversion_oux_tool_width(char type, char **str)
{
	char			*tmp;
	int				i;

	if (g_flags.width != -1 && g_flags.width > (i = ft_strlen(*str)))
	{
		i = g_flags.width - i;
		((tmp = ft_strnew(i)) == NULL) ? exit(-1) : 0;
		if (g_flags.zero == 1 && g_flags.minus == -1 && *str[0] != '\0')
			ft_memset(tmp, '0', i);
		else
			ft_memset(tmp, ' ', i);
		if (g_flags.minus == -1)
			((*str = ft_strcat_free(&tmp, str)) == NULL) ? exit(-1) : 0;
		else
			((*str = ft_strcat_free(str, &tmp)) == NULL) ? exit(-1) : 0;
		if (g_flags.sharp == 1 && g_flags.zero == 1 &&
				g_flags.minus == -1 && str[0][0] != '\0')
		{
			str[0][1] = type;
			i = 2;
			while (str[0][i] == '0' && str[0][i] != 'x' && str[0][i] != 'X')
				i++;
			str[0][i] = '0';
		}
	}
}

int					ft_conversion_oux(char **output, char type, va_list ap)
{
	char			*tmp;
	char			*str;
	uintmax_t		i;

	i = ft_conversion_oux_tool_getnum(type, ap);
	str = ft_conversion_oux_tool_getstr(type, i);
	if ((type == 'u' || type == 'U') && g_flags.grouping == 1)
		ft_conversion_oux_tool_u(output, &str, NULL, NULL);
	if ((type == 'o' || type == 'O') && g_flags.sharp == 1 && str[0] != '0')
	{
		((tmp = ft_strjoin("0", str)) == NULL) ? exit(-1) : 0;
		ft_memdel((void **)&str);
		str = tmp;
	}
	(g_flags.precision != -1 && g_flags.sharp == -1 && str[0] == '0' &&
		str[1] == '\0') ? str[0] = '\0' : 0;
	((type == 'x' || type == 'X') && g_flags.precision == 0 && str[0] == '0' &&
		str[1] == '\0') ? str[0] = '\0' : 0;
	if ((type == 'o' || type == 'O') && (g_flags.precision != -1))
		g_flags.zero = -1;
	ft_conversion_oux_tool_one(type, &str);
	ft_conversion_oux_tool_width(type, &str);
	((*output = ft_strcat_free(output, &str)) == NULL) ? exit(-1) : 0;
	return (0);
}

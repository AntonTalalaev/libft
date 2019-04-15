/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:38:16 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 13:58:16 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags				g_flags;
t_flags_global		g_flags_global;

static void		ft_printf_convertions(const char *restrict format, va_list ap,
		char **output, int i)
{
	if ((IF_NOT_CONV) || format[i] == '%')
		ft_conversion_c(output, format[i]);
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'D')
	{
		(format[i] == 'D') ? ft_strcpy(g_flags.length, "l") : 0;
		ft_conversion_di(output, ap);
	}
	if (format[i] == 'c' && g_flags.length[0] != 'l')
		ft_conversion_c(output, va_arg(ap, int));
	(format[i] == 'C' || (format[i] == 'c' && g_flags.length[0] == 'l')) ?
		ft_conversion_lc(output, va_arg(ap, int)) : 1;
	if (format[i] == 's' && g_flags.length[0] != 'l')
		ft_conversion_s(output, va_arg(ap, const char *));
	(format[i] == 'S' || (format[i] == 's' && g_flags.length[0] == 'l')) ?
		ft_conversion_ls(output, va_arg(ap, const int *)) : 1;
	if (format[i] == 'p')
		ft_conversion_p(output, va_arg(ap, void *));
	(format[i] == 'o' || format[i] == 'O' || format[i] == 'u' ||
	format[i] == 'U' || format[i] == 'x' || format[i] == 'X' ||
	format[i] == 'b') ? ft_conversion_oux(output, format[i], ap) : 0;
	if ((format[i] == 'f' || format[i] == 'F') &&
			(g_flags.length[0] == '\0' || g_flags.length[0] == 'l'))
		ft_conversion_f(output, ap);
	((format[i] == 'f' || format[i] == 'F') && g_flags.length[0] == 'L') ?
		ft_conversion_lf(output, ap) : 1;
}

static int		ft_printf_tool_two(const char *restrict format, va_list ap,
		char **output, int i)
{
	ft_flag_correcter();
	(format[i] != '~') ? ft_printf_convertions(format, ap, output, i) : 0;
	if (g_flags_global.counter == -1)
		return (-1);
	if (g_flags_global.dest_str == NULL && g_flags_global.dest_file == 1 &&
			g_flags_global.add_color)
		ft_putstr(g_flags_global.color);
	if (*output != NULL)
	{
		(g_flags_global.up_low_case == 1) ? ft_strlowcase(*output) : 0;
		(g_flags_global.up_low_case == 2) ? ft_strupcase(*output) : 0;
		if (g_flags_global.dest_str != NULL)
		{
			g_flags_global.counter += ft_strlen(*output);
			ft_strcat(g_flags_global.dest_str, *output);
		}
		else
			g_flags_global.counter += ft_putstr_fd(*output,
					g_flags_global.dest_file);
	}
	ft_memdel((void **)output);
	return (0);
}

static int		ft_printf_tool_three(const char *restrict format,
		char **output, int i)
{
	int			a;
	char		*tmp;

	a = 0;
	if ((tmp = ft_strnew(ft_strlen(&format[i]))) == NULL)
		return (-1);
	while (format[i] != '%')
		tmp[a++] = format[i++];
	*output = ft_strcat_free(output, &tmp);
	i++;
	return (i);
}

static int		ft_printf_tool_one(const char *restrict format, va_list ap,
		char **output, int i)
{
	char		*tmp;

	ft_flag_global_clear();
	while (format[i] != '\0')
	{
		if (ft_strchr(&format[i], '%') == NULL)
		{
			if ((tmp = ft_strjoin(*output, &format[i])) == NULL)
				return (-1);
			ft_memdel((void **)output);
			*output = tmp;
			return (0);
		}
		ft_flag_clear();
		if ((i = ft_printf_tool_three(format, output, i)) == -1)
			return (-1);
		while (IS_FLAG)
			i += ft_flag_adder(&format[i], ap);
		if (format[i] == '\0')
			return (0);
		if (ft_printf_tool_two(format, ap, output, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	char		*output;

	if (ft_strlen(format) == 0 || (format[0] == '%' && format[1] == '\0'))
		return (0);
	va_start(ap, format);
	output = NULL;
	if (ft_printf_tool_one(format, ap, &output, 0) < 0)
		return (-1);
	if (output == NULL)
		return (g_flags_global.counter);
	if (g_flags_global.up_low_case != 0)
		(g_flags_global.up_low_case == 1) ? ft_strlowcase(output) :
			ft_strupcase(output);
	if (g_flags_global.dest_str != NULL)
	{
		g_flags_global.counter += ft_strlen(output);
		ft_strcat(g_flags_global.dest_str, output);
	}
	else
		g_flags_global.counter += ft_putstr_fd(output,
				g_flags_global.dest_file);
	ft_memdel((void **)&output);
	va_end(ap);
	return (g_flags_global.counter);
}

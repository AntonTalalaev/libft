/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 17:16:56 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_conversion_s(char **output, const char *str)
{
	int					i;
	char				*tmp;
	char				*dst;

	if (str == NULL)
		((dst = ft_strdup("(null)")) == NULL) ? exit(-1) : 0;
	else
		((dst = ft_strdup(str)) == NULL) ? exit(-1) : 0;
	if (g_flags.precision != -1)
		dst[g_flags.precision] = '\0';
	if (g_flags.width != -1)
	{
		if ((i = g_flags.width - ft_strlen(dst)) > 0)
		{
			((tmp = ft_strnew(i)) == NULL) ? exit(-1) : 0;
			(g_flags.zero == 1 && g_flags.minus == -1) ?
				ft_memset(tmp, '0', i) : ft_memset(tmp, ' ', i);
			if (g_flags.minus == -1)
				((dst = ft_strcat_free(&tmp, &dst)) == NULL) ? exit(-1) : 0;
			else
				((dst = ft_strcat_free(&dst, &tmp)) == NULL) ? exit(-1) : 0;
		}
	}
	((*output = ft_strcat_free(output, &dst)) == NULL) ? exit(-1) : 0;
}

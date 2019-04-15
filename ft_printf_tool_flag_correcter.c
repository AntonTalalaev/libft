/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:39:49 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/01 14:51:15 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags				g_flags;
t_flags_global		g_flags_global;

void	ft_flag_clear(void)
{
	g_flags.sharp = -1;
	g_flags.zero = -1;
	g_flags.minus = -1;
	g_flags.plus = -1;
	g_flags.space = -1;
	g_flags.width = -1;
	g_flags.precision = -1;
	g_flags.length[0] = '\0';
	g_flags.length[1] = '\0';
}

void	ft_flag_global_clear(void)
{
	g_flags_global.dest_str = NULL;
	g_flags_global.dest_file = 1;
	g_flags_global.up_low_case = 0;
	g_flags_global.add_color = 0;
	ft_strcpy(&g_flags_global.color[0], "\x1b[0m\0");
	g_flags_global.counter = 0;
}

void	ft_flag_correcter(void)
{
	if (g_flags.plus == 1)
		g_flags.space = -1;
	if (g_flags.minus == 1)
		g_flags.zero = -1;
	if (g_flags_global.up_low_case != 0)
		if (g_flags_global.up_low_case != 1 && g_flags_global.up_low_case != 2)
			g_flags_global.up_low_case = 0;
}

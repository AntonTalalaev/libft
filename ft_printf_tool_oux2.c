/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool_ouxX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:41:25 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 14:51:00 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_conversion_oux_tool_getstr(char type, uintmax_t i)
{
	if (type == 'u' || type == 'U')
		return (ft_uitoa(i));
	if (type == 'o' || type == 'O')
		return (ft_decimal_converter("01234567", i));
	if (type == 'x')
		return (ft_decimal_converter("0123456789abcdef", i));
	if (type == 'X')
		return (ft_decimal_converter("0123456789ABCDEF", i));
	if (type == 'b')
		return (ft_decimal_converter("01", i));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:09:12 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/03 12:03:57 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_if_min_max_atoi(const char *str, long long int sign)
{
	if (sign > 0)
		if (ft_strncmp(str, "9223372036854775807", 19) > 0)
			return (-1);
	if (sign < 0)
		if (ft_strncmp(str, "-9223372036854775808", 20) > 0)
			return (0);
	return (0);
}

int				ft_atoi(const char *str)
{
	long long int		number;
	long long int		sign;
	int					i;

	sign = 1;
	number = 0;
	i = -1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	(*str == '-') ? (sign = -sign) : (1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9' && ++i < 19)
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (i == 19 && ft_if_min_max_atoi(str, sign) == -1)
		return (-1);
	if (i == 19 && ft_if_min_max_atoi(str, sign) == 0)
		return (0);
	return (number * sign);
}

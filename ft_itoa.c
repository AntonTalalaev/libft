/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:40:13 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 15:17:27 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(intmax_t n)
{
	int				i;
	uintmax_t		q;
	uintmax_t		n2;
	intmax_t		sign;
	char			*p;

	sign = 1;
	i = 1;
	(n < 0) ? (sign = -1) : (1);
	(n >= 0) ? (i = 0) : (1);
	n2 = (uintmax_t)(n * sign);
	q = n2;
	while (q /= 10)
		i++;
	if ((p = (char *)malloc(sizeof(char) * (i + 2))) == NULL)
		return (NULL);
	p[i + 1] = '\0';
	q = 1;
	while (i >= 0)
	{
		p[i] = (n2 / q % 10) + '0';
		q *= 10;
		(i-- == 0 && sign < 0) ? (p[i + 1] = '-') : (1);
	}
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:40:13 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 15:03:17 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(uintmax_t n)
{
	int				i;
	uintmax_t		q;
	char			*p;

	i = 0;
	q = n;
	while (q /= 10)
		i++;
	if ((p = (char *)malloc(sizeof(char) * (i + 2))) == NULL)
		return (NULL);
	p[i + 1] = '\0';
	q = 1;
	while (i >= 0)
	{
		p[i] = (n / q % 10) + '0';
		q *= 10;
		i--;
	}
	return (p);
}

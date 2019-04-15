/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:43:00 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/28 16:34:26 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**p;
	unsigned int	i;
	unsigned int	a;

	if (!s)
		return (NULL);
	a = 0;
	if ((p = (char **)malloc(sizeof(char *) *
					(i = (ft_delimcount(s, c) + 1)))) == NULL)
		return (NULL);
	p[i - 1] = 0;
	while (*s)
	{
		i = 0;
		while (*s && *s != c && ++i)
			s++;
		if (i)
			if ((p[a++] = ft_strsub(s - i, 0, i)) == NULL)
				return (ft_arrdel(&p));
		if (*s)
			s++;
	}
	return (p);
}

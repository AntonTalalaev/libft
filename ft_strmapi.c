/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:15:27 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/28 16:22:03 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		if ((p = ft_strdup(s)) == NULL)
			return (NULL);
		while (p[i])
		{
			p[i] = f(i, p[i]);
			i++;
		}
		return (p);
	}
	return (NULL);
}

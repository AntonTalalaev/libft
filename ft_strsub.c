/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:08:35 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/28 15:43:56 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	if (s)
	{
		i = 0;
		if ((p = ft_strnew(len)) == NULL)
			return (NULL);
		while (s[start] != '\0' && len)
		{
			p[i] = s[start + i];
			i++;
			len--;
		}
		return (p);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:24:51 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/28 15:51:34 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*p;
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		while (s[i])
			i++;
		if (i > 0)
			i--;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			--i;
		if ((p = ft_strsub(s, 0, i + 1)) == NULL)
			return (NULL);
		return (p);
	}
	return (NULL);
}

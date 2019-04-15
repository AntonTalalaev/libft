/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:36:31 by mwunsch           #+#    #+#             */
/*   Updated: 2018/12/04 16:40:22 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (*haystack != '\0' && i < len)
	{
		i = 0;
		while (i < len && haystack[i] == *needle)
		{
			if (*needle == '\0')
				return ((char *)(haystack));
			needle++;
			i++;
		}
		if ((*needle == '\0') || i == len)
			return ((*needle == '\0') ? (char *)(haystack) : NULL);
		needle -= i;
		haystack++;
		len--;
	}
	return (NULL);
}

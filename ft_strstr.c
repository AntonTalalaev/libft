/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:36:31 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/28 14:36:32 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		i = 0;
		while (*haystack == *needle && *needle)
		{
			haystack++;
			needle++;
			i++;
		}
		if (*needle == '\0')
			return ((char *)(haystack - i));
		needle -= i;
		haystack = haystack + 1 - i;
	}
	return (NULL);
}

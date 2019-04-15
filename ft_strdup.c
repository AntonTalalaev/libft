/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:08:56 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 15:00:03 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		n;

	n = 0;
	while (s1[n] != '\0')
		n++;
	if ((dest = (char*)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	n = 0;
	while (s1[n] != '\0')
	{
		dest[n] = s1[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

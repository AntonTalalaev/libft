/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:21:56 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 15:02:23 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = ft_strlen((char *)src);
	while (i < len)
	{
		if (i <= size)
		{
			dst[i] = src[i];
		}
		else
		{
			dst[i] = '\0';
		}
		i++;
	}
	return (dst);
}

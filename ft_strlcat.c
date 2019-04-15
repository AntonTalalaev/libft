/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:21:56 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/27 14:50:11 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		size_dst;
	size_t		size_src;
	size_t		answer;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dst >= size)
		return (size + size_src);
	i = 0;
	answer = size_dst + size_src;
	while (size_src-- && i < (size - size_dst - 1))
	{
		dst[i + size_dst] = src[i];
		i++;
	}
	dst[i + size_dst] = '\0';
	return (answer);
}

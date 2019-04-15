/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:06:55 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 15:20:24 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] &&
			s1[i] && --n > 0)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

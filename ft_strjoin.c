/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:40:51 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 15:00:21 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	sl1;
	size_t	sl2;

	sl1 = s1 ? ft_strlen(s1) : 0;
	sl2 = s2 ? ft_strlen(s2) : 0;
	if (s1 || s2)
	{
		if ((p = ft_strnew(sl1 + sl2)) == NULL)
			return (NULL);
		if (!s1)
		{
			ft_strcpy(p, s2);
			return (p);
		}
		if (!s2)
		{
			ft_strcpy(p, s1);
			return (p);
		}
		ft_strcpy(p, s1);
		ft_strcpy(p + sl1, s2);
		return (p);
	}
	return (NULL);
}

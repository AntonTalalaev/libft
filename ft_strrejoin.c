/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zokon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:20:55 by zokon             #+#    #+#             */
/*   Updated: 2018/11/23 17:22:15 by zokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrejoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, s1);
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp + ft_strlen(tmp), s2);
	if (!tmp)
		return (NULL);
	ft_strdel(&s1);
	return (tmp);
}

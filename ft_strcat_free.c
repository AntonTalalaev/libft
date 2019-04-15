/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:50:35 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/04 17:07:14 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_free(char **dst, char **src)
{
	char		*tmp;

	if ((tmp = ft_strjoin(*dst, *src)) == NULL)
		return (NULL);
	ft_memdel((void **)dst);
	ft_memdel((void **)src);
	return (tmp);
}

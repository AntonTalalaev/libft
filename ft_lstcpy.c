/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:33:12 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/26 15:33:27 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *elem)
{
	if (elem)
	{
		if (!elem->content_size)
			return (ft_lstnew(NULL, 0));
		return (ft_lstnew(elem->content, elem->content_size));
	}
	return (NULL);
}

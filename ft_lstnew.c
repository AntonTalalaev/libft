/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 10:37:39 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/25 14:51:46 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	if ((p = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		p->content = NULL;
		p->content_size = 0;
	}
	else
	{
		p->content = ft_memalloc(content_size);
		ft_memcpy(p->content, content, content_size);
		p->content_size = content_size;
	}
	p->next = NULL;
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:21:41 by mwunsch           #+#    #+#             */
/*   Updated: 2018/12/06 15:40:35 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **alst, void const *content, size_t content_size)
{
	t_list	*p;

	p = *alst;
	if (*alst)
	{
		while (p->next)
			p = p->next;
		p->next = ft_lstnew(content, content_size);
	}
	else
		*alst = ft_lstnew(content, content_size);
}

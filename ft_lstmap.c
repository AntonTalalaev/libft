/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:24:34 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/29 15:42:32 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_lstdelall(t_list **alst)
{
	t_list	*p;

	p = *alst;
	while (p->next)
	{
		while (p->next->next)
			p = p->next;
		free(p->next);
		p->next = NULL;
		p = *alst;
	}
	free(p);
	p = NULL;
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*p2;
	t_list	*first;

	if (lst == NULL || f == NULL)
		return (NULL);
	p = f(lst);
	if ((first = ft_lstnew(p->content, p->content_size)) == NULL)
		return (NULL);
	p = first;
	while (lst->next)
	{
		lst = lst->next;
		if ((p2 = ft_lstnew((f(lst))->content, (f(lst))->content_size)) == NULL)
			return (ft_lstdelall(&first));
		p->next = p2;
		p = p2;
	}
	return (first);
}

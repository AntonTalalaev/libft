/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:14:54 by mwunsch           #+#    #+#             */
/*   Updated: 2018/12/06 15:58:13 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	if (alst && del)
	{
		p = *alst;
		while (p->next)
		{
			while (p->next->next)
				p = p->next;
			ft_lstdelone(&p->next, del);
			p = *alst;
		}
		ft_lstdelone(&(*alst), del);
	}
}

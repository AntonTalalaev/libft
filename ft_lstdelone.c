/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:14:54 by mwunsch           #+#    #+#             */
/*   Updated: 2018/12/06 15:56:49 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*p;

	if (alst == NULL || del == NULL)
		return ;
	p = *alst;
	del(p->content, p->content_size);
	free(*alst);
	*alst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:01:39 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/26 12:24:25 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputstr(t_list *elem)
{
	if (elem && elem->content)
		ft_putstr(elem->content);
	ft_putchar('\n');
}

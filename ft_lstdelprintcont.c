/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delprintcont                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:14:54 by mwunsch           #+#    #+#             */
/*   Updated: 2018/12/06 16:32:53 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelprintcont(void *p, size_t d)
{
	size_t	i;

	if (p == NULL)
		return ;
	i = 0;
	while (d > 0)
	{
		ft_putchar(((char *)p)[i]);
		i++;
		d--;
	}
	ft_putchar('\n');
	free(p);
	p = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:19:59 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/27 21:24:24 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;
	long int	q;
	long int	nb;

	i = 1;
	q = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		q = -q;
	}
	nb = q;
	while (q /= 10)
		i *= 10;
	i *= 10;
	while (i /= 10)
		ft_putchar_fd((nb / i % 10) + '0', fd);
}

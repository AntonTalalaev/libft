/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:12:55 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 14:23:57 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_decimal_converter(const char *baze, uintmax_t n)
{
	int			i;
	int			x;
	char		*str;
	char		*tmp;
	uintmax_t	conv_num;

	conv_num = ft_strlen(baze);
	if ((str = ft_strnew(32)) == NULL)
		return (NULL);
	if ((tmp = ft_strnew(32)) == NULL)
		return (NULL);
	i = 0;
	x = 0;
	while (n >= conv_num)
	{
		tmp[i] = baze[n % conv_num];
		n /= conv_num;
		i++;
	}
	tmp[i] = baze[n];
	while (i != 0)
		str[x++] = tmp[i--];
	str[x] = tmp[i];
	ft_memdel((void **)&tmp);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:51:51 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 15:14:20 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*d;
	unsigned char			*s;
	unsigned char			x;

	x = c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n > 0)
	{
		*d = *s;
		if (*s == x)
			return (++d);
		d++;
		s++;
		n--;
	}
	return (NULL);
}

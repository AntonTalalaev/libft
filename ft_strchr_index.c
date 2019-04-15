/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 13:05:03 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 14:58:51 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strchr_index(const char *s, int c)
{
	int		index;

	index = 0;
	while (*s != '\0')
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return (index);
		s++;
		index++;
	}
	return (-1);
}

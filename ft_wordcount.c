/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:22:28 by mwunsch           #+#    #+#             */
/*   Updated: 2018/11/26 16:24:48 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordcount(char const *s)
{
	int				in;
	unsigned int	i;
	unsigned int	count;

	i = 0;
	in = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' ||
				s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
			in = 0;
		else if (in == 0)
		{
			in = 1;
			count++;
		}
		i++;
	}
	return (count);
}

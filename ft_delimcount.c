/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:22:28 by mwunsch           #+#    #+#             */
/*   Updated: 2018/12/06 15:25:58 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_delimcount(char const *s, char c)
{
	int				in;
	unsigned int	i;
	unsigned int	count;

	if (!s)
		return (-1);
	i = 0;
	in = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
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

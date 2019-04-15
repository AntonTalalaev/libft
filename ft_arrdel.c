/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:52:39 by mwunsch           #+#    #+#             */
/*   Updated: 2019/01/11 18:20:43 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdel(char ***arr)
{
	unsigned int	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(**arr);
	**arr = NULL;
	return (NULL);
}

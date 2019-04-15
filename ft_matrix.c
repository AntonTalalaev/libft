/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:22:33 by mwunsch           #+#    #+#             */
/*   Updated: 2019/01/11 19:18:11 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix(size_t size1, size_t size2, char c)
{
	char		**matrix;
	size_t		i;
	size_t		j;

	i = 0;
	if ((matrix = (char **)malloc(sizeof(char *) * (size1 + 1))) == NULL)
		return (NULL);
	while (i < size1)
	{
		if ((matrix[i] = (char *)malloc(sizeof(char ) * (size2 + 1))) == NULL)
			return (ft_arrdel(&matrix));
		j = 0;
		while (j < size2)
		{
			matrix[i][j] = c;
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	return (matrix);
}

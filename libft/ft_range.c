/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:07:42 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/24 20:10:55 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int i;
	int *dest;

	if (min >= max)
		return (NULL);
	if (!(dest = (int*)malloc(sizeof(int*) * (max - min))))
		return (NULL);
	i = 0;
	while (min != max)
	{
		dest[i] = min;
		min++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

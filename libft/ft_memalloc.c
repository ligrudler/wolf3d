/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:33:22 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/16 22:58:57 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	char	*str2;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(str) * size)))
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str2 = (void *)str;
	return (str2);
}

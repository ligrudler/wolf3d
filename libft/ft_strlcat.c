/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:05:55 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/20 17:06:10 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	j;
	int		k;

	j = 0;
	k = 0;
	i = 0;
	if (count == 0)
		return (ft_strlen(src));
	while (dest[i] && i < count)
		i++;
	j = i;
	while (src[i - j] && i < count - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < count)
		dest[i] = '\0';
	while (src[k])
		k++;
	return (k + j);
}

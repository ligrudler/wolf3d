/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:14:53 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/16 22:37:23 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = -1;
	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dest;
	if (str1 < str2)
	{
		while (((int)(--n) >= 0))
		{
			str2[n] = str1[n];
		}
	}
	else
		while ((++i) < (int)n)
		{
			str2[i] = str1[i];
		}
	return (dest);
}

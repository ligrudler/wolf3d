/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:23:08 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/16 22:50:05 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*d;

	i = 0;
	d = (char *)s;
	while (d[i])
		i++;
	while (d[i] != c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (d + i);
}

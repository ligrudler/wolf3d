/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:34:38 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/24 18:38:54 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*d;
	char	*e;

	d = (char *)haystack;
	e = (char *)needle;
	i = -1;
	j = 0;
	if (e[0] == '\0')
		return ((char *)haystack);
	while (d[++i])
	{
		if (d[i] == e[j])
		{
			while (d[i + j] == e[j])
			{
				if (e[j + 1] == '\0')
					return (&d[i]);
				j++;
			}
		}
		j = 0;
	}
	return (0);
}

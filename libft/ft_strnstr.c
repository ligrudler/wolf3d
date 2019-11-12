/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:10:27 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/24 19:44:39 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*str;

	if (*needle == '\0')
		return ((char*)haystack);
	i = ft_strlen(needle);
	str = (char*)haystack;
	while (*str && len-- >= i)
	{
		if (ft_memcmp(str, needle, i) == 0)
			return (str);
		str++;
	}
	return (0);
}

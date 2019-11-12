/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:36:27 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/16 22:55:45 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*d;
	unsigned char	*e;
	int				i;

	i = 0;
	d = (unsigned char *)s1;
	e = (unsigned char *)s2;
	while (d[i] && e[i])
	{
		if (d[i] == e[i])
			i++;
		if (d[i] != e[i])
			return (d[i] - e[i]);
	}
	return (d[i] - e[i]);
}

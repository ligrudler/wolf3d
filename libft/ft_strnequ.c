/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:57:04 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/24 17:03:46 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] == s2[i])
		{
			if ((!(s1[i]) && !(s2[i])) || (i == n - 1))
				return (1);
			i++;
		}
	}
	return (0);
}

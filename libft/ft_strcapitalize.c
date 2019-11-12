/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:55:36 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/24 20:14:55 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (str[a] >= 'A' && str[a] <= 'Z')
			str[a] = str[a] + 32;
		a++;
	}
	a = 0;
	if (str[a] <= 'z' && str[a] >= 'a')
		str[a] = str[a] - 32;
	while (str[a])
	{
		if (str[a] > 'z' || (str[a] < 'a' && str[a] > 'Z')
				|| (str[a] < 'A' && str[a] > '9')
				|| (str[a] < '0' && str[a] > 1))
		{
			if (str[a + 1] <= 'z' && str[a + 1] >= 97)
				str[a + 1] = str[a + 1] - 32;
		}
		a++;
	}
	return (str);
}

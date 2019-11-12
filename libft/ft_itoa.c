/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:01:53 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/23 18:27:03 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*nbrstr(long n, char *str, int len)
{
	if (n > 9)
		nbrstr(n / 10, str, len - 1);
	if (n >= 0)
	{
		str[len] = ((n % 10) + '0');
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	long	nb;

	nb = n;
	i = n;
	len = 1;
	while (i /= 10)
		len++;
	if (n < 0)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		nb = -nb;
	}
	str = nbrstr(nb, str, len - 1);
	str[len] = '\0';
	return (str);
}

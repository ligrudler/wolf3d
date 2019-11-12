/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:18:54 by lgrudler          #+#    #+#             */
/*   Updated: 2019/05/09 17:34:57 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	nbr;

	i = 0;
	nbr = 0;
	neg = 0;
	while (nptr[i] == ' ' || nptr[i] == '\r' || nptr[i] == '\t'
			|| nptr[i] == '\n' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		neg = ((nptr[i] == '-') ? 1 : 0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + nptr[i] - '0';
		i++;
		if (nbr < 0)
			return (neg == 1 ? 0 : -1);
	}
	return (neg == 1 ? -nbr : nbr);
}

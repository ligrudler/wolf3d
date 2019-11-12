/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:37:29 by jmoucach          #+#    #+#             */
/*   Updated: 2019/04/29 17:37:30 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_htoi(char *hex)
{
	int		i;
	int		nb;

	if (!hex || !hex[1] || !hex[0] || hex[0] != '0' || (hex[1] != 'x'
		&& hex[1] != 'X') || ft_strlen(hex) > 10 || (ft_strlen(hex) == 10
		&& hex[1] != '7'))
		return (0);
	i = 2;
	nb = 0;
	while (hex[i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			nb = nb * 16 + hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] < 'g')
			nb = nb * 16 + (10 + hex[i] - 'a');
		else if (hex[i] >= 'A' && hex[i] < 'G')
			nb = (hex[i] - 'A' + 10) + nb * 16;
		else
			break ;
		i++;
	}
	return (nb);
}

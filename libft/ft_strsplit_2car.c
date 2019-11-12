/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:18:19 by lgrudler          #+#    #+#             */
/*   Updated: 2019/03/04 17:34:37 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words2(char const *s, t_car car)
{
	int i;
	int mot;
	int check;

	i = 0;
	mot = 0;
	check = 1;
	while (s[i] != '\0')
	{
		if (s[i] == car.y || s[i] == car.z)
			check = 1;
		if ((s[i] != car.y && check == 1) && (s[i] != car.z && check == 1))
		{
			mot++;
			check = 0;
		}
		i++;
	}
	return (mot);
}

static int		ft_count_letters2(const char *s, t_car car, int i)
{
	int k;

	k = 0;
	while (s[i] != car.y && s[i] != car.z)
	{
		k++;
		i++;
	}
	return (k);
}

static char		**whtab2(char **tab, int mot, t_car car, char const *s)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] && j < mot)
	{
		while (s[i] == car.y || s[i] == car.z)
			i++;
		k = ft_count_letters2(s, car, i);
		if (k == 0)
			return (0);
		tab[j] = ft_strsub(s, i, k);
		while (s[i] != car.y && s[i] != car.z)
			i++;
		i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_strsplit_2car(char const *s, t_car car)
{
	int		mot;
	char	**tab;

	if (s == NULL)
		return (NULL);
	mot = ft_count_words2(s, car);
	if (!(tab = (char**)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	whtab2(tab, mot, car, s);
	if (tab == NULL)
		return (0);
	return (tab);
}

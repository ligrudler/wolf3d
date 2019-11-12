/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:18:19 by lgrudler          #+#    #+#             */
/*   Updated: 2019/05/03 15:21:01 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int i;
	int mot;
	int check;

	i = 0;
	mot = 0;
	check = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			check = 1;
		if (s[i] != c && check == 1)
		{
			mot++;
			check = 0;
		}
		i++;
	}
	return (mot);
}

static int		ft_count_letters(const char *s, char c, int i)
{
	int k;

	k = 0;
	while (s[i] != c)
	{
		k++;
		i++;
	}
	return (k);
}

static char		**whtab(char **tab, int mot, char c, char const *s)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] && j < mot)
	{
		while (s[i] == c)
			i++;
		k = ft_count_letters(s, c, i);
		if (k == 0)
			return (0);
		tab[j] = ft_strsub(s, i, k);
		while (s[i] != c)
			i++;
		i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		mot;
	char	**tab;

	if (s == NULL)
		return (NULL);
	mot = ft_count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	whtab(tab, mot, c, s);
	if (tab == NULL)
		return (0);
	return (tab);
}

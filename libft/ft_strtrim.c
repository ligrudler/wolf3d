/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:24:11 by lgrudler          #+#    #+#             */
/*   Updated: 2019/05/09 17:34:35 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	stt;
	unsigned int	end;
	char			*s2;

	stt = 0;
	if (s == NULL)
		return (NULL);
	while ((s[stt] == ' ' || s[stt] == '\n' || s[stt] == '\t') && s[stt])
		stt++;
	end = ft_strlen(s);
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t'
				|| s[end] == '\0') && (end > stt))
		end--;
	s2 = ft_strsub(s, stt, (end + 1 - stt));
	return (s2);
}

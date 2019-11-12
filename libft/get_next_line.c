/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:20:12 by lgrudler          #+#    #+#             */
/*   Updated: 2019/03/05 19:29:27 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char		*str;
	const int	l1 = (s1) ? ft_strlen(s1) : 0;
	const int	l2 = (s2) ? ft_strlen(s2) : 0;

	if (!(str = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	return (str);
}

int		stockvariable(char **str, char **line)
{
	char *tmp;

	if (*str && (tmp = ft_strchr(*str, '\n')) != NULL)
	{
		tmp[0] = '\0';
		*line = ft_strdup(*str);
		tmp = ft_strdup(tmp + 1);
		free(*str);
		*str = tmp;
		if (tmp[0] == '\0')
		{
			free(*str);
			*str = NULL;
		}
		return (1);
	}
	return (0);
}

int		lastboucle(char **str, char **line)
{
	if (*str == NULL)
		return (0);
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[10240];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*temp;

	if (fd <= -1 || fd > 10240 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (stockvariable(&str[fd], line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = str[fd];
		if (!(str[fd] = ft_strjoin_gnl(temp, buf)))
			return (-1);
		free(temp);
		if (stockvariable(&str[fd], line))
			return (1);
	}
	if (ret <= -1)
		return (-1);
	if (lastboucle(&str[fd], line) == 1)
		return (1);
	return (0);
}

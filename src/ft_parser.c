/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:01:22 by grudler           #+#    #+#             */
/*   Updated: 2020/03/05 09:31:55 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

int		file_valid_name(char *file, char *ref)
{
	int i;
	int j;

	i = ft_strlen(file) - 1;
	j = ft_strlen(ref) - 1;
	while (j >= 0)
	{
		if (ref[j] != file[i])
			return (0);
		i--;
		j--;
	}
	return (i >= 0 ? 1 : 0);
}

void	stock_in_map(char *str, t_sdl *sdl)
{
	int i;

	sdl->pars.x_map = 0;
	sdl->pars.y_map = 0;
	i = 0;
	while (sdl->pars.y_map < sdl->pars.nb_lin && str[i])
	{
		sdl->pars.x_map = 0;
		while (sdl->pars.x_map < sdl->pars.nb_col && str[i])
		{
			if (ft_isdigit(str[i]))
			{
				sdl->pars.map[sdl->pars.y_map][sdl->pars.x_map] =
					ft_atoi(&str[i]);
				sdl->pars.x_map++;
			}
			i++;
		}
		sdl->pars.y_map++;
		i++;
	}
}

int		create_map(char *str, t_sdl *sdl)
{
	int i;

	i = -1;
	if (check_column_line(str, sdl, i) == 0)
	{
		ft_putendl("Error column number");
		return (0);
	}
	if (!(sdl->pars.map = (int **)malloc(sizeof(int *) * sdl->pars.nb_lin)))
	{
		free(sdl->pars.map);
		return (0);
	}
	while (++i < sdl->pars.nb_lin)
		if (!(sdl->pars.map[i] = (int *)malloc(sizeof(int) * sdl->pars.nb_col)))
		{
			free_tpars(sdl, ++i);
			return (0);
		}
	stock_in_map(str, sdl);
	if (!(check_close_map(sdl)))
	{
		ft_putendl("Map Not Closed");
		free_tpars(sdl, i);
		return (0);
	}
	ft_putendl("Map...[Checked]");
	return (1);
}

int		ft_parser(int fd, t_sdl *sdl)
{
	char	buff[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		ret;

	str = NULL;
	ret = read(fd, buff, 4);
	if (ft_strcmp(buff, CHECKCODE))
	{
		ft_putendl("Incorrect Map");
		return (0);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin_gnl(tmp, buff);
		free(tmp);
	}
	if (str == NULL || ret <= -1 || !(create_map(str, sdl)))
		map_error(sdl, str);
	free(str);
	return (1);
}

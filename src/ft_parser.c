/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:01:22 by grudler           #+#    #+#             */
/*   Updated: 2020/03/03 11:22:59 by qlouisia         ###   ########.fr       */
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

int		check_plus(t_sdl *check, int line, int column)
{
	if (check->pars.map[line][column] == 1)
	{
		if (check->pars.verif == 1)
		{
			ft_putstr("Only one spawn\n");
			return (0);
		}
		check->pars.spawnx = column;
		check->pars.spawny = line;
		check->pars.verif = 1;
	}
	if (line == 0 && check->pars.map[0][column] == 0)
		return (0);
	else if (line == check->pars.nb_lin - 1 && check->pars.map[line][column] == 0)
		return (0);
	else if ((column == 0 || column == check->pars.nb_col - 1) && check->pars.map[line][column] == 0)
		return (0);
	return (1);
}

int		check_close_map(t_sdl *check)
{
	int line;
	int column;

	line = -1;
	while (++line < check->pars.nb_lin)
	{
		column = -1;
		while (++column < check->pars.nb_col)
			if (check_plus(check, line, column) == 0)
			{
				ft_putstr("ERROR MAP");
				return (0);
			}
	}
	if (check->pars.verif == 0)
	{
		ft_putstr("Need a spawn");
		return (0);
	}
	ft_putstr("Map VALID");
	return (1);
}

int		check_column_line(char *str, t_sdl *sdl)
{
	int i;
	int tmp;
	int check;

	i = -1;
	tmp = 0;
	while (str[++i])
	{
		tmp = sdl->pars.nb_col;
		sdl->pars.nb_col = 0;
		while (str[i] && str[i] != '\n')
			if (ft_isdigit(str[i++]))
			{
				sdl->pars.nb_col++;
				check = 1;
			}
		if (check == 1 && tmp != 0 && tmp != sdl->pars.nb_col)
			return (0);
		else if (check == 1)
		{
			sdl->pars.nb_lin++;
			check = 0;
		}
		else if (check == 0)
			sdl->pars.nb_col = tmp;
	}
	return (1);
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
				sdl->pars.map[sdl->pars.y_map][sdl->pars.x_map] = ft_atoi(&str[i]);
				sdl->pars.x_map++;
			}
			i++;
		}
		sdl->pars.y_map++;
		i++;
	}
}

int		create_map(char *str, t_sdl *sdl) // il faudrait penser a bien tout free (str ex) dans les retour erreur de malloc
{
	int i;

	i = 0;
	if (check_column_line(str, sdl) == 0)
	{
		ft_putstr("ERROR NB COLONNE");
		ft_error();
	}
	if (!(sdl->pars.map = (int **)malloc(sizeof(int *) * sdl->pars.nb_lin)))
		return (0);
	while (i < sdl->pars.nb_lin)
	{
		if (!(sdl->pars.map[i] = (int *)malloc(sizeof(int) * sdl->pars.nb_col)))
			return (0);
		i++;
	}
	stock_in_map(str, sdl);
	if (!check_close_map(sdl))
	{
		ft_putendl("Map NOT CLOSED");
		return (0);
	}
	return (1);
}

int		ft_parser(int fd, t_sdl *sdl)
{
	char buff[BUFF_SIZE + 1];
	char *str;
	char *tmp;
	int ret;

	str = NULL;
	ret = read(fd, buff, 4);
	// buff[4] = '\0';
	if (ft_strcmp (buff, CHECKCODE))
	{
		ft_putendl ("Incorrect Map");
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
	{
		free(str);
		ft_putendl("MAP ERROR");
		ft_error();
		return (0);
	}
	free(str);
	return (1);
}

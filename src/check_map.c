/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:45:33 by grudler           #+#    #+#             */
/*   Updated: 2020/03/03 11:47:35 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

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

int		check_column_line(char *str, t_sdl *sdl, int i)
{
	int tmp;
	int check;

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

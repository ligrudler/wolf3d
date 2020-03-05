/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:45:33 by grudler           #+#    #+#             */
/*   Updated: 2020/03/05 16:12:59 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
**                 #######################################
**                 ############## check_plus #############
**                 #######################################
**
** Return error if more than one spawn exist.
** Return error if the map isn't closed by walls.
*/

int		check_plus(t_sdl *check, int line, int column)
{
	if (check->pars.map[line][column] == 1)
	{
		if (check->pars.verif == 1)
		{
			ft_putendl("Only one spawn");
			return (0);
		}
		check->pars.spawnx = column;
		check->pars.spawny = line;
		check->pars.verif = 1;
	}
	if (line == 0 && check->pars.map[0][column] == 0)
		return (0);
	else if (line == check->pars.nb_lin - 1
		&& check->pars.map[line][column] == 0)
		return (0);
	else if ((column == 0 || column == check->pars.nb_col - 1)
		&& check->pars.map[line][column] == 0)
		return (0);
	if (check->pars.map[line][column] > 2)
		return (0);
	return (1);
}

/*
**                 #######################################
**                 ########### check_close_map ###########
**                 #######################################
**
** Return error if the map is not closed by walls.
** Return error if no spawn exists.
*/

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
				return (0);
	}
	if (check->pars.verif == 0)
	{
		ft_putendl("Need a spawn");
		return (0);
	}
	return (1);
}

/*
**                 #######################################
**                 ########## check_column_line ##########
**                 #######################################
**
** Calculate number of line and number of column in the map.
** Return error if the number of column is different in another line.
*/

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

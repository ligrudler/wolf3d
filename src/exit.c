/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:31 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/05 15:48:15 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
**                 #######################################
**                 ############### map_error #############
**                 #######################################
**
** Free all allocated data if a error occure in parsing
*/

void		map_error(t_sdl *sdl, char *str)
{
	free(str);
	free(sdl);
	ft_putendl("Map error");
	exit(0);
}

/*
**                 #######################################
**                 ############## free_tpars #############
**                 #######################################
**
** Free all allocated data allocated when parsing the map at the end of
** the program.
*/

int			free_tpars(t_sdl *map, int size)
{
	int	line;

	line = 0;
	while (line < size)
	{
		free(map->pars.map[line]);
		line++;
	}
	free(map->pars.map);
	return (0);
}

/*
**                 #######################################
**                 ############# free_weapons ############
**                 #######################################
**
** Free all frame loaded in weapons structure.
*/

void		free_weapons(t_weapons *wp)
{
	int i;

	i = 0;
	while (i < 5)
	{
		exit8bit(wp->frame[i]);
		i++;
	}
}

/*
**                 #######################################
**                 ############## free_image #############
**                 #######################################
**
** Free all images loaded (texture + frame)
*/

void		free_image(t_sdl *sdl)
{
	int i;

	i = 0;
	if (sdl->menu_img)
		exit8bit(sdl->menu_img);
	while (i < 4)
	{
		if (sdl->txt[i])
			exit8bit(sdl->txt[i]);
		i++;
	}
	if (sdl->weapons)
		free_weapons(sdl->weapons);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:31 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/05 09:33:57 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void		map_error(t_sdl *sdl, char *str)
{
	free(str);
	free(sdl);
	ft_putendl("Map error");
	exit(0);
}

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

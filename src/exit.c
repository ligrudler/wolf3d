/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:31 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/04 13:27:42 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

int		free_tpars(t_sdl *map, int size)
{
	int	line;

	line = 0;
	while (line < size)
	{
		free(map->pars.map[line]);
		line++;
	}
	free(map->pars.map);
	ft_putstr("MAP CLEANED");
	return (0);
}

void free_weapons(t_weapons *wp)
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
	printf("free weapons\n");
	if (sdl->weapons)
		free_weapons(sdl->weapons);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:31 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/24 15:29:33 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"
#include <stdlib.h>

int 	free_tpars(t_sdl *map, int size)
{
	int line;

	line = 0;
	while (line < size)
	{
		free(map->pars.map[line]);
		line++;
	}
	free(map->pars.map);
	ft_putstr("MAP CLEANED");
	return(0);
}

// a reprendre et a ameliorer au fil des images
int free_image (t_sdl *sdl)
{
	exit8bit(sdl->menu_img);
	exit8bit(sdl->txt);
	exit8bit(sdl->txt2);
	exit8bit(sdl->txt3);
}
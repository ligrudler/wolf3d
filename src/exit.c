/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:31 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/20 16:01:44 by qlouisia         ###   ########.fr       */
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
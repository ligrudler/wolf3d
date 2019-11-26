/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:31 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/26 20:01:19 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"
#include <stdlib.h>

int 	free_tpars(t_pars *map, int size)
{
	int line;
	
	line = 0;
	while (line < size)
	{
		free(map->map[line]);
		line++;
	}
	free(map->map);
	ft_putstr("MAP CLEANED");
	return(0);
}

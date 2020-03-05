/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:13:31 by lgrudler          #+#    #+#             */
/*   Updated: 2020/03/05 11:22:32 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
**                 #######################################
**                 ############# clear screen ############
**                 #######################################
**
** Function to clear the screen, call every time in the display loop
*/

void	clear_screen(t_sdl *sdl)
{
	uint32_t	*pixels;
	int			i;
	int			n;

	n = WINY * WINX;
	i = 0;
	pixels = (uint32_t *)sdl->screen->pixels;
	while (i < n)
	{
		pixels[i] = 0;
		i++;
	}
}

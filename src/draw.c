/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:19:49 by lgrudler          #+#    #+#             */
/*   Updated: 2020/01/06 14:32:00 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	draw(t_sdl *sdl)
{
	draw_sky_ground(sdl);
	raycast(sdl);
	SDL_RenderPresent(sdl->renderer);
}

void	draw_sky_ground(t_sdl *sdl)
{
	int i;
	int j;

	j = 0;
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 255, 0);
	while (j++ <= WINY / 2)
	{
		i = 0;
		while (i++ < WINX)
		{
			SDL_RenderDrawPoint(sdl->renderer, i, j);
		}
	}
	j = WINY / 2;
	SDL_SetRenderDrawColor(sdl->renderer, 0, 255, 255, 0);
	while (j++ <= WINY)
	{
		i = 0;
		while (i++ < WINX)
		{
			SDL_RenderDrawPoint(sdl->renderer, i, j);
		}
	}
}

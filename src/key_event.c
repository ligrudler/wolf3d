/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:25:38 by grudler           #+#    #+#             */
/*   Updated: 2020/01/21 19:55:19 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	horizontal_deplacement(t_sdl *sdl)
{
	if (sdl->key[SDL_SCANCODE_LEFT])
	{
		double oldDirX = sdl->rcst.dirX;
		sdl->rcst.dirX = sdl->rcst.dirX * cos(-MOVEDIR) - sdl->rcst.dirY * sin(-MOVEDIR);
		sdl->rcst.dirY = oldDirX * sin(-MOVEDIR) + sdl->rcst.dirY * cos(-MOVEDIR);
		double oldPlaneX = sdl->rcst.planX;
		sdl->rcst.planX = sdl->rcst.planX * cos(-MOVEDIR) - sdl->rcst.planY * sin(-MOVEDIR);
		sdl->rcst.planY = oldPlaneX * sin(-MOVEDIR) + sdl->rcst.planY * cos(-MOVEDIR);
	}
	if (sdl->key[SDL_SCANCODE_RIGHT])
	{
		double oldDirX = sdl->rcst.dirX;
		sdl->rcst.dirX = sdl->rcst.dirX * cos(MOVEDIR) - sdl->rcst.dirY * sin(MOVEDIR);
		sdl->rcst.dirY = oldDirX * sin(MOVEDIR) + sdl->rcst.dirY * cos(MOVEDIR);
		double oldPlaneX = sdl->rcst.planX;
		sdl->rcst.planX = sdl->rcst.planX * cos(MOVEDIR) - sdl->rcst.planY * sin(MOVEDIR);
		sdl->rcst.planY = oldPlaneX * sin(MOVEDIR) + sdl->rcst.planY * cos(MOVEDIR);
	}
}

void	vertical_deplacement(t_sdl *sdl)
{
	double y;
	if (sdl->rcst.dirY < 0)
		y = sdl->rcst.posy - 0.1;
	else if (sdl->rcst.dirY >= 0)
		y = sdl->rcst.posy + 0.1;

	if (sdl->key[SDL_SCANCODE_UP])
	{
		if ((sdl->pars.map[(int)(y + sdl->rcst.dirY * MOVE)][(int)sdl->rcst.posx] == 0) && (sdl->pars.map[(int)y][(int)(sdl->rcst.posx + sdl->rcst.dirX * MOVE)] == 0))
		{
			sdl->rcst.posy += sdl->rcst.dirY * MOVE;
			sdl->rcst.posx += sdl->rcst.dirX * MOVE;
		}
	}
	if (sdl->key[SDL_SCANCODE_DOWN])
	{
		if ((sdl->pars.map[(int)(y - sdl->rcst.dirY * MOVE)][(int)sdl->rcst.posx] == 0) && (sdl->pars.map[(int)y][(int)(sdl->rcst.posx - sdl->rcst.dirX * MOVE)] == 0))
		{
			sdl->rcst.posy -= sdl->rcst.dirY * MOVE;
			sdl->rcst.posx -= sdl->rcst.dirX * MOVE;
		}
	}
}

void	event(t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->evenements))
	{
		if (sdl->evenements.type == SDL_KEYDOWN)
			sdl->key[sdl->evenements.key.keysym.scancode] = 1;
		if (sdl->evenements.type == SDL_KEYUP)
			sdl->key[sdl->evenements.key.keysym.scancode] = 0;
	}
	if (sdl->evenements.type == SDL_QUIT)
		sdl->end = 1;
	if (sdl->key[SDL_SCANCODE_ESCAPE])
		sdl->end = 1;
	if (sdl->key[SDL_SCANCODE_SPACE])
		init_raycast(sdl);

	vertical_deplacement(sdl);
	horizontal_deplacement(sdl);
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0);
	if (SDL_RenderClear(sdl->renderer) != 0)
		ft_error();
}

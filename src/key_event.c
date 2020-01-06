/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:25:38 by grudler           #+#    #+#             */
/*   Updated: 2020/01/06 13:19:53 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	horizontal_deplacement(t_sdl *sdl)
{
	if (sdl->key[SDL_SCANCODE_A])
	{
		double oldDirX = sdl->rcst.dirX;
		sdl->rcst.dirX = sdl->rcst.dirX * cos(-MOVEDIR) - sdl->rcst.dirY * sin(-MOVEDIR);
		sdl->rcst.dirY = oldDirX * sin(-MOVEDIR) + sdl->rcst.dirY * cos(-MOVEDIR);
		double oldPlaneX = sdl->rcst.planX;
		sdl->rcst.planX = sdl->rcst.planX * cos(-MOVEDIR) - sdl->rcst.planY * sin(-MOVEDIR);
		sdl->rcst.planY = oldPlaneX * sin(-MOVEDIR) + sdl->rcst.planY * cos(-MOVEDIR);
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0);
		if (SDL_RenderClear(sdl->renderer) != 0)
			ft_error();
		raycast(sdl);
	}
	if (sdl->key[SDL_SCANCODE_D])
	{
		double oldDirX = sdl->rcst.dirX;
		sdl->rcst.dirX = sdl->rcst.dirX * cos(MOVEDIR) - sdl->rcst.dirY * sin(MOVEDIR);
		sdl->rcst.dirY = oldDirX * sin(MOVEDIR) + sdl->rcst.dirY * cos(MOVEDIR);
		double oldPlaneX = sdl->rcst.planX;
		sdl->rcst.planX = sdl->rcst.planX * cos(MOVEDIR) - sdl->rcst.planY * sin(MOVEDIR);
		sdl->rcst.planY = oldPlaneX * sin(MOVEDIR) + sdl->rcst.planY * cos(MOVEDIR);
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0);
		if (SDL_RenderClear(sdl->renderer) != 0)
			ft_error();
		raycast(sdl);
	}
}

void	vertical_deplacement(t_sdl *sdl)
{
	if (sdl->key[SDL_SCANCODE_W] && sdl->rcst.posy <= 24 && sdl->rcst.posx < 24)
	{
		if ((sdl->pars.map[(int)(sdl->rcst.posy + sdl->rcst.dirY * MOVE)][(int)sdl->rcst.posx] == 0) && (sdl->pars.map[(int)sdl->rcst.posy][(int)(sdl->rcst.posx + sdl->rcst.dirX * MOVE)] == 0))
		{
			sdl->rcst.posy += sdl->rcst.dirY * MOVE;
			sdl->rcst.posx += sdl->rcst.dirX * MOVE;
		}
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0);
		if (SDL_RenderClear(sdl->renderer) != 0)
			ft_error();
		raycast(sdl);
	}
	if (sdl->key[SDL_SCANCODE_S] && sdl->rcst.posy > 0 && sdl->rcst.posx >= 0)
	{
		if ((sdl->pars.map[(int)(sdl->rcst.posy - sdl->rcst.dirY * MOVE)][(int)sdl->rcst.posx] == 0) && (sdl->pars.map[(int)sdl->rcst.posy][(int)(sdl->rcst.posx - sdl->rcst.dirX * MOVE)] == 0))
		{
			sdl->rcst.posy -= sdl->rcst.dirY * MOVE;
			sdl->rcst.posx -= sdl->rcst.dirX * MOVE;
		}
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0);
		if (SDL_RenderClear(sdl->renderer) != 0)
			ft_error();
		raycast(sdl);
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
	if (sdl->key[SDL_SCANCODE_ESCAPE])
		sdl->end = 1;
	vertical_deplacement(sdl);
	horizontal_deplacement(sdl);
}

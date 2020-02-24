/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:25:38 by grudler           #+#    #+#             */
/*   Updated: 2020/02/24 14:21:12 by qlouisia         ###   ########.fr       */
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
	if (sdl->key[SDL_SCANCODE_UP])
	{
		if (sdl->pars.map[(int)(sdl->rcst.posy + sdl->rcst.dirY * HITBOX)][(int)(sdl->rcst.posx + sdl->rcst.dirX * HITBOX)] == 0)
		{
			if(sdl->pars.map[(int)(sdl->rcst.posy)][(int)(sdl->rcst.posx + sdl->rcst.dirX * HITBOX)] == 0)
				sdl->rcst.posx += sdl->rcst.dirX * sdl->move;
			if(sdl->pars.map[(int)(sdl->rcst.posy + sdl->rcst.dirY * HITBOX)][(int)(sdl->rcst.posx)] == 0)
				sdl->rcst.posy += sdl->rcst.dirY * sdl->move;
		}
	}
	if (sdl->key[SDL_SCANCODE_DOWN])
	{
		if (sdl->pars.map[(int)(sdl->rcst.posy - sdl->rcst.dirY * HITBOX)][(int)(sdl->rcst.posx - sdl->rcst.dirX * HITBOX)] == 0)
		{
			if(sdl->pars.map[(int)(sdl->rcst.posy)][(int)(sdl->rcst.posx - sdl->rcst.dirX * HITBOX)] == 0)
				sdl->rcst.posx -= sdl->rcst.dirX * sdl->move;
			if(sdl->pars.map[(int)(sdl->rcst.posy - sdl->rcst.dirY * HITBOX)][(int)(sdl->rcst.posx)] == 0)
				sdl->rcst.posy -= sdl->rcst.dirY * sdl->move;
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
	if (sdl->key[SDL_SCANCODE_SPACE] && sdl->menu == true)
		sdl->menu = false;
	else {
		if (sdl->key[SDL_SCANCODE_SPACE])
			init_variables(sdl);
		if (sdl->key[SDL_SCANCODE_LSHIFT])
			sdl->move = 0.06;
		else
			sdl->move = 0.03;

		vertical_deplacement(sdl);
		horizontal_deplacement(sdl);
	}
	/*SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0);
	if (SDL_RenderClear(sdl->renderer) != 0)
		ft_error();*/
}

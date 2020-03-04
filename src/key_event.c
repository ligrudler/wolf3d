/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:25:38 by grudler           #+#    #+#             */
/*   Updated: 2020/03/04 20:04:32 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	horizontal_deplacement(t_sdl *sdl)
{
	double odx;
	double opx;

	odx = sdl->rcst.dirx;
	opx = sdl->rcst.planx;
	if (sdl->key[SDL_SCANCODE_LEFT])
	{
		sdl->rcst.dirx = sdl->rcst.dirx * cos(-MOVEDIR)
			- sdl->rcst.diry * sin(-MOVEDIR);
		sdl->rcst.diry = odx * sin(-MOVEDIR) + sdl->rcst.diry * cos(-MOVEDIR);
		sdl->rcst.planx = sdl->rcst.planx * cos(-MOVEDIR)
			- sdl->rcst.plany * sin(-MOVEDIR);
		sdl->rcst.plany = opx * sin(-MOVEDIR) + sdl->rcst.plany * cos(-MOVEDIR);
	}
	if (sdl->key[SDL_SCANCODE_RIGHT])
	{
		sdl->rcst.dirx = sdl->rcst.dirx * cos(MOVEDIR)
			- sdl->rcst.diry * sin(MOVEDIR);
		sdl->rcst.diry = odx * sin(MOVEDIR) + sdl->rcst.diry * cos(MOVEDIR);
		sdl->rcst.planx = sdl->rcst.planx * cos(MOVEDIR)
			- sdl->rcst.plany * sin(MOVEDIR);
		sdl->rcst.plany = opx * sin(MOVEDIR) + sdl->rcst.plany * cos(MOVEDIR);
	}
}

void	vertical_deplacement(t_sdl *sdl)
{
	if (sdl->key[SDL_SCANCODE_UP])
		if (sdl->pars.map[(int)(sdl->rcst.posy + sdl->rcst.diry * HITBOX)]
			[(int)(sdl->rcst.posx + sdl->rcst.dirx * HITBOX)] < 2)
		{
			if (sdl->pars.map[(int)(sdl->rcst.posy)][(int)(sdl->rcst.posx
				+ sdl->rcst.dirx * HITBOX)] < 2)
				sdl->rcst.posx += sdl->rcst.dirx * sdl->move;
			if (sdl->pars.map[(int)(sdl->rcst.posy + sdl->rcst.diry
				* HITBOX)][(int)(sdl->rcst.posx)] < 2)
				sdl->rcst.posy += sdl->rcst.diry * sdl->move;
		}
	if (sdl->key[SDL_SCANCODE_DOWN])
		if (sdl->pars.map[(int)(sdl->rcst.posy - sdl->rcst.diry * HITBOX)]
			[(int)(sdl->rcst.posx - sdl->rcst.dirx * HITBOX)] < 2)
		{
			if (sdl->pars.map[(int)(sdl->rcst.posy)][(int)(sdl->rcst.posx
				- sdl->rcst.dirx * HITBOX)] < 2)
				sdl->rcst.posx -= sdl->rcst.dirx * sdl->move;
			if (sdl->pars.map[(int)(sdl->rcst.posy
				- sdl->rcst.diry * HITBOX)][(int)(sdl->rcst.posx)] < 2)
				sdl->rcst.posy -= sdl->rcst.diry * sdl->move;
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
	if (sdl->evenements.type == SDL_QUIT || sdl->key[SDL_SCANCODE_ESCAPE])
		sdl->end = 1;
	if (sdl->key[SDL_SCANCODE_SPACE] && sdl->menu == true)
		sdl->menu = false;
	else
	{
		if (sdl->key[SDL_SCANCODE_SPACE])
			sdl->weapons->shoot = true;
		if (sdl->key[SDL_SCANCODE_LSHIFT])
			sdl->move = 0.06;
		else
			sdl->move = 0.03;
		vertical_deplacement(sdl);
		horizontal_deplacement(sdl);
	}
}

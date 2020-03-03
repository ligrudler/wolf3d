/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:25:38 by grudler           #+#    #+#             */
/*   Updated: 2020/03/03 16:40:50 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	horizontal_deplacement(t_sdl *sdl)
{
	double odx;
	double opx;

	odx = sdl->rcst.dirX;
	opx = sdl->rcst.planX;
	if (sdl->key[SDL_SCANCODE_LEFT])
	{
		sdl->rcst.dirX = sdl->rcst.dirX * cos(-MOVEDIR)
			- sdl->rcst.dirY * sin(-MOVEDIR);
		sdl->rcst.dirY = odx * sin(-MOVEDIR) + sdl->rcst.dirY * cos(-MOVEDIR);
		sdl->rcst.planX = sdl->rcst.planX * cos(-MOVEDIR)
			- sdl->rcst.planY * sin(-MOVEDIR);
		sdl->rcst.planY = opx * sin(-MOVEDIR) + sdl->rcst.planY * cos(-MOVEDIR);
	}
	if (sdl->key[SDL_SCANCODE_RIGHT])
	{
		sdl->rcst.dirX = sdl->rcst.dirX * cos(MOVEDIR)
			- sdl->rcst.dirY * sin(MOVEDIR);
		sdl->rcst.dirY = odx * sin(MOVEDIR) + sdl->rcst.dirY * cos(MOVEDIR);
		sdl->rcst.planX = sdl->rcst.planX * cos(MOVEDIR)
			- sdl->rcst.planY * sin(MOVEDIR);
		sdl->rcst.planY = opx * sin(MOVEDIR) + sdl->rcst.planY * cos(MOVEDIR);
	}
}

void	vertical_deplacement(t_sdl *sdl)
{
	if (sdl->key[SDL_SCANCODE_UP])
		if (sdl->pars.map[(int)(sdl->rcst.posy + sdl->rcst.dirY * HITBOX)]
			[(int)(sdl->rcst.posx + sdl->rcst.dirX * HITBOX)] < 2)
		{
			if (sdl->pars.map[(int)(sdl->rcst.posy)][(int)(sdl->rcst.posx
				+ sdl->rcst.dirX * HITBOX)] < 2)
				sdl->rcst.posx += sdl->rcst.dirX * sdl->move;
			if (sdl->pars.map[(int)(sdl->rcst.posy + sdl->rcst.dirY
				* HITBOX)][(int)(sdl->rcst.posx)] < 2)
				sdl->rcst.posy += sdl->rcst.dirY * sdl->move;
		}
	if (sdl->key[SDL_SCANCODE_DOWN])
		if (sdl->pars.map[(int)(sdl->rcst.posy - sdl->rcst.dirY * HITBOX)]
			[(int)(sdl->rcst.posx - sdl->rcst.dirX * HITBOX)] < 2)
		{
			if (sdl->pars.map[(int)(sdl->rcst.posy)][(int)(sdl->rcst.posx
				- sdl->rcst.dirX * HITBOX)] < 2)
				sdl->rcst.posx -= sdl->rcst.dirX * sdl->move;
			if (sdl->pars.map[(int)(sdl->rcst.posy
				- sdl->rcst.dirY * HITBOX)][(int)(sdl->rcst.posx)] < 2)
				sdl->rcst.posy -= sdl->rcst.dirY * sdl->move;
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
	{
		sdl->end = 1;
		printf("exit by action\n");
	}
	if (sdl->key[SDL_SCANCODE_SPACE] && sdl->menu == true)
		sdl->menu = false;
	else
	{
		if (sdl->key[SDL_SCANCODE_SPACE])
			sdl->weapons->shoot = true;
			//init_variables(sdl);
		if (sdl->key[SDL_SCANCODE_LSHIFT])
			sdl->move = 0.06;
		else
			sdl->move = 0.03;
		vertical_deplacement(sdl);
		horizontal_deplacement(sdl);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2019/12/05 00:42:15 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

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
	if (sdl->key[SDL_SCANCODE_S] && sdl->rcst.posy <= 24 && sdl->rcst.posx < 24)
	{
		if (sdl->pars.map[(int)(sdl->rcst.posy * MOVE)][(int)sdl->rcst.posx] == 0)
			sdl->rcst.posy *= MOVE;
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0);
		if (SDL_RenderClear(sdl->renderer) != 0)
			ft_error();
		raycast(sdl);
	}
	if (sdl->key[SDL_SCANCODE_W] && sdl->rcst.posy > 0 && sdl->rcst.posx >= 0)
	{
		if (sdl->pars.map[(int)(sdl->rcst.posy / MOVE)][(int)sdl->rcst.posx] == 0)
			sdl->rcst.posy /= MOVE;
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0);
		if (SDL_RenderClear(sdl->renderer) != 0)
			ft_error();
		raycast(sdl);
	}
	if (sdl->key[SDL_SCANCODE_D])
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
	if (sdl->key[SDL_SCANCODE_A])
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

int init_sdl(t_sdl *sdl)
{
	int		terminer;

	terminer = 0;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error();
	if (!(sdl->fenetre = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_SHOWN)))
		ft_error();
	if (!(sdl->renderer = SDL_CreateRenderer(sdl->fenetre, -1, SDL_RENDERER_SOFTWARE)))
		ft_error();
	return (0);
}


int		main(int argc, char **argv)
{
	int fd;
	t_sdl sdl;

	sdl.end = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_parser(fd, &sdl);
		init_sdl(&sdl);
		init_raycast(&sdl);
		raycast(&sdl);
		while (!(sdl.end))
			event(&sdl);
		SDL_DestroyRenderer(sdl.renderer);
		SDL_DestroyWindow(sdl.fenetre);
		SDL_Quit();
		free_tpars(&sdl, sdl.pars.nb_lin);
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp

	return (0);
}

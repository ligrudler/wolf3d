/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2019/11/26 20:31:01 by grudler          ###   ########.fr       */
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
}

void	draw(t_sdl *sdl)
{
	int		i;

	i = 0;
	SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 0, 0);
	while (i < 400)
	{
		sdl->point[i].x = i;
		sdl->point[i].y = 2 * i + 400 ;
		i++;
	}
	SDL_RenderDrawPoints(sdl->renderer, sdl->point, 400);
	SDL_RenderPresent(sdl->renderer);
	event(sdl);
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
	t_pars pars;
	t_sdl sdl;

	sdl.end = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_parser(fd, &pars);
		init_sdl(&sdl);
		draw(&sdl);
		while (!(sdl.end))
			event(&sdl);
		SDL_DestroyRenderer(sdl.renderer);
		SDL_DestroyWindow(sdl.fenetre);
		SDL_Quit();
		free_tpars(&pars,pars.nb_lin);
		while(1);
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp

	return (0);
}

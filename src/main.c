/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2019/11/27 20:31:29 by qlouisia         ###   ########.fr       */
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

/*
void	draw(t_sdl *sdl)
{
	int		i;
	
	i = 0;
	SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 0, 0);
	while (i < 400)
	{
		sdl->line.p1.x = 100;
		sdl->line.p1.y = 100 + i;
		sdl->line.p2.x = 400;
		sdl->line.p2.y = 400 + i;
		i++;
		ft_drawline(sdl);
	}
	SDL_RenderPresent(sdl->renderer);
	event(sdl);
}
*/
void	draw(t_sdl *sdl)
{
	t_pt p1;
	t_pt p2;
	SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 0, 0);
	set_point(&p1,200,200);
	set_point(&p2,220,220);
	// ft_drawline(&p1, &p2, sdl);
	draw_rect(sdl, &p1, &p2);
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
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp

	return (0);
}

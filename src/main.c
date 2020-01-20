/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2020/01/20 11:31:22 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

int init_sdl(t_sdl *sdl)
{
	int		terminer;

	terminer = 0;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
	if (!(sdl->fenetre = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_SHOWN)))
		ft_error();
	if (!(sdl->renderer = SDL_CreateRenderer(sdl->fenetre, -1, SDL_RENDERER_SOFTWARE)))
		ft_error();
	if (!(sdl->img = (uint32_t*)malloc(WINX * (WINY + 1) * sizeof(uint32_t))))
		ft_error(); // nettoyage et free � cr�er 
	if (! (sdl->texture = SDL_CreateTexture(sdl->renderer, ARGB, 1, WINX, WINY)))
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
		while (!(sdl.end))
		{
			event(&sdl);
			fps_limit(&sdl);
			draw(&sdl);
		}
		SDL_DestroyRenderer(sdl.renderer);
		SDL_DestroyWindow(sdl.fenetre);
		SDL_Quit();
		free_tpars(&sdl, sdl.pars.nb_lin);
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp

	return (0);
}

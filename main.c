/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2019/11/20 15:55:17 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Includes/wolf3d.h"

int beautifull_window()
{
	int		terminer;
	int		i;
	t_sdl	sdl;

	terminer = 0;
	i = 0;

	// Initialisation de la SDL

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return (-1);
	}

	// Création de la fenêtre

	sdl.fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	if(sdl.fenetre == 0)
	{
		SDL_Quit();

		return -1;
	}

	if (!(sdl.renderer = SDL_CreateRenderer(sdl.fenetre, -1, SDL_RENDERER_SOFTWARE)))
		ft_error();
	SDL_SetRenderDrawColor(sdl.renderer, 255, 0, 0, 255);
	while (i < 800)
	{
		sdl.point[i].x = i;
		sdl.point[i].y = 400;
		i++;
	}
	SDL_RenderDrawPoints(sdl.renderer, sdl.point, 800);
	SDL_RenderPresent(sdl.renderer);
	// On quitte la SDL
	// Boucle principale

	while(!terminer)
	{
		SDL_WaitEvent(&sdl.evenements);

		if(sdl.evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;
	}
	SDL_DestroyWindow(sdl.fenetre);
	SDL_Quit();
	return (0);
}


int		main(int argc, char **argv)
{
	int fd;
	t_pars pars;
	int i = 0;
	int j = 0;
	beautifull_window();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_parser(fd, &pars);
		while (j < pars.nb_lin) // Test parsing
		{
			i = 0;
			while (i < pars.nb_col)
			{
				printf("%d", pars.map[j][i]);
				i++;
			}
			printf("%c", '\n');
			j++;
		}
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp

	return 0;
}

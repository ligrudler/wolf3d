/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2019/11/20 18:06:17 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Includes/wolf3d.h"

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

	if (!(sdl.fenetre = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_SHOWN)))
	{
		SDL_Quit();
		return (-1);
	}

	if (!(sdl.renderer = SDL_CreateRenderer(sdl.fenetre, -1, SDL_RENDERER_SOFTWARE)))
		ft_error();
	SDL_SetRenderDrawColor(sdl.renderer, 255, 255, 0, 0);
	while (i < 400)
	{
		sdl.point[i].x = i;
		sdl.point[i].y = 2* i + 400 ;
		i++;
	}
	SDL_RenderDrawPoints(sdl.renderer, sdl.point, 400);
	SDL_RenderPresent(sdl.renderer);
	// On quitte la SDL
	// Boucle principale

	while(!terminer)
	{
		SDL_WaitEvent(&sdl.evenements);

		if(sdl.evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;
	}
	SDL_DestroyRenderer(sdl.renderer);
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

	return (0);
}

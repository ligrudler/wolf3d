/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2020/01/23 17:43:58 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

// fonction pour initialiser les textures
// Penser a virer les printfs 
int init_texture (t_sdl *sdl)
{
	sdl->surf = SDL_LoadBMP("./ressources/Blue4.bmp");
	if (sdl->surf)
	{
		// image = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_ARGB8888, 0);
		// sdl->test_texture = SDL_CreateTextureFromSurface(sdl->renderer, image);
		// if (sdl->test_texture)
		// {
			printf("texture cree\n");
			return (1);
		// }
		// else
		// 	printf("error text\n");
	}
	else
		printf("echec de chargement du sprite (%s)\n", SDL_GetError());
	return (0);

}

int init_sdl(t_sdl *sdl)
{
	int		terminer;

	terminer = 0;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return (1);
	}
	if (!(sdl->fenetre = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_SHOWN)))
		ft_error();
	// Creer la surface pour afficher la fenetre
	sdl->screen = SDL_GetWindowSurface(sdl->fenetre);
	printf("WINDOW Create\n");
	if (! (init_texture(sdl)))
		ft_error();
	// Creer la surface de travail
	sdl->img = SDL_CreateRGBSurfaceWithFormat(0, WINX, WINY, 32, SDL_PIXELFORMAT_ARGB32);
    if (sdl->img == NULL) {
        ft_error();
	}
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
		printf("end initialization\n");
		while (!(sdl.end))
		{
			event(&sdl);
			//fps_limit(&sdl); // affichage de FPS 
			draw(&sdl);
		}
		SDL_FreeSurface((&sdl)->img);
		SDL_FreeSurface((&sdl)->screen);
		SDL_DestroyWindow(sdl.fenetre);
		SDL_Quit();
		free_tpars(&sdl, sdl.pars.nb_lin);
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp

	return (0);
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2020/02/20 18:04:35 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"
#include "../Includes/wolf3d.h"
// fonction pour initialiser les textures
// Penser a virer les printfs
int init_texture (t_sdl *sdl)
{
	SDL_Surface *tmp;
	
	sdl->txt = load_image("./ressources/Blue4.bmp");
	if (sdl->txt)
	{
		tmp = sdl->img;
		sdl->img = SDL_ConvertSurfaceFormat(sdl->img,SDL_PIXELFORMAT_ARGB8888,0);
		SDL_FreeSurface(tmp);
		ft_putendl("Textures Loaded");
		return (1);
	}
	else
		ft_putendl("Error with Texture, please check files in ressources");
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
	// Creer la surface de travail
	sdl->img = SDL_CreateRGBSurfaceWithFormat(0, WINX, WINY, 32, SDL_PIXELFORMAT_ARGB32);
    if (sdl->img == NULL) {
        ft_error();
	}
	sdl->txt = NULL;
	if (! (init_texture(sdl)))
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
		if (!(ft_parser(fd, &sdl)))
			return (0);
		init_sdl(&sdl);
		init_variables(&sdl);
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
		exit8bit((&sdl)->txt);
		free_tpars(&sdl, sdl.pars.nb_lin);
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp

	return (0);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2020/03/02 09:54:26 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

// fonction pour initialiser les textures
// Penser a virer les printfs

int init_weapons (t_weapons *wp)
{
	// need secure and return
	wp->frame_nb = 0;
	wp->delay = 100;
	wp->shoot = false;
	wp->frame2= load_image("./ressources/pistol1.bmp");
	wp->frame[0] = load_image("./ressources/pistol1.bmp");
	wp->frame[1] = load_image("./ressources/pistol2.bmp");
	wp->frame[2] = load_image("./ressources/pistol3.bmp");
	wp->frame[3] = load_image("./ressources/pistol4.bmp");
	wp->frame[4] = load_image("./ressources/pistol5.bmp");
	printf("load gun text\n");
	return (1);
}
int init_texture (t_sdl *sdl)
{
	SDL_Surface *tmp;

	sdl->txt = load_image("./ressources/GreenWall0.bmp");
	sdl->txt2 = load_image("./ressources/Blue4.bmp");
	sdl->txt3 = load_image("./ressources/RedBricks0.bmp");
	sdl->txt4 = load_image("./ressources/WoodenWall0.bmp");
	sdl->icon = SDL_LoadBMP("./ressources/icon.bmp");
	if(!( sdl->weapons = (t_weapons *)malloc(sizeof(t_weapons))))
		return (0);

	init_weapons(sdl->weapons);
	if (sdl->txt)
	{
	/*	tmp = sdl->img;
		sdl->img = SDL_ConvertSurfaceFormat(sdl->img,SDL_PIXELFORMAT_ARGB8888,0);
		SDL_FreeSurface(tmp);*/
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
	/*sdl->img = SDL_CreateRGBSurfaceWithFormat(0, WINX, WINY, 32, SDL_PIXELFORMAT_ARGB32);
    if (sdl->img == NULL) {
        ft_error();
	}*/
	sdl->txt = NULL;
	if (! (init_texture(sdl)))
		ft_error();
	sdl->menu = true;
	SDL_SetWindowIcon(sdl->fenetre, sdl->icon);
	return (0);
}


int		main(int argc, char **argv)
{
	int fd;
	t_sdl *sdl;

	if (argc == 2)
	{
		if (!(sdl = (t_sdl *)malloc(sizeof(t_sdl))))
			return (0);
		ft_bzero(sdl, sizeof(t_sdl));
		fd = open(argv[1], O_RDONLY);
		if (!(ft_parser(fd, sdl)))
			return (0);
		init_sdl(sdl);

		if (TTF_Init() == -1)
			return (0);
		sdl->police = TTF_OpenFont("./ressources/bebasneue-regular.ttf", 50);

		init_variables(sdl);
		printf("end initialization\n");
		init_menu(sdl);
		ft_bzero((sdl)->key, SDL_NUM_SCANCODES);
		while (!(sdl->end))
		{
			sdl->counter++;
			event(sdl);
			fps_limit(sdl);
			draw(sdl);
		}
	//	SDL_FreeSurface((sdl)->img);
		printf("free screen\n");
		SDL_FreeSurface((sdl)->screen);
		printf("free fenetre\n");
		SDL_FreeSurface((sdl)->icon);
		SDL_DestroyWindow(sdl->fenetre);

		TTF_CloseFont(sdl->police);
		TTF_Quit();

		SDL_Quit();
		printf("free image\n");
		free_image (sdl);
		printf("free pars\n");
		free_tpars(sdl, sdl->pars.nb_lin);
		free(sdl->weapons);
		free(sdl);
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp

	return (0);

}

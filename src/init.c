/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:06:02 by grudler           #+#    #+#             */
/*   Updated: 2020/03/03 11:47:32 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

int init_weapons (t_weapons *wp)
{
	// need secure and return
	wp->frame_nb = 0;
	wp->delay = 100;
	wp->shoot = false;
	wp->frame[0] = load_image("./ressources/pistol1.bmp");
	wp->frame[1] = load_image("./ressources/pistol2.bmp");
	wp->frame[2] = load_image("./ressources/pistol3.bmp");
	wp->frame[3] = load_image("./ressources/pistol4.bmp");
	wp->frame[4] = load_image("./ressources/pistol5.bmp");
	ft_putendl("load gun text\n");
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
	if (sdl->txt) // need to improve
	{
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
	sdl->screen = SDL_GetWindowSurface(sdl->fenetre);
	printf("WINDOW Create\n");
	sdl->txt = NULL;
	if (! (init_texture(sdl)))
		ft_error();
	sdl->menu = true;
	SDL_SetWindowIcon(sdl->fenetre, sdl->icon);
	return (0);
}

void	init_variables(t_sdl *sdl)
{
	sdl->rcst.posx = sdl->pars.spawnx + 0.5; // postion x du joueur
	sdl->rcst.posy = sdl->pars.spawny + 0.5;
	sdl->rcst.dirX = 0; // direction du joueur (ou regarde le joueur)
	sdl->rcst.dirY = -1;
	sdl->rcst.planX = 0.66; // plan de la camera (ce quon affiche a lecran) Fov de 66 ici
	sdl->rcst.planY = 0;
	sdl->fps.lastTime = 0;
	sdl->fps.framelimit = 0;
	sdl->counter = 0;
}

void	init_raycast(t_sdl *sdl, int x)
{
	sdl->rcst.cameraX = 2 * x / (double)WINX - 1; // coordonnés x du plan de la camera que le current x de l'ecran represente
	sdl->rcst.raydirX = sdl->rcst.dirX + sdl->rcst.planX * sdl->rcst.cameraX; //direction des rayons
	sdl->rcst.raydirY = sdl->rcst.dirY + sdl->rcst.planY * sdl->rcst.cameraX;
	sdl->rcst.mapX = (int)sdl->rcst.posx; // coordonées du carré actuel ou se trouve le rayon
	sdl->rcst.mapY = (int)sdl->rcst.posy;
	sdl->rcst.deltadistX = fabs(1 / sdl->rcst.raydirX); // distance que le rayon doit traverser pour aller d'un x-side au prochain x ou y-side (calcul simplifié trouvé apres pythagore)
	sdl->rcst.deltadistY = fabs(1 / sdl->rcst.raydirY);
}

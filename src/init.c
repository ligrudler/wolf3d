/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:06:02 by grudler           #+#    #+#             */
/*   Updated: 2020/03/05 11:18:42 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
**                 #######################################
**                 ############## init weapons ##############
**                 #######################################
**
** Function to load wall textures : 
** success = return true | fail = return false 
** frame_nb = store the current frame number 
** delay = between 2 frame (millis)
** shoot = bool to get if a current animation is running 
*/

bool		init_weapons(t_weapons *wp)
{
	wp->frame_nb = 0;
	wp->delay = 100;
	wp->shoot = false;
	if (!(wp->frame[0] = load_image("./ressources/pistol1.bmp")) ||
		!(wp->frame[1] = load_image("./ressources/pistol2.bmp")) ||
		!(wp->frame[2] = load_image("./ressources/pistol3.bmp")) ||
		!(wp->frame[3] = load_image("./ressources/pistol4.bmp")) ||
		!(wp->frame[4] = load_image("./ressources/pistol5.bmp")))
	{
		ft_putendl("Error with Gun Text");
		return (0);
	}
	ft_putendl("Weapon_texture...[loaded]");
	return (1);
}

/*
**                 #######################################
**                 ############## init wall ##############
**                 #######################################
**
** Function to load wall textures : 
** success = return true | fail = return false 

*/

bool		init_wall(t_sdl *sdl)
{
	if (!(sdl->txt[0] = load_image("./ressources/GreenWall0.bmp")) ||
		!(sdl->txt[1] = load_image("./ressources/Blue4.bmp")) ||
		!(sdl->txt[2] = load_image("./ressources/RedBricks0.bmp")) ||
		!(sdl->txt[3] = load_image("./ressources/WoodenWall0.bmp")))
	{
		ft_putendl("Error with Gun Text");
		return (false);
	}
	ft_putendl("Wall_texture...[loaded]");
	return (true);
}

/*
**                 #######################################
**                 ############ init textures ############
**                 #######################################
**
** Function to load all images needed for the game : 
** success = return 1 | fail = return 0 
** 1) first all wall textures 
** 2) then the icon (dock icon)
** 3) after create the weapons structure to store all data 
** 4) load weapons textures 
** 
*/

int			init_texture(t_sdl *sdl)
{
	if (!(init_wall(sdl)))
		return (0);
	sdl->icon = SDL_LoadBMP("./ressources/icon.bmp");
	if (!(sdl->weapons = (t_weapons *)malloc(sizeof(t_weapons))))
		return (0);
	ft_bzero(sdl->weapons, sizeof(t_weapons));
	if (init_weapons(sdl->weapons))
	{
		ft_putendl("Textures...[Loaded]");
		return (1);
	}
	else
		ft_putendl("Error with Texture, please check files in ressources");
	return (0);
}

/*
**                 #######################################
**                 ############ init variables ###########
**                 #######################################
**
** call in the main, to set initial parameter of the raycasting
** posx,posy = coordinates of the player position
** dirx = x coordinate of the direction vector 
** diry = y coordinate of the direction vector
** To get a FOV of 66 degree, we need to have direction vector > camera plane
** lasttime = 
** framelimit = 
** police1 = Menu Font
** polie2 = FPS display Font
*/

void		init_variables(t_sdl *sdl)
{
	sdl->rcst.posx = sdl->pars.spawnx + 0.5;
	sdl->rcst.posy = sdl->pars.spawny + 0.5;
	sdl->rcst.dirx = 0;
	sdl->rcst.diry = -1;
	sdl->rcst.planx = 0.66;
	sdl->rcst.plany = 0;
	sdl->fps.lasttime = 0;
	sdl->fps.framelimit = 0;
	sdl->counter = 0;
	sdl->ttf.police1 = TTF_OpenFont("./ressources/bebasneue-regular.ttf", 50);
	sdl->ttf.police2 = TTF_OpenFont("./ressources/vogue.ttf", 50);
}

/*
**                 #######################################
**                 ############# init raycast ############
**                 #######################################
**
** Init all variables needed for raycasting, call in the beginning of each ray casting
** camerax = x coordinate on the camera plane  right side = [1] | center[0] |left [-1]
** raydirx = coordinate vector x of the ray 
** raydiry = coordinate vector y of the ray 
** mapx = coordinate x of the cell where i am
** mapy = coordinate y of the cell where i am
** deltadistx = the distance that the ray need to travel to reach the next x side
** deltadistx = the distance that the ray need to travel to reach the next x side
** to compute we using a simplification of pythagoras formula (much faster)
*/

void		init_raycast(t_sdl *sdl, int x)
{
	sdl->rcst.camerax = 2 * x / (double)WINX - 1;
	sdl->rcst.raydirx = sdl->rcst.dirx + sdl->rcst.planx * sdl->rcst.camerax;
	sdl->rcst.raydiry = sdl->rcst.diry + sdl->rcst.plany * sdl->rcst.camerax;
	sdl->rcst.mapx = (int)sdl->rcst.posx;
	sdl->rcst.mapy = (int)sdl->rcst.posy;
	sdl->rcst.deltadistx = fabs(1 / sdl->rcst.raydirx);
	sdl->rcst.deltadisty = fabs(1 / sdl->rcst.raydiry);
}

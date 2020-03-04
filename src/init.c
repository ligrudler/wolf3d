/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:06:02 by grudler           #+#    #+#             */
/*   Updated: 2020/03/04 19:25:33 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

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

bool		init_wall(t_sdl *sdl)
{
	if (!(sdl->txt[0] = load_image("./ressources/GreenWall0.bmp")) ||
		!(sdl->txt[1] = load_image("./ressources/Blue4.bmp")) ||
		!(sdl->txt[2] = load_image("./ressources/RedBricks0.bmp")) ||
		!(sdl->txt[3] = load_image("./ressources/WoodenWall0.bmp")))
	{
		ft_putendl("Error with Gun Text");
		return (0);
	}
	ft_putendl("Wall_texture...[loaded]");
	return (1);
}

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

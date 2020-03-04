/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:35:26 by grudler           #+#    #+#             */
/*   Updated: 2020/03/04 16:23:15 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	ray_direction_distance(t_sdl *sdl)
{
	if (sdl->rcst.raydirx < 0)
	{
		sdl->rcst.stepx = -1;
		sdl->rcst.sidedistx = (double)((sdl->rcst.posx - sdl->rcst.mapx)
			* sdl->rcst.deltadistx);
	}
	else
	{
		sdl->rcst.stepx = 1;
		sdl->rcst.sidedistx = (double)((sdl->rcst.mapx + 1 - sdl->rcst.posx)
			* sdl->rcst.deltadistx);
	}
	if (sdl->rcst.raydiry < 0)
	{
		sdl->rcst.stepy = -1;
		sdl->rcst.sidedisty = (double)((sdl->rcst.posy - sdl->rcst.mapy)
			* sdl->rcst.deltadisty);
	}
	else
	{
		sdl->rcst.stepy = 1;
		sdl->rcst.sidedisty = (double)((sdl->rcst.mapy + 1 - sdl->rcst.posy)
			* sdl->rcst.deltadisty);
	}
}

void	side_hit(t_sdl *sdl)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (sdl->rcst.sidedistx < sdl->rcst.sidedisty)
		{
			sdl->rcst.sidedistx += sdl->rcst.deltadistx;
			sdl->rcst.mapx += sdl->rcst.stepx;
			sdl->rcst.side = 0;
		}
		else
		{
			sdl->rcst.sidedisty += sdl->rcst.deltadisty;
			sdl->rcst.mapy += sdl->rcst.stepy;
			sdl->rcst.side = 1;
		}
		if (sdl->pars.map[sdl->rcst.mapy][sdl->rcst.mapx] == 2)
			hit = 1;
	}
}

void	ray_lenght(t_sdl *sdl)
{
	if (sdl->rcst.side == 0)
		sdl->rcst.raylenght = (sdl->rcst.mapx - sdl->rcst.posx
			+ (1 - sdl->rcst.stepx) / 2) / sdl->rcst.raydirx;
	else
		sdl->rcst.raylenght = (sdl->rcst.mapy - sdl->rcst.posy
			+ (1 - sdl->rcst.stepy) / 2) / sdl->rcst.raydiry;
}

void	find_line_height(t_sdl *sdl)
{
	sdl->rcst.lineheight = (int)(WINY / sdl->rcst.raylenght);
	sdl->rcst.lowpix = -sdl->rcst.lineheight / 2 + WINY / 2;
	if (sdl->rcst.lowpix < 0)
		sdl->rcst.lowpix = 0;
	sdl->rcst.highpix = sdl->rcst.lineheight / 2 + WINY / 2;
	if (sdl->rcst.highpix >= WINY)
		sdl->rcst.highpix = WINY - 1;
}

void	raycast(t_sdl *sdl)
{
	int			x;

	x = 0;
	while (x < WINX)
	{
		init_raycast(sdl, x);
		ray_direction_distance(sdl);
		side_hit(sdl);
		ray_lenght(sdl);
		find_line_height(sdl);
		draw_vertical_line(sdl, x);
		x++;
	}
}

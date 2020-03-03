/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:35:26 by grudler           #+#    #+#             */
/*   Updated: 2020/03/03 14:51:43 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	ray_direction_distance(t_sdl *sdl)
{
	if (sdl->rcst.raydirX < 0)
	{
		sdl->rcst.stepX = -1;
		sdl->rcst.sidedistX = (double)((sdl->rcst.posx - sdl->rcst.mapX)
			* sdl->rcst.deltadistX);
	}
	else
	{
		sdl->rcst.stepX = 1;
		sdl->rcst.sidedistX = (double)((sdl->rcst.mapX + 1 - sdl->rcst.posx)
			* sdl->rcst.deltadistX);
	}
	if (sdl->rcst.raydirY < 0)
	{
		sdl->rcst.stepY = -1;
		sdl->rcst.sidedistY = (double)((sdl->rcst.posy - sdl->rcst.mapY)
			* sdl->rcst.deltadistY);
	}
	else
	{
		sdl->rcst.stepY = 1;
		sdl->rcst.sidedistY = (double)((sdl->rcst.mapY + 1 - sdl->rcst.posy)
			* sdl->rcst.deltadistY);
	}
}

void	side_hit(t_sdl *sdl)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (sdl->rcst.sidedistX < sdl->rcst.sidedistY)
		{
			sdl->rcst.sidedistX += sdl->rcst.deltadistX;
			sdl->rcst.mapX += sdl->rcst.stepX;
			sdl->rcst.side = 0;
		}
		else
		{
			sdl->rcst.sidedistY += sdl->rcst.deltadistY;
			sdl->rcst.mapY += sdl->rcst.stepY;
			sdl->rcst.side = 1;
		}
		if (sdl->pars.map[sdl->rcst.mapY][sdl->rcst.mapX] == 2)
			hit = 1;
	}
}

void	ray_lenght(t_sdl *sdl)
{
	if (sdl->rcst.side == 0)
		sdl->rcst.raylenght = (sdl->rcst.mapX - sdl->rcst.posx
			+ (1 - sdl->rcst.stepX) / 2) / sdl->rcst.raydirX;
	else
		sdl->rcst.raylenght = (sdl->rcst.mapY - sdl->rcst.posy
			+ (1 - sdl->rcst.stepY) / 2) / sdl->rcst.raydirY;
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

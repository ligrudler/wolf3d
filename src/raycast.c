/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:35:26 by grudler           #+#    #+#             */
/*   Updated: 2020/03/05 16:26:18 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
**                 #######################################
**                 ####### ray_direction_distance ########
**                 #######################################
** DDA Digital Differential Analizer
** Initialize variables for DDA algorithm.
*/

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

/*
**                 #######################################
**                 ############## side_hit ###############
**                 #######################################
** DDA
** Check if a wall is hit by executing the DDA algorithm.
*/

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

/*
**                 #######################################
**                 ############# ray_lenght ##############
**                 #######################################
** Calculate ray's lenght from player positon until it hits a wall.
*/

void	ray_lenght(t_sdl *sdl)
{
	if (sdl->rcst.side == 0)
		sdl->rcst.raylenght = (sdl->rcst.mapx - sdl->rcst.posx
			+ (1 - sdl->rcst.stepx) / 2) / sdl->rcst.raydirx;
	else
		sdl->rcst.raylenght = (sdl->rcst.mapy - sdl->rcst.posy
			+ (1 - sdl->rcst.stepy) / 2) / sdl->rcst.raydiry;
}

/*
**                 #######################################
**                 ########## find_line_height ###########
**                 #######################################
** Compute wall's height and deduct the highest pixel
** and the lowest pixel of the line to display.
*/

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

/*
**                 #######################################
**                 ############### Raycast ###############
**                 #######################################
** The principe of raycasting is :
** Cast a ray for each horizontal pixel of the screen until he collide
** with a wall.
** Then get the distance and the side hit and compute the size of the wall
*/

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

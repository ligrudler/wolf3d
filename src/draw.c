/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:19:49 by lgrudler          #+#    #+#             */
/*   Updated: 2020/01/06 14:32:00 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"


void put_pixels(t_sdl* sdl, uint32_t color, int x, int y)
{
	uint32_t *pixels;

	pixels = (uint32_t *)sdl->img->pixels;
	if ((x > 0 && x < WINX) && (y > 0 && x < WINY))
	{
		pixels[x + WINY * y] = color;
 	}
}

void clear_screen(t_sdl *sdl)
{

	uint32_t *pixels;
	int i;
	int n;

	n = WINY * WINX;
	i = 0;
	pixels = (uint32_t *)sdl->img->pixels;
	while(i < n)
	{
		pixels[i] = 0;
		i++;
	 }
}

void update_screen(t_sdl* sdl)
{
	SDL_BlitSurface(sdl->img, NULL, sdl->screen, NULL);
	SDL_UpdateWindowSurface(sdl->fenetre);
}

void	draw_sky_ground(t_sdl *sdl)
{
	int i;
	int j;
	uint32_t color;

	j = 0;
	color = convert_argb(255, 135, 206, 255);
	while (j <= WINY /*/ 2*/)
	{
		i = 0;
		while (i < WINX)
		{
			put_pixels(sdl, color, i, j);
			i++;
		}
		j++;
	}
	j = WINY / 2;
	color = convert_argb(255, 211, 211, 211);
	while (j <= WINY)
	{
		i = 0;
		while (i < WINX)
		{
			put_pixels(sdl, color, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_sdl *sdl)
{
	clear_screen(sdl);
	draw_sky_ground(sdl);
	raycast(sdl);
	//draw_picture(sdl);
	update_screen(sdl);

}

void	draw_vertical_line(t_sdl *sdl, int x)
{
	int y;

	y = sdl->rcst.lowpix;
	while (y <= sdl->rcst.highpix)
	{
		put_pixels(sdl, sdl->rcst.color, x, y);
		y++;
	}
}

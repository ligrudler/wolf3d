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

void PutPixel32_nolock(SDL_Surface * surface, int x, int y, Uint32 color)
{
    Uint8 * pixel = (Uint8*)surface->pixels;
    pixel += (y * surface->pitch) + (x * sizeof(Uint32));
    *((Uint32*)pixel) = color;
}


void put_pixels(t_sdl* sdl, uint32_t color, int x, int y)
{
	//if( SDL_MUSTLOCK(sdl->img) )
      //  SDL_LockSurface(sdl->img);
    //PutPixel32_nolock(sdl->img, x, y, color);
    //if( SDL_MUSTLOCK(sdl->img) )
     //   SDL_UnlockSurface(sdl->img);
	
	uint32_t *pixels;

	pixels = (uint32_t *)sdl->img->pixels;
	if ((x > 0 && x < WINX) && (y > 0 && x < WINY))
	{
		pixels[x + WINY * y] = color;
 	}

}

uint32_t	convert_argb(unsigned int a, unsigned int r, unsigned int g,
	unsigned int b)
{
	unsigned int nb;

	if (a > 0xff)
		a = 0xff;
	if (r > 0xff)
		r = 0xff;
	if (g > 0xff)
		g = 0xff;
	if (b > 0xff)
		b = 0xff;
	//nb = ((a << 24) | (r << 16) | (g << 8) | (b));
	nb = ((b << 24) | (g << 16) | (r << 8) | (a));
	return (nb);
}

void update_screen(t_sdl* sdl)
{
/*
	int n;
	int i;
	Uint8 * pixel = (Uint8*)sdl->img->pixels;

	n = WINX * WINY;
	i = 0;

	while (i < n)
	{
		pixel[i] = 0;
		i++;
	}*/
	SDL_FillRect(sdl->screen, NULL, 0); // Need to recreate this function
	SDL_BlitSurface(sdl->img, NULL, sdl->screen, NULL);
	SDL_UpdateWindowSurface(sdl->fenetre);

	/*
	SDL_UpdateTexture(sdl->texture, NULL, sdl->img, WINX * sizeof(uint32_t));
	SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
	*/
}

void	draw(t_sdl *sdl)
{
	draw_sky_ground(sdl);
	raycast(sdl);
	//draw_picture(sdl);
	update_screen(sdl);

}

void	draw_sky_ground(t_sdl *sdl)
{
	int i;
	int j;
	uint32_t color;

	j = 0;
	//SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 255, 0);
	color = convert_argb(255, 135, 206, 255);
	while (j <= WINY /*/ 2*/)
	{
		i = 0;
		while (i < WINX)
		{
			//SDL_RenderDrawPoint(sdl->renderer, i, j);
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
			//SDL_RenderDrawPoint(sdl->renderer, i, j);
			put_pixels(sdl, color, i, j);
			i++;
		}
		j++;
	}
}

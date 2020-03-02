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

	pixels = (uint32_t *)sdl->screen->pixels;
	if ((x >= 0 && x < WINX) && (y >= 0 && x < WINY))
	{
		pixels[x + WINY * y] = color;
 	}
}

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    //int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;  // 4=bpp

    return *(Uint32 *)p;
}

void clear_screen(t_sdl *sdl)
{

	uint32_t *pixels;
	int i;
	int n;

	n = WINY * WINX;
	i = 0;
	pixels = (uint32_t *)sdl->screen->pixels;
	while(i < n)
	{
		pixels[i] = 0;
		i++;
	 }
}

void update_screen(t_sdl* sdl)
{
	SDL_UpdateWindowSurface(sdl->fenetre);
}

void	draw_sky_ground(t_sdl *sdl)
{
	int y;
	int x;
	uint32_t color;

	y = 0;
	color = convert_argb(255, 135, 206, 255);

	while (y <= ( (WINY - 1) / 2))
	{
		x = 0;
		while (x < WINX - 1)
		{
			put_pixels(sdl, color, x, y);
			x++;
			//printf("x :%d | y: %d\n",x,y);
		}
		y++;
	}

	y = ( (WINY - 1) / 2);
	color = convert_argb(255, 211, 211, 211);
	while (y <= (WINY - 1))
	{
		x = 0;
		while (x < (WINX - 1))
		{
			put_pixels(sdl, color, x, y);
			x++;
		}
		y++;
	}
}

void	draw(t_sdl *sdl)
{
	if (sdl->menu == false)
	{
		clear_screen(sdl);
		draw_sky_ground(sdl);
		raycast(sdl);
		draw_wepaon(sdl, sdl->weapons);
		fps_display(sdl);
	}
	else
		display_menu(sdl, sdl->menu_img);
	update_screen(sdl);
}

// Working really good

void	draw_vertical_line(t_sdl *sdl, int x)
{
	int y;
//	uint32_t *pixels;
	// test affichage texture
	double wallx;
	if (sdl->rcst.side == 0)
		wallx = sdl->rcst.posy + sdl->rcst.raylenght *  sdl->rcst.raydirY;
	else
		wallx = sdl->rcst.posx + sdl->rcst.raylenght *  sdl->rcst.raydirX;
	wallx -= floor(wallx);

	int texX = (int) (wallx * 64.0);

	texX = 64 - texX - 1;
/*
	if (sdl->rcst.side == 0 && sdl->rcst.raydirX > 0)
	{
		texX = 64 - texX - 1;
	}*/
	/*
	if (sdl->rcst.side == 1 && sdl->rcst.raydirX < 0)
	{
		texX = 64 - texX - 1;
	}*/
	double step = 1.0 * 64 / sdl->rcst.lineheight;
	double texPos = (sdl->rcst.lowpix - WINY / 2 + sdl->rcst.lineheight / 2) * step ;

	//pixels = (uint32_t *)sdl->surf->pixels;
	y = sdl->rcst.lowpix;
	while (y <= sdl->rcst.highpix)
	{
		int texY =(int)texPos & (64 - 1);
		texPos += step;
		if ((int)sdl->rcst.posx >= sdl->rcst.mapX && sdl->rcst.side == 0)
			sdl->rcst.color = sdl->txt->data[ 64 * texY + texX];
		else if (sdl->rcst.side == 0)
			sdl->rcst.color = sdl->txt2->data[ 64 * texY + texX];
		if ((int)sdl->rcst.posy <= sdl->rcst.mapY && sdl->rcst.side == 1)
			sdl->rcst.color = sdl->txt3->data[ 64 * texY + texX];
		else if (sdl->rcst.side == 1)
			sdl->rcst.color = sdl->txt4->data[ 64 * texY + texX];
		//sdl->rcst.color = sdl->txt->data[ 64 * texY + texX];
		put_pixels(sdl, sdl->rcst.color, x, y);
		y++;
	}
}

/*
void	draw_vertical_line(t_sdl *sdl, int x)
{
	int y;
	long scale;
	long index_frac;
	int text_index;
	uint32_t *pixels;

	index_frac = 0;
	text_index = 0;
	scale = (64 << 16) / sdl->rcst.lineheight ;
	y = sdl->rcst.lowpix;
	while (y <= sdl->rcst.highpix)
	{
		text_index += (index_frac >> 16);
		pixels = (uint32_t *)sdl->txt->data;
		//sdl->rcst.color = pixels[text_index];
		sdl->rcst.color = pixels[0];
	//	printf(" value first px : %d\n", sdl->txt->data[0]);
		put_pixels(sdl, sdl->rcst.color, x, y);
		index_frac += scale;      // advance index by scale-factor
  		index_frac &= 66535;      // mask out the whole part and just keep t

		y++;
	}
}
*/
/*
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
*/

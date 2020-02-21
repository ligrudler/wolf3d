/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:14:09 by qlouisia           #+#    #+#             */
/*   Updated: 2020/01/21 19:14:09 by qlouisia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../Includes/wolf3d.h"
// need to delete
/*
void draw_picture(t_sdl* sdl)
{
	SDL_Surface* image = SDL_LoadBMP("d:\\Dev\\health.bmp");
	if (image)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl->renderer, image);
		if (texture)
		{

			SDL_Rect dstrect = { 5, 5, 320, 240 };
			SDL_RenderCopy(sdl->renderer, texture, NULL, &dstrect);
			SDL_RenderPresent(sdl->renderer);
		}
		else
			printf("error text\n");
	}
	else
		printf("echec de chargement du sprite (%s)\n", SDL_GetError());
}
*/

void test_draw_image(t_sdl *sdl)
{
	int x;
	int y;
	uint32_t color;
	int i;
	int tmp;

	y = 0;
	i = 0;
	while (y < IMGH)
	{
		x = 0 ;
		while (x < IMGW)
		{
			
			color = sdl->txt->data[ y * IMGW + x];
			//color = convert_8bits_color(color);
			put_pixels(sdl, color, x + IMGW + 2 , y);
			i++;
			
			//printf(" %d = x:%d y:%d \n",i,x,y);
			x++;
		}
		y++;
	}
}
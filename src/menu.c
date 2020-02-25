/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:23:20 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/25 16:31:24 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void draw_wepaon(t_sdl *sdl, t_bmp *img)
{
	int x;
	int y;
	uint32_t color;
	uint32_t ref_col;
	int padding_x;
	int padding_y;

	y = 0;
	padding_x = (WINX / 2) - (img->width / 2);
	padding_y = WINY - img->height;
	ref_col = img->data[0];
	while (y < img->width)
	{
		x = 0 ;
		while (x < img->height)
		{
			color = img->data[ y * img->width + x];
			if (color != ref_col)
				put_pixels(sdl, color, x + padding_x , y + padding_y);
			x++;
		}
		y++;
	}
}


	void display_menu(t_sdl *sdl, t_bmp *img)
{
	int x;
	int y;
	int x_p;
	int y_p;
	uint32_t color;

	float scale_x;
	float scale_y;
	scale_x = ((float)img->width / WINX);
	scale_y = ((float)img->height / WINY);
	y = 0;
	while (y < WINY - 1)
	{
		x = 0 ;
		while (x < WINX - 1)
		{
			x_p = x * scale_x;
			y_p = y * scale_y;
			color = img->data[ y_p * img->width + x_p];
			//color = convert_8bits_color(color);
			put_pixels(sdl, color, x , y);
			
		//	printf(" x:%d y:%d | x_p %d y_p %d [%f][%f] \n",x,y,x_p, y_p, scale_x, scale_y);
			x++;
		}
		y++;
	}

}




int init_menu(t_sdl *sdl)
{
	if (!(sdl->menu_img = load_image("./ressources/wol.bmp")))
		return(0);

	// centrer l'image en fonction de la taille de la fenetre
	sdl->padding_x = (WINX - sdl->menu_img->width) / 2;
	sdl->padding_y = (WINY - sdl->menu_img->height) / 2;
	/*
	display_menu(sdl, sdl->menu_img);
	SDL_BlitSurface(sdl->img, NULL, sdl->screen, NULL);
	SDL_UpdateWindowSurface(sdl->fenetre);
	*/
	return (1);
	
}

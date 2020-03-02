/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:23:20 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/02 19:11:04 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void draw_wepaon(t_sdl *sdl, t_weapons *img)
{
	int x;
	int y;
	uint32_t color;
	uint32_t ref_col;
	int padding_x;
	int padding_y;
	static int last_time = 0;
	int current_time;

	y = 0;
	padding_x = (WINX / 2) - (img->frame[img->frame_nb]->width / 2);
	padding_y = WINY - img->frame[img->frame_nb]->height;
	ref_col = img->frame[img->frame_nb]->data[0];
	while (y < img->frame[img->frame_nb]->height)
	{
		x = 0 ;
		while (x < img->frame[img->frame_nb]->width)
		{
			color = img->frame[img->frame_nb]->data[ y *img->frame[img->frame_nb]->width + x];
			if (color != ref_col)
				put_pixels(sdl, color, x + padding_x , y + padding_y);
			x++;
		}
		y++;
	}
	if (img->shoot == true)
	{
		current_time = SDL_GetTicks();
		if (current_time > last_time + img->delay)
	{
		img->frame_nb++;
		if (img->frame_nb > 4)
		{
			img->frame_nb = 0;
			img->shoot = false;
		}
		last_time = current_time;
	}
	}
}

void	displat_menu_text(t_sdl *sdl)
{
	SDL_Surface *texte;
	SDL_Rect position;
	SDL_Color red = {255,0,0};

	sdl->police = TTF_OpenFont("./ressources/vogue.ttf", 50);
	texte = TTF_RenderText_Blended(sdl->police, "Press space !", red);

	position.x = WINX / 1.8;
	position.y = WINY / 1.3;
	SDL_BlitSurface(texte, NULL, sdl->screen, &position);
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
			put_pixels(sdl, color, x , y);
			x++;
		}
		y++;
	}
//	displat_menu_text(sdl);
}




int init_menu(t_sdl *sdl)
{
	if (!(sdl->menu_img = load_image("./ressources/wol.bmp")))
		return(0);

	// centrer l'image en fonction de la taille de la fenetre
	sdl->padding_x = (WINX - sdl->menu_img->width) / 2;
	sdl->padding_y = (WINY - sdl->menu_img->height) / 2;

	// refactoriser pour n'afficher l'image qu'une fois
	
	/*
	display_menu(sdl, sdl->menu_img);
	SDL_BlitSurface(sdl->img, NULL, sdl->screen, NULL);
	SDL_UpdateWindowSurface(sdl->fenetre);
	*/
	return (1);

}

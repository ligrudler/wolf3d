/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:23:20 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/05 12:52:44 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
**                 #######################################
**                 ############# frame_weapon ############
**                 #######################################
** Display the animation of the gunshot
** if shoot is true (a shot is occuring), check a timer and display the good
** frame
*/

void			frame_weapon(t_weapons *img)
{
	static int	last_time = 0;
	int			current_time;

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

/*
**                 #######################################
**                 ############# draw_weapon ############
**                 #######################################
** Compute where to draw the weapons with the window size.
*/

void			draw_wepaon(t_sdl *sdl, t_weapons *img)
{
	int			x;
	int			y;
	int			padding_x;
	int			padding_y;

	y = 0;
	padding_x = (WINX / 2) - (img->frame[img->frame_nb]->width / 2);
	padding_y = WINY - img->frame[img->frame_nb]->height;
	img->ref_col = img->frame[img->frame_nb]->data[0];
	while (y < img->frame[img->frame_nb]->height)
	{
		x = 0;
		while (x < img->frame[img->frame_nb]->width)
		{
			img->color = img->frame[img->frame_nb]->data[y
				* img->frame[img->frame_nb]->width + x];
			if (img->color != img->ref_col)
				put_pixels(sdl, img->color, x + padding_x, y + padding_y);
			x++;
		}
		y++;
	}
	frame_weapon(img);
}

/*
**                 #######################################
**                 ########## displat_menu_text ##########
**                 #######################################
** Display the text in menu
*/


void			displat_menu_text(t_sdl *sdl)
{
	SDL_Surface		*texte;
	SDL_Rect		position;
	const SDL_Color	red = {255, 0, 0, 0};

	texte = TTF_RenderText_Blended(sdl->ttf.police2, "Press space !", red);
	position.x = WINX / 1.8;
	position.y = WINY / 1.3;
	SDL_BlitSurface(texte, NULL, sdl->screen, &position);
	SDL_FreeSurface(texte);
}

/*
**                 #######################################
**                 ########## displat_menu_text ##########
**                 #######################################
** Display menu image and resize
*/

void			display_menu(t_sdl *sdl, t_bmp *img)
{
	sdl->men.scale_x = ((float)img->width / WINX);
	sdl->men.scale_y = ((float)img->height / WINY);
	sdl->men.y = 0;
	while (sdl->men.y < WINY - 1)
	{
		sdl->men.x = 0;
		while (sdl->men.x < WINX - 1)
		{
			sdl->men.x_p = sdl->men.x * sdl->men.scale_x;
			sdl->men.y_p = sdl->men.y * sdl->men.scale_y;
			sdl->men.color = img->data[sdl->men.y_p * img->width
				+ sdl->men.x_p];
			put_pixels(sdl, sdl->men.color, sdl->men.x, sdl->men.y);
			sdl->men.x++;
		}
		sdl->men.y++;
	}
	displat_menu_text(sdl);
}

/*
**                 #######################################
**                 ########## displat_menu_text ##########
**                 #######################################
** Load menu image and center it.
*/

int				init_menu(t_sdl *sdl)
{
	if (!(sdl->menu_img = load_image("./ressources/wol.bmp")))
		return (0);
	sdl->padding_x = (WINX - sdl->menu_img->width) / 2;
	sdl->padding_y = (WINY - sdl->menu_img->height) / 2;
	display_menu(sdl, sdl->menu_img);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:23:20 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/24 14:50:25 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
	void display_menu(t_sdl *sdl, t_bmp *img)
{
	int x;
	int y;
	uint32_t color;
	int i;
	int tmp;

	y = 0;
	i = 0;
//	printf("display menu\n");
	while (y < img->height)
	{
		x = 0 ;
		while (x < img->width)
		{
			
			color = img->data[ y * img->width + x];
			//color = convert_8bits_color(color);
			put_pixels(sdl, color, x + img->width, y);
			i++;
			
			//printf(" %d = x:%d y:%d \n",i,x,y);
			x++;
		}
		y++;
	}

}
*/

	void display_menu(t_sdl *sdl, t_bmp *img)
{
	int x;
	int y;
	uint32_t color;
	int i;
	int tmp;

	y = 0;
	i = 0;
	while (y < img->height)
	{
		x = 0 ;
		while (x < img->width)
		{
			
			color = img->data[ y *img->width + x];
			//color = convert_8bits_color(color);
			put_pixels(sdl, color, x /*+ IMGW + 2*/ , y);
			i++;
			
			//printf(" %d = x:%d y:%d \n",i,x,y);
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
	/*
	display_menu(sdl, sdl->menu_img);
	SDL_BlitSurface(sdl->img, NULL, sdl->screen, NULL);
	SDL_UpdateWindowSurface(sdl->fenetre);
	*/
	return (1);
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:12:37 by grudler           #+#    #+#             */
/*   Updated: 2020/02/01 16:40:51 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

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
	nb = ((a << 24) | (r << 16) | (g << 8) | (b));
	//nb = ((b << 24) | (g << 16) | (r << 8) | (a));
	return (nb);
}
/*
uint32_t scale_texture (t_sdl *sdl)
{
float scale_y;

scale_y = sdl->rcst.lineheight / 64; // diviser la hauteur du mur par la taille de la texture

}
*/
// Changement de couleur, en fonction de dirX  et si le rayon touche en y ou en x side. On check si la position du joueur est inferieure ou superieure au x (ou au y) du mur touché.
int		get_color(t_sdl *sdl)
{
	if ((int)sdl->rcst.posx < sdl->rcst.mapX && sdl->rcst.side == 0)
		return(convert_argb(255, 255, 100, 23)); // ouest
	else if (sdl->rcst.side == 0)
		return(convert_argb(255, 255, 0, 0)); // est 
	if ((int)sdl->rcst.posy > sdl->rcst.mapY && sdl->rcst.side == 1) // sud
		return(convert_argb(255, 0, 255, 0));
	return(convert_argb(255, 0, 0, 255)); // nord 
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:12:37 by grudler           #+#    #+#             */
/*   Updated: 2020/01/28 14:13:10 by grudler          ###   ########.fr       */
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
	//nb = ((a << 24) | (r << 16) | (g << 8) | (b));
	nb = ((b << 24) | (g << 16) | (r << 8) | (a));
	return (nb);
}

// Changement de couleur, en fonction de dirX  et si le rayon touche en y ou en x side. On check si la position du joueur est inferieure ou superieure au x (ou au y) du mur touché.
int		get_color(t_sdl *sdl)
{
	if (sdl->rcst.dirX > 0)
	{
		if ((int)sdl->rcst.posx >= sdl->rcst.mapX && sdl->rcst.side == 0)
			return(convert_argb(255, 0, 0, 0));
		else if (sdl->rcst.side == 0)
			return(convert_argb(255, 255, 255, 255));
		if ((int)sdl->rcst.posy <= sdl->rcst.mapY && sdl->rcst.side == 1)
			return(convert_argb(255, 0, 0, 255));
		else if (sdl->rcst.side == 1)
			return(convert_argb(255, 255, 0, 0));
	}
	if ((int)sdl->rcst.posx < sdl->rcst.mapX && sdl->rcst.side == 0)
		return(convert_argb(255, 255, 255, 255));
	else if (sdl->rcst.side == 0)
		return(convert_argb(255, 0, 0, 0));
	if ((int)sdl->rcst.posy > sdl->rcst.mapY && sdl->rcst.side == 1)
		return(convert_argb(255, 255, 0, 0));
	return(convert_argb(255, 0, 0, 255));
}

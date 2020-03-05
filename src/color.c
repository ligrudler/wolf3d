/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:12:37 by grudler           #+#    #+#             */
/*   Updated: 2020/03/05 11:21:58 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
**                 #######################################
**                 ############ convert argb ############
**                 #######################################
**
** Function to load all images needed for the game : 
** success = return 1 | fail = return 0 
** 1) first all wall textures 
** 2) then the icon (dock icon)
** 3) after create the weapons structure to store all data 
** 4) load weapons textures 
** 
*/


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
	return (nb);
}

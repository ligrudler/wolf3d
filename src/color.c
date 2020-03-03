/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:12:37 by grudler           #+#    #+#             */
/*   Updated: 2020/03/02 20:14:00 by lgrudler         ###   ########.fr       */
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
	return (nb);
}

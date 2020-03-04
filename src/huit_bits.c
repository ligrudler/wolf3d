/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huit_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:33:21 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/04 16:12:56 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bmp.h"
#include <stdlib.h>

uint32_t	convert_8bitscolor(char r, char g, char b)
{
	int nb;
	int value;

	value = ((255 & 0xFF) << 24) | //alpha
			(((int)r & 0xFF) << 16) | //red
			(((int)g & 0xFF) << 8) | //green
			(((int)b & 0xFF) << 0); //blue
	return (value);
}

void		format_data8bit(char *tmp, t_bmp *bmp)
{
	int				x;
	int				y;
	int				i;
	unsigned char	index;

	i = 0;
	y = bmp->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < bmp->width)
		{
			index = tmp[y * bmp->width + x];
			bmp->data[i] = bmp->palette[index];
			x++;
			i++;
		}
		y--;
	}
}
/* Color Format in raw data : R B G 0  */

int			create_palette(char *tmp, t_bmp *bmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp += bmp->header_size + 14;
	if (bmp->nb_color_palette == 0)
		bmp->nb_color_palette = 256;
	if (!(bmp->palette = (uint32_t *)malloc(sizeof(uint32_t) * bmp->nb_color_palette)))
		return (0);
	while (i < bmp->nb_color_palette * 4)
	{
		bmp->palette[j] = convert_8bitscolor(tmp[i + 2], tmp[i + 1], tmp[i]);
		i += 4;
		j++;
	}
	return (1);
}

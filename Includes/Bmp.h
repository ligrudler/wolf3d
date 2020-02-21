/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:57:19 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/20 15:52:38 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER_H
# define BMP_PARSER_H
#include <stdint.h>

# define IMGW 64
# define IMGH 64
# define BUFFSIZE 54 + 256 * 4

typedef struct	s_bmpfiles
{
	int size;
	int width;
	int height;
	int bpp;
	int BPP;
	int px_data_offset;
	int header_size;
	int nb_color_palette;
	int compression;
	int image_size;
	int important_color_nb;
	uint32_t *palette;
	uint32_t *data;
}				t_bmp;

int create_palette(char *tmp, t_bmp *bmp);
void format_data8bit(char *tmp, t_bmp *bmp);
int exit8bit(t_bmp *bmp);
#endif
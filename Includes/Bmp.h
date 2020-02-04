/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:57:19 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/04 16:53:50 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER_H
# define BMP_PARSER_H
#include <stdint.h>

typedef struct	s_bmpfiles
{
	int size;
	int width;
	int height;
	int bpp;
	uint32_t *data;
}				t_bmp;

#endif

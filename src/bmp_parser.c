/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:51:37 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/05 11:38:51 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"
#include "../Includes/bmp.h"
#include <fcntl.h>

/*
**                 #######################################
**                 ############# error in bmp ############
**                 #######################################
**
** Function to free, if a error occure when loading a BMP
*/

void		*error_in_bmp(t_bmp *img, char *tmp_data)
{
	if (tmp_data)
		free(tmp_data);
	exit8bit(img);
	return (NULL);
}

/*
**                 #######################################
**                 ############ get header info ##########
**                 #######################################
**
** In the header, we get alls informations :
** width / height of the image
** bpp = bits per pixels (how is store pixels informations)
** data offset = where in the files, beginning data
** nb_color_palette = how many color in the palette
** header_size = size of the files header
** image_size =  size of the images (in bits)
** compression = Method of compression used (not supported)
** bypp = bytes per pixels
** size = size of the images
*/

void		get_header_info(t_bmp *ret, char *buff)
{
	ret->width = *(uint32_t*)(buff + 18);
	ret->height = *(uint32_t*)(buff + 22);
	ret->bpp = *(int*)(buff + 28);
	ret->px_data_offset = *(int*)(buff + 10);
	ret->nb_color_palette = *(int*)(buff + 46);
	ret->important_color_nb = *(int*)(buff + 50);
	ret->header_size = *(int*)(buff + 14);
	ret->image_size = *(int*)(buff + 34);
	ret->compression = *(int*)(buff + 30);
	ret->bypp = ret->bpp / 8;
	ret->size = ret->width * ret->height * ret->bypp;
}

/*
**                 #######################################
**                 ############### create img ############
**                 #######################################
**
** call after read files informations ;
** return NULL if a problem occure, return a non NULL pointer if success
** 1) Create palette
** 2) Copy pixels data
** 3) format pixels data (color in argb and reorganise to pixel[0] : upper left)
*/

void		*create_img(t_bmp *ret, int fd, char *buff)
{
	char	*tmp_data;

	if (ret->bpp <= 8)
		if (!(create_palette(buff, ret)))
			return (error_in_bmp(ret, NULL));
	if (!(tmp_data = (char *)malloc(sizeof(char) * ret->size)))
		return (error_in_bmp(ret, NULL));
	ft_bzero(tmp_data, sizeof(tmp_data));
	if (!(ret->data = (uint32_t *)malloc(sizeof(uint32_t) * ret->size)))
		return (error_in_bmp(ret, tmp_data));
	ft_bzero(ret->data, sizeof(uint32_t) * ret->size);
	if ((read(fd, tmp_data, ret->size)) < -1)
		return (error_in_bmp(ret, tmp_data));
	if (ret->bpp <= 8)
		format_data8bit(tmp_data, ret);
	free(tmp_data);
	return (ret);
}

/*
**                 #######################################
**                 ############### load img ############
**                 #######################################
**
** call to load a BMP files into a t_bmp struct
** return (NULL) if error | return a pointer to the struct if success
** support only 8 bits color
*/

t_bmp		*load_image(char *path)
{
	int		fd;
	char	buff[BUFFSIZE];
	t_bmp	*ret;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl(" Error in files");
		return (NULL);
	}
	if (!(ret = (t_bmp *)malloc(sizeof(t_bmp))))
		return (NULL);
	ft_bzero(ret, sizeof(t_bmp));
	ft_bzero(buff, sizeof(char) * BUFFSIZE);
	if ((read(fd, buff, BUFFSIZE) < -1))
		return (error_in_bmp(ret, NULL));
	if (buff[0] != 'B' && buff[1] != 'M')
		return (error_in_bmp(ret, NULL));
	get_header_info(ret, buff);
	if (!create_img(ret, fd, buff))
		return (NULL);
	close(fd);
	return (ret);
}

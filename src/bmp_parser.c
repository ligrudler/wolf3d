/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:51:37 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/04 19:32:19 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"
#include "../Includes/bmp.h"
#include <fcntl.h>

void		*error_in_bmp(t_bmp *img, char *tmp_data)
{
	if (tmp_data)
		free(tmp_data);
	exit8bit(img);
	return (NULL);
}

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

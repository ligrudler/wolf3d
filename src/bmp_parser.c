/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:51:37 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/02 18:47:41 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"
#include "../Includes/Bmp.h"
#include <fcntl.h>
#include <stdlib.h>

t_bmp *load_image (char *path)
{
	int fd;
	char buff[BUFFSIZE];
	char *tmp_data;
	t_bmp *ret;
	int i;
	char tmp;


	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl(" Error in files");
		return (NULL);
	}
	// Create struct

	if (!(ret = (t_bmp *)malloc(sizeof(t_bmp))))
		return (NULL);

	//read Header and get informations
	ft_bzero(buff,sizeof(char) * BUFFSIZE);
	read(fd,buff,BUFFSIZE); // need protection
	if (buff[0] != 'B' && buff[1] != 'M')
		return(NULL);
	ret->width = *(uint32_t*)(buff + 18);
	ret->height = *(uint32_t*)(buff + 22);
	ret->bpp = *(int*)(buff + 28);
	ret->px_data_offset = *(int*)(buff + 10);
	ret->nb_color_palette = *(int*)(buff + 46);
	ret->important_color_nb = *(int*)(buff + 50);
	ret->header_size = *(int*)(buff + 14);
	ret->image_size = *(int*)(buff + 34);
	ret->compression = *(int*)(buff + 30);
	ret->BPP = ret->bpp / 8;
	ret->size = ret->width * ret->height * ret->BPP;

	// get palette color;
	if (ret->bpp <= 8)
		create_palette(buff, ret);

	
	// Get Data from image
	if (!(tmp_data = (char *)malloc(sizeof(char) * ret->size)))
		return (NULL);
	if (!(ret->data = (uint32_t *)malloc(sizeof(uint32_t) * ret->size)))
		return (NULL);
	ft_bzero(tmp_data,sizeof(char) * ret->size);
	ft_bzero(ret->data,sizeof(uint32_t) * ret->size);
	int retu ;
	retu = read(fd,tmp_data,ret->size ); // need protection
	if (ret->bpp <= 8)
		format_data8bit(tmp_data, ret);
	free(tmp_data);
	close(fd);
	return (ret);
}


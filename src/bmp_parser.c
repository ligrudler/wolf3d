/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:51:37 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/26 14:16:58 by qlouisia         ###   ########.fr       */
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


	printf("\n### CUSTOM READ ###\n\n");
	printf("%s\n",path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl(" Error in files");
		return (NULL);
	}
	// Create struct

	if (!(ret = (t_bmp *)malloc(sizeof(t_bmp))))
		return (NULL);
	printf("file open\n");

	//read Header and get informations 
	ft_bzero(buff,sizeof(char) * BUFFSIZE);	
	read(fd,buff,BUFFSIZE); // need protection
	printf("check files : %c%c \n",buff[0],buff[1]);
	if (buff[0] != 'B' && buff[1] != 'M')
		return(NULL);
	ret->width = *(uint32_t*)(buff + 18);
	/*ret->width  = ((buff[18]>> 8) | (buff[19]<<8));//(int)buff[18];*/
	ret->height = *(uint32_t*)(buff + 22);//(int)buff[22];
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

	//ret->size = 3 * ret->width * ret->height;
	printf(" w : %d h : %d | bpp : %d | BPP : %d |offset : %d \n",ret->width ,ret->height, ret->bpp, ret->BPP, ret->px_data_offset);
	printf(" Color in palette : %d  | important color : %d | Header Size : %d | compression : %d  | image size : %d \n",ret->nb_color_palette, ret->important_color_nb, ret->header_size, ret->compression, ret->image_size);
	// Get Data from image
	if (!(tmp_data = (char *)malloc(sizeof(char) * ret->size)))
		return (NULL);
	if (!(ret->data = (uint32_t *)malloc(sizeof(uint32_t) * ret->size)))
		return (NULL);
	ft_bzero(tmp_data,sizeof(char) * ret->size);
	ft_bzero(ret->data,sizeof(uint32_t) * ret->size);
	int retu ;
	retu = read(fd,tmp_data,ret->size ); // need protection
	


	printf("Size : %d | return from files : %d \n", ret->size, retu );
	if (ret->bpp <= 8)
		format_data8bit(tmp_data, ret);
	
	printf(" value first px : %d\n", ret->data[0]);
	
	
	
	//ret->width = *(int*)&buff[18];
	//ret->height = *(int*)&buff[22];
	//printf(" w : %d | h %d \n", ret->width, ret->height);

	
	// copy data 

	// close file
	printf("\n### CUSTOM READ END ###\n\n");
	free(tmp_data);
	close(fd);
	return (ret); 	
}


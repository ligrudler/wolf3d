/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:51:37 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/04 16:53:41 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"
#include "../Includes/Bmp.h"
#include <fcntl.h>


t_bmp *load_image (char *path)
{
	int fd;
	char buff[54];
	t_bmp ret;
	int w;
	int h; 

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl(" Error in files");
		return (NULL);
	}
	printf("file open\n");
	//read Header and get informations 
	read(fd,buff,54); // need protection 
	w = *(int*)&buff[18];
	h = *(int*)&buff[22];
	ret.bpp = *(int*)&buff[28];
	printf(" w : %d h : %d | bpp : %d\n", w,h, ret.bpp);

	ret.width = w;
	ret.height = h;
	//printf(" w : %d | h %d \n", ret.width, ret.height);
	//ret->width = *(int*)&buff[18];
	//ret->height = *(int*)&buff[22];
	//printf(" w : %d | h %d \n", ret->width, ret->height);

	
	// copy data 

	// close file
	return (&ret); 	
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitBMP.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:49:29 by qlouisia          #+#    #+#             */
/*   Updated: 2020/02/20 15:47:35 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bmp.h"
#include <stdlib.h>

int exit8bit(t_bmp *bmp)
{
	if (bmp->palette != NULL)
		free (bmp->palette);
	if (bmp->palette != NULL)
		free (bmp->data);
	free(bmp);
	return (1);
}
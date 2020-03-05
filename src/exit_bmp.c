/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:49:29 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/05 11:39:50 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bmp.h"
#include <stdlib.h>

/*
**                 #######################################
**                 ############### exit8bit ##############
**                 #######################################
**
** Function to free all information on a t_bmp struct
*/

int		exit8bit(t_bmp *bmp)
{
	if (bmp)
	{
		if (bmp->palette != NULL)
			free(bmp->palette);
		if (bmp->data != NULL)
			free(bmp->data);
		free(bmp);
	}
	return (1);
}

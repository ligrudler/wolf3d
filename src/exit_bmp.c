/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:49:29 by qlouisia          #+#    #+#             */
/*   Updated: 2020/03/02 20:27:15 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bmp.h"
#include <stdlib.h>

int		exit8bit(t_bmp *bmp)
{
	if (bmp->palette != NULL)
		free(bmp->palette);
	if (bmp->data != NULL)
		free(bmp->data);
	free(bmp);
	return (1);
}

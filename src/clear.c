/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:13:31 by lgrudler          #+#    #+#             */
/*   Updated: 2020/03/03 15:13:51 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	clear_screen(t_sdl *sdl)
{
	uint32_t	*pixels;
	int			i;
	int			n;

	n = WINY * WINX;
	i = 0;
	pixels = (uint32_t *)sdl->screen->pixels;
	while (i < n)
	{
		pixels[i] = 0;
		i++;
	}
}

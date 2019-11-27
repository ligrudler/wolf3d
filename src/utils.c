/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:19:49 by lgrudler          #+#    #+#             */
/*   Updated: 2019/11/27 17:50:09 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	init_bres(t_sdl *sdl)
{
	sdl->line.err = 0;
	sdl->line.dx = ft_abs(sdl->line.p2.x - sdl->line.p1.x);
	sdl->line.sx = sdl->line.p1.x < sdl->line.p2.x ? 1 : -1;
	sdl->line.dy = ft_abs(sdl->line.p2.y - sdl->line.p1.y);
	sdl->line.sy = sdl->line.p1.y < sdl->line.p2.y ? 1 : -1;
}

int	ft_drawline(t_sdl *sdl)
{
	init_bres(sdl);
	if (sdl->line.dx > sdl->line.dy)
		sdl->line.err = sdl->line.dx / 2;
	else if (sdl->line.dx < sdl->line.dy)
		sdl->line.err = -(sdl->line.dy) / 2;
	while (1)
	{
		SDL_RenderDrawPoint(sdl->renderer, sdl->line.p1.x, sdl->line.p1.y);
		if (sdl->line.p1.x == sdl->line.p2.x
			&& sdl->line.p1.y == sdl->line.p2.y)
			return (0);
		sdl->line.e2 = sdl->line.err;
		if (sdl->line.e2 > -(sdl->line.dx))
		{
			sdl->line.err -= sdl->line.dy;
			sdl->line.p1.x += sdl->line.sx;
		}
		if (sdl->line.e2 < sdl->line.dy)
		{
			sdl->line.err += sdl->line.dx;
			sdl->line.p1.y += sdl->line.sy;
		}
	}

}

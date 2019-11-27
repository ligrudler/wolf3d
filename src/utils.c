/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:19:49 by lgrudler          #+#    #+#             */
/*   Updated: 2019/11/27 20:50:59 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"
#include <stdio.h>

void	init_bres(t_line *bre, t_pt *p1, t_pt *p2)
{
	bre->err = 0;
	bre->dx = ft_abs(p2->x - p1->x);
	bre->sx = p1->x < p2->x ? 1 : -1;
	bre->dy = ft_abs(p2->y - p1->y);
	bre->sy = p1->y < p2->y ? 1 : -1;
}

int	ft_drawline(t_pt s1, t_pt s2, t_sdl *sdl)
{
	t_line bre;

	init_bres( &bre, &s1, &s2);
	if (bre.dx > bre.dy)
		bre.err = bre.dx / 2;
	else if (bre.dx < bre.dy)
		bre.err = -(bre.dy) / 2;
	while (1)
	{
		SDL_RenderDrawPoint(sdl->renderer, s1.x, s1.y);
		if (s1.x == s2.x && s1.y == s2.y)
		{
			printf("[%d,%d]\n",s1.x,s1.y);
			return (0);
		}
		bre.e2 = bre.err;
		if (bre.e2 > -(bre.dx))
		{
			bre.err -= bre.dy;
			s1.x += bre.sx;
		}
		if (bre.e2 < bre.dy)
		{
			bre.err += bre.dx;
			s1.y += bre.sy;
		}
	}
}


/*
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
*/

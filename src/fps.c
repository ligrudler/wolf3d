/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:01:43 by grudler           #+#    #+#             */
/*   Updated: 2020/03/02 20:27:38 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

int		fps_limit_delay(t_sdl *sdl)
{
	int		getticks;
	int		max;

	getticks = SDL_GetTicks();
	if (sdl->fps.framelimit > getticks)
		SDL_Delay(sdl->fps.framelimit - getticks);
	return (0);
}

void	fps_counter(t_sdl *sdl)
{
	unsigned int getticks;

	getticks = SDL_GetTicks();
	sdl->fps.currentTime = getticks - sdl->fps.lastTime;
	if (sdl->fps.currentTime != 0)
		sdl->fps.currentFPS = 1000 / (sdl->fps.currentTime);
	sdl->fps.lastTime = getticks;
}

void	fps_limit(t_sdl *sdl)
{
	fps_limit_delay(sdl);
	sdl->fps.framelimit = SDL_GetTicks() + (1000 / MAX_FPS);
	fps_counter(sdl);
}

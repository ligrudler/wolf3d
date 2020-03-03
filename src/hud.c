/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:48:56 by grudler           #+#    #+#             */
/*   Updated: 2020/03/02 20:41:25 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	fps_display(t_sdl *sdl)
{
	SDL_Surface		*texte;
	SDL_Rect		position;
	const SDL_Color	font_color = {255, 255, 0};

	sdl->police = TTF_OpenFont("./ressources/bebasneue-regular.ttf", 50);
	if (sdl->counter % 10 == 0)
	{
		sdl->str = ft_itoa(sdl->fps.currentFPS);
		sdl->counter = 0;
	}
	texte = TTF_RenderText_Blended(sdl->police, sdl->str, font_color);
	position.x = 10;
	position.y = 10;
	SDL_BlitSurface(texte, NULL, sdl->screen, &position);
	free(sdl->str);
	//SDL_FreeSurface(texte);
	sdl->str = NULL;
}

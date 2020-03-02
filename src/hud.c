/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:48:56 by grudler           #+#    #+#             */
/*   Updated: 2020/03/02 10:05:28 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	fps_display(t_sdl *sdl)
{
	SDL_Surface *texte;
	SDL_Rect position;
	SDL_Color noir = {255,255,0};

	sdl->police = TTF_OpenFont("./ressources/bebasneue-regular.ttf", 50);
	if (sdl->counter % 10 == 0)
	{
		sdl->str = ft_itoa(sdl->fps.currentFPS);
		sdl->counter = 0;
	}

	texte = TTF_RenderText_Blended(sdl->police, sdl->str, noir);

	position.x = 10;
	position.y = 10;
	SDL_BlitSurface(texte, NULL, sdl->screen, &position);
}

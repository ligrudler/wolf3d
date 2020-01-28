/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:35:26 by grudler           #+#    #+#             */
/*   Updated: 2020/01/28 14:44:15 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

// Fonction pour regarder dans quelle direction part le rayon et calculer la distance que le rayon met avant de toucher un 1er side
void	ray_direction_distance(t_sdl *sdl)
{
	if (sdl->rcst.raydirX < 0)
	{
		sdl->rcst.stepX = -1; // direction du rayon , de -1 à 1 en fonction si le sideDist est plutot a gauche ou a droite
		sdl->rcst.sidedistX = (double)((sdl->rcst.posx - sdl->rcst.mapX) * sdl->rcst.deltadistX); // distance que le rayon doit traverser pour aller de sa position de base a son tout premier x-side ou y-side
	}
	else
	{
		sdl->rcst.stepX = 1;
		sdl->rcst.sidedistX = (double)((sdl->rcst.mapX + 1 - sdl->rcst.posx) * sdl->rcst.deltadistX);
	}
	if (sdl->rcst.raydirY < 0)
	{
		sdl->rcst.stepY = -1;
		sdl->rcst.sidedistY = (double)((sdl->rcst.posy - sdl->rcst.mapY) * sdl->rcst.deltadistY);
	}
	else
	{
		sdl->rcst.stepY = 1;
		sdl->rcst.sidedistY = (double)((sdl->rcst.mapY + 1 - sdl->rcst.posy) * sdl->rcst.deltadistY);
	}

}
//focntion permettant de regarder si les sides coincident avec un mur ou pas et si cest le mur est toucheé en x ou en y side, la boucle s'arrete si un mur est toucheé
void	side_hit(t_sdl *sdl)
{
	int	hit;

	hit = 0; // check si un mur est touché
	while(hit == 0)
	{
		if (sdl->rcst.sidedistX < sdl->rcst.sidedistY)
		{
			sdl->rcst.sidedistX += sdl->rcst.deltadistX;
			sdl->rcst.mapX += sdl->rcst.stepX;
			sdl->rcst.side = 0;
		}
		else
		{
			sdl->rcst.sidedistY += sdl->rcst.deltadistY;
			sdl->rcst.mapY += sdl->rcst.stepY;
			sdl->rcst.side = 1;
		}
		if (sdl->pars.map[sdl->rcst.mapY][sdl->rcst.mapX] > 0)
			hit = 1;
	}
}

// Calcul de la longueur total du rayon
void	ray_lenght(t_sdl *sdl)
{
	if (sdl->rcst.side == 0)
		sdl->rcst.raylenght = (sdl->rcst.mapX - sdl->rcst.posx + (1 - sdl->rcst.stepX) / 2) / sdl->rcst.raydirX;
	else
		sdl->rcst.raylenght = (sdl->rcst.mapY - sdl->rcst.posy + (1 - sdl->rcst.stepY) / 2) / sdl->rcst.raydirY;

}
// Calcul de la hauteur attendu de la droite verticale pour le x courrant et caclul des 2 pixels aux extremités.
void	find_line_height(t_sdl *sdl)
{
	sdl->rcst.lineheight = (int)(WINY / sdl->rcst.raylenght);
	sdl->rcst.lowpix = -sdl->rcst.lineheight / 2 + WINY / 2;
	if (sdl->rcst.lowpix < 0)
		sdl->rcst.lowpix = 0;
	sdl->rcst.highpix = sdl->rcst.lineheight / 2 + WINY / 2;
	if (sdl->rcst.highpix >= WINY)
		sdl->rcst.highpix = WINY - 1;
}

void	raycast(t_sdl *sdl)
{
	int			x;

	x = 0;
	// boucle ou on parcourt tous les x de l'ecran pour savoir pour chaque x, quelle est la hauteur de la droite verticale a dessiner et ou elle se situe
	while (x < WINX)
	{
		init_raycast(sdl, x);
		ray_direction_distance(sdl);
		side_hit(sdl);
		ray_lenght(sdl);
		find_line_height(sdl);
		sdl->rcst.color = get_color(sdl);
		draw_vertical_line(sdl, x);
		x++;
	}
}

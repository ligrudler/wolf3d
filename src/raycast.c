/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:35:26 by grudler           #+#    #+#             */
/*   Updated: 2020/01/28 13:07:53 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	init_raycast(t_sdl *sdl)
{
	sdl->rcst.posx = 10; // postion x du joueur
	sdl->rcst.posy = 13;
	sdl->rcst.dirX = 0; // direction du joueur (ou regarde le joueur)
	sdl->rcst.dirY = -1;
	sdl->rcst.planX = 0.66; // plan de la camera (ce quon affiche a lecran) Fov de 66 ici
	sdl->rcst.planY = 0;

	sdl->fps.lastTime = 0;
	sdl->fps.framelimit = 0;
}

void	raycast(t_sdl *sdl)
{
	int			x;

	x = 0;

// boucle ou on parcourt tous les x de l'ecran pour savoir pour chaque x, quelle est la hauteur de la droite verticale a dessiner et ou elle se situe
	while (x < WINX)
	{
		sdl->rcst.cameraX = 2 * x / (double)WINX - 1; // coordonnés x du plan de la camera que le current x de l'ecran represente
		sdl->rcst.raydirX = sdl->rcst.dirX + sdl->rcst.planX * sdl->rcst.cameraX; //direction des rayons
		sdl->rcst.raydirY = sdl->rcst.dirY + sdl->rcst.planY * sdl->rcst.cameraX;

		sdl->rcst.mapX = (int)sdl->rcst.posx; // coordonées du carré actuel ou se trouve le rayon
		sdl->rcst.mapY = (int)sdl->rcst.posy; // ICEIII

		sdl->rcst.deltadistX = fabs(1 / sdl->rcst.raydirX); // distance que le rayon doit traverser pour aller d'un x-side au prochain x ou y-side (calcul simplifié trouvé apres pythagore)
		sdl->rcst.deltadistY = fabs(1 / sdl->rcst.raydirY);

// Fonction pour regarder dans quelle direction part le rayon et calculer la distance que le rayon met avant de toucher un 1er side
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

//focntion permettant de regarder si les sides coincident avec un mur ou pas et si cest le mur est toucheé en x ou en y side, la boucle s'arrete si un mur est toucheé
		sdl->rcst.hit = 0; // check si un mur est touché
		while(sdl->rcst.hit == 0)
		{
			if (sdl->rcst.sidedistX < sdl->rcst.sidedistY)
			{
				sdl->rcst.sidedistX += sdl->rcst.deltadistX;
				sdl->rcst.mapX += sdl->rcst.stepX;
				sdl->rcst.side = 0; // check si le mur a ete toucheé en y ou en x-side
			}
			else
			{
				sdl->rcst.sidedistY += sdl->rcst.deltadistY;
				sdl->rcst.mapY += sdl->rcst.stepY;
				sdl->rcst.side = 1;
			}
			if (sdl->pars.map[sdl->rcst.mapY][sdl->rcst.mapX] > 0)
				sdl->rcst.hit = 1;
		}

// Calcul de la longueur total du rayon
		if (sdl->rcst.side == 0)
			sdl->rcst.raylenght = (sdl->rcst.mapX - sdl->rcst.posx + (1 - sdl->rcst.stepX) / 2) / sdl->rcst.raydirX;
		else
			sdl->rcst.raylenght = (sdl->rcst.mapY - sdl->rcst.posy + (1 - sdl->rcst.stepY) / 2) / sdl->rcst.raydirY;

// Calcul de la hauteur attendu de la droite verticale pour le x courrant
		sdl->rcst.lineheight = (int)(WINY / sdl->rcst.raylenght);

// caclul le pixel du haut et le pixel du bas de la droite verticale
		sdl->rcst.lowpix = -sdl->rcst.lineheight / 2 + WINY / 2;
		if (sdl->rcst.lowpix < 0)
			sdl->rcst.lowpix = 0;
		sdl->rcst.highpix = sdl->rcst.lineheight / 2 + WINY / 2;
		if (sdl->rcst.highpix >= WINY)
			sdl->rcst.highpix = WINY - 1;

// Changement de couleur si le rayon touche en x ou en y side

	if (sdl->rcst.dirX > 0)
	{
		if ((int)sdl->rcst.posx >= sdl->rcst.mapX && sdl->rcst.side == 0)
			sdl->rcst.color = convert_argb(255, 0, 0, 0);
		else if (sdl->rcst.side == 0)
			sdl->rcst.color = convert_argb(255, 255, 255, 255);
		if ((int)sdl->rcst.posy <= sdl->rcst.mapY && sdl->rcst.side == 1)
			sdl->rcst.color = convert_argb(255, 0, 0, 255);
		else if (sdl->rcst.side == 1)
			sdl->rcst.color = convert_argb(255, 255, 0, 0);
	}
	else
	{
		if ((int)sdl->rcst.posx < sdl->rcst.mapX && sdl->rcst.side == 0)
			sdl->rcst.color = convert_argb(255, 255, 255, 255);
		else if (sdl->rcst.side == 0)
			sdl->rcst.color = convert_argb(255, 0, 0, 0);
		if ((int)sdl->rcst.posy > sdl->rcst.mapY && sdl->rcst.side == 1)
			sdl->rcst.color = convert_argb(255, 255, 0, 0);
		else if (sdl->rcst.side == 1)
			sdl->rcst.color = convert_argb(255, 0, 0, 255);
	}
// Dessine la droite verticale
		int y;

		y = sdl->rcst.lowpix;
		while (y <= sdl->rcst.highpix)
		{
			put_pixels(sdl, sdl->rcst.color, x, y);
			y++;
		}
		x++;
	}

}

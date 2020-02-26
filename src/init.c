/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:06:02 by grudler           #+#    #+#             */
/*   Updated: 2020/02/26 19:12:58 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	init_variables(t_sdl *sdl)
{
	sdl->rcst.posx = sdl->pars.spawnx + 0.5; // postion x du joueur
	sdl->rcst.posy = sdl->pars.spawny + 0.5;
	sdl->rcst.dirX = 0; // direction du joueur (ou regarde le joueur)
	sdl->rcst.dirY = -1;
	sdl->rcst.planX = 0.66; // plan de la camera (ce quon affiche a lecran) Fov de 66 ici
	sdl->rcst.planY = 0;

	sdl->fps.lastTime = 0;
	sdl->fps.framelimit = 0;
}

void	init_raycast(t_sdl *sdl, int x)
{
	sdl->rcst.cameraX = 2 * x / (double)WINX - 1; // coordonnés x du plan de la camera que le current x de l'ecran represente
	sdl->rcst.raydirX = sdl->rcst.dirX + sdl->rcst.planX * sdl->rcst.cameraX; //direction des rayons
	sdl->rcst.raydirY = sdl->rcst.dirY + sdl->rcst.planY * sdl->rcst.cameraX;

	sdl->rcst.mapX = (int)sdl->rcst.posx; // coordonées du carré actuel ou se trouve le rayon
	sdl->rcst.mapY = (int)sdl->rcst.posy;

	sdl->rcst.deltadistX = fabs(1 / sdl->rcst.raydirX); // distance que le rayon doit traverser pour aller d'un x-side au prochain x ou y-side (calcul simplifié trouvé apres pythagore)
	sdl->rcst.deltadistY = fabs(1 / sdl->rcst.raydirY);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:52:16 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/27 20:52:05 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void set_point(t_pt *point, double x, double y)
{
    point->x = x;
    point->y = y;
}

void draw_rect(t_sdl *sdl, t_pt *p1, t_pt *p2)
{
    t_pt tmp;

    set_point(&tmp, p2->x, p1->y);
    while(p1->y < p2->y)
    {
        ft_drawline(*p1, tmp, sdl);
        p1->y++;
        tmp.y++;
    }
}
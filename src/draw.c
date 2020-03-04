/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:19:49 by lgrudler          #+#    #+#             */
/*   Updated: 2020/03/04 16:23:15 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void	put_pixels(t_sdl *sdl, uint32_t color, int x, int y)
{
	uint32_t	*pixels;

	pixels = (uint32_t *)sdl->screen->pixels;
	if ((x >= 0 && x < WINX) && (y >= 0 && x < WINY))
		pixels[x + WINY * y] = color;
}

void	draw_sky_ground(t_sdl *sdl)
{
	int			y;
	int			x;
	uint32_t	color;

	y = -1;
	color = convert_argb(255, 135, 206, 255);
	while (++y <= ((WINY - 1) / 2))
	{
		x = -1;
		while (++x < WINX - 1)
			put_pixels(sdl, color, x, y);
	}
	y = ((WINY - 1) / 2);
	color = convert_argb(255, 211, 211, 211);
	while (y <= (WINY - 1))
	{
		x = 0;
		while (x < (WINX - 1))
		{
			put_pixels(sdl, color, x, y);
			x++;
		}
		y++;
	}
}

void	draw(t_sdl *sdl)
{
	if (sdl->menu == false)
	{
		clear_screen(sdl);
		draw_sky_ground(sdl);
		raycast(sdl);
		draw_wepaon(sdl, sdl->weapons);
		fps_display(sdl);
	}
	else
		display_menu(sdl, sdl->menu_img);
	SDL_UpdateWindowSurface(sdl->fenetre);
}

void	draw_faces(t_sdl *sdl, int tex_x, double step, int x)
{
	int		y;
	int		tex_y;
	double	texpos;

	texpos = (sdl->rcst.lowpix - WINY / 2 + sdl->rcst.lineheight / 2) * step;
	y = sdl->rcst.lowpix;
	while (y <= sdl->rcst.highpix)
	{
		tex_y = (int)texpos & (64 - 1);
		texpos += step;
		if ((int)sdl->rcst.posx >= sdl->rcst.mapx && sdl->rcst.side == 0)
			sdl->rcst.color = sdl->txt[0]->data[64 * tex_y + tex_x];
		else if (sdl->rcst.side == 0)
			sdl->rcst.color = sdl->txt[1]->data[64 * tex_y + tex_x];
		if ((int)sdl->rcst.posy <= sdl->rcst.mapy && sdl->rcst.side == 1)
			sdl->rcst.color = sdl->txt[2]->data[64 * tex_y + tex_x];
		else if (sdl->rcst.side == 1)
			sdl->rcst.color = sdl->txt[3]->data[64 * tex_y + tex_x];
		put_pixels(sdl, sdl->rcst.color, x, y);
		y++;
	}
}

void	draw_vertical_line(t_sdl *sdl, int x)
{
	double	wallx;
	double	step;
	int		tex_x;

	if (sdl->rcst.side == 0)
		wallx = sdl->rcst.posy + sdl->rcst.raylenght * sdl->rcst.raydiry;
	else
		wallx = sdl->rcst.posx + sdl->rcst.raylenght * sdl->rcst.raydirx;
	wallx -= floor(wallx);
	tex_x = (int)(wallx * 64.0);
	tex_x = 64 - tex_x - 1;
	step = 1.0 * 64 / sdl->rcst.lineheight;
	draw_faces(sdl, tex_x, step, x);
}

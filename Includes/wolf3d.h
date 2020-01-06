/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:43:42 by grudler           #+#    #+#             */
/*   Updated: 2020/01/06 13:13:33 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h> // pour printf
# include "../lib/SDL2-2.0.10/include/SDL.h"

# define BUFF_SIZE 10
# define WINX 800
# define WINY 800
# define MOVE 0.1
# define MOVEDIR 0.05

typedef struct	s_raycast
{
	double	posx;
	double	posy;
	double	dirX;
	double	dirY;
	double	planX;
	double	planY;

	double	time;
	double	oldtime;

	double	cameraX;
	double	raydirX;
	double	raydirY;

	int	mapX;
	int	mapY;
	double	sidedistX;
	double	sidedistY;
	double	deltadistX;
	double	deltadistY;
	double	raylenght;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;

	int		lineheight;
	int		lowpix;
	int		highpix;
}				t_raycast;

typedef struct	s_pt
{
	int x;
	int y;
}				t_pt;

typedef struct	s_line
{
	t_pt	p1;
	t_pt	p2;
	int		err;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e2;
}				t_line;

typedef struct	s_pars
{
	int **map;
	int x_map;
	int y_map;
	int	nb_col;
	int	nb_lin;
}		t_pars;

typedef struct	s_sdl
{
	SDL_Window *fenetre;
	SDL_Event evenements;
	SDL_Renderer *renderer;
	SDL_Point    point[WINX/2];
	char		key[SDL_NUM_SCANCODES];
	int			end;
	Uint32		type;
	SDL_Scancode scancode;
	t_pars		pars;
	t_raycast	rcst;
}				t_sdl;

int		ft_parser(int fd, t_sdl *sdl);
int 	free_tpars(t_sdl *map, int size);
int	ft_drawline(t_pt s1, t_pt s2, t_sdl *sdl);
void	init_bres(t_line *bre, t_pt *p1, t_pt *p2);
void	draw(t_sdl *sdl);
int init_sdl(t_sdl *sdl);
void	event(t_sdl *sdl);
void draw_rect(t_sdl *sdl, t_pt *p1, t_pt *p2);
void set_point(t_pt *point, double x, double y);
void	raycast(t_sdl *sdl);
void	init_raycast(t_sdl *sdl);

#endif

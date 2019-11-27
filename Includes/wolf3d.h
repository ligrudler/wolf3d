/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:43:42 by grudler           #+#    #+#             */
/*   Updated: 2019/11/27 17:39:07 by lgrudler         ###   ########.fr       */
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
	t_line		line;
}				t_sdl;

int		ft_parser(int fd, t_pars *pars);
int 	free_tpars(t_pars *map, int size);
int	ft_drawline(t_sdl *sdl);
void	init_bres(t_sdl *sdl);
void	draw(t_sdl *sdl);
int init_sdl(t_sdl *sdl);
void	event(t_sdl *sdl);
#endif

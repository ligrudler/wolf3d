/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:43:42 by grudler           #+#    #+#             */
/*   Updated: 2020/03/02 10:24:19 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include "../Includes/Bmp.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <stdio.h> // pour printf
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

# define BUFF_SIZE 10
# define WINX 800
# define WINY 800
# define HITBOX 0.3
# define MOVEDIR 0.05
# define MAX_FPS 60
# define ARGB 372645892 // equivalent de SDL_PIXELFORMAT_ARGB8888

typedef struct	s_fps
{
	unsigned int lastTime;
	unsigned int currentTime;
	double		currentFPS;
	unsigned int	framelimit;
}				t_fps;

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
	int		side;

	int		lineheight;
	int		lowpix;
	int		highpix;
	uint32_t color;
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
	double			spawnx;
	double			spawny;
}		t_pars;

typedef struct s_weapons
{
	t_bmp *frame[5];
	t_bmp *frame2;
	int		delay;
	int		frame_nb;
	bool	shoot;

}				t_weapons;

typedef struct	s_sdl
{
	TTF_Font *police;
	int		counter;
	char	*str;

	SDL_Window *fenetre;
	SDL_Event evenements;
	SDL_Point    point[WINX/2];
	char		key[SDL_NUM_SCANCODES];
	int			end;
	bool		menu;
	double			move;
//	Uint32 *img;
	Uint32		type;
	SDL_Scancode scancode;
	t_pars		pars;
	t_raycast	rcst;
//	SDL_Surface *surf;
//	SDL_Surface *img;
	SDL_Surface *screen; // Surface affichant l'ecran
	t_bmp *txt;
	t_bmp *txt2;
	t_bmp *txt3;
	t_bmp *txt4;
	t_bmp *menu_img;
	int padding_x;
	int padding_y;
	SDL_Surface *icon;
	t_weapons 	*weapons;
	t_fps fps;
}				t_sdl;

int		ft_parser(int fd, t_sdl *sdl);
int 	free_tpars(t_sdl *map, int size);
int		ft_drawline(t_pt s1, t_pt s2, t_sdl *sdl);
void	init_bres(t_line *bre, t_pt *p1, t_pt *p2);
void	draw(t_sdl *sdl);
int 	init_sdl(t_sdl *sdl);
void	event(t_sdl *sdl);
void 	draw_rect(t_sdl *sdl, t_pt *p1, t_pt *p2);
void	set_point(t_pt *point, double x, double y);
void	raycast(t_sdl *sdl);
void	init_variables(t_sdl *sdl);
void	draw(t_sdl *sdl);
void	draw_sky_ground(t_sdl *sdl);
void	fps_counter(t_sdl *sdl);
void	fps_limit(t_sdl *sdl);
int		fps_limit_delay(t_sdl *sdl);
void 	put_pixels(t_sdl* sdl, uint32_t color, int x, int y);
uint32_t	convert_argb(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
int		get_color(t_sdl *sdl);
void	draw_vertical_line(t_sdl *sdl, int x);
void	init_raycast(t_sdl *sdl, int x);

t_bmp *load_image (char *path);
int init_menu(t_sdl *sdl);
void display_menu(t_sdl *sdl, t_bmp *img);
int free_image (t_sdl *sdl);
void draw_wepaon(t_sdl *sdl, t_weapons *img);
void	fps_display(t_sdl *sdl);


#endif

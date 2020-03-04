/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:43:42 by grudler           #+#    #+#             */
/*   Updated: 2020/03/04 19:30:00 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../Includes/bmp.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "SDL.h"
# include "SDL_ttf.h"

# define BUFF_SIZE 4 //10
# define WINX 1000
# define WINY 1000
# define HITBOX 0.3
# define MOVEDIR 0.05
# define MAX_FPS 130
# define CHECKCODE "W3D\n"

typedef struct			s_fps
{
	unsigned int		lasttime;
	unsigned int		currentime;
	double				currentfps;
	unsigned int		framelimit;
}						t_fps;

typedef struct			s_raycast
{
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planx;
	double				plany;

	double				camerax;
	double				raydirx;
	double				raydiry;

	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				raylenght;
	int					stepx;
	int					stepy;
	int					side;

	int					lineheight;
	int					lowpix;
	int					highpix;
	uint32_t			color;
}						t_raycast;

typedef struct			s_pars
{
	int					**map;
	int					x_map;
	int					y_map;
	int					nb_col;
	int					nb_lin;
	int					verif;
	double				spawnx;
	double				spawny;
}						t_pars;

typedef struct			s_weapons
{
	t_bmp				*frame[5];
	int					delay;
	int					frame_nb;
	bool				shoot;
}						t_weapons;

typedef struct			s_ttf
{
	TTF_Font			*police1;
	TTF_Font			*police2;
	char				*str;
	char				*tmp;
}						t_ttf;

typedef struct			s_sdl
{
	char				*str;
	char				*tmp;
	int					counter;
	SDL_Window			*fenetre;
	SDL_Event			evenements;
	SDL_Point			point[WINX / 2];
	char				key[SDL_NUM_SCANCODES];
	int					end;
	bool				menu;
	double				move;
	Uint32				type;
	t_pars				pars;
	t_raycast			rcst;
	t_ttf				ttf;
	SDL_Surface			*screen;
	t_bmp				*txt[4];
	t_bmp				*menu_img;
	int					padding_x;
	int					padding_y;
	SDL_Surface			*icon;
	t_weapons			*weapons;
	t_fps				fps;
}						t_sdl;

/*
**	bmp_parser.c
*/

t_bmp					*load_image(char *path);

/*
**	check_map.c
*/

int						check_column_line(char *str, t_sdl *sdl, int i);
int						check_close_map(t_sdl *check);
int						check_plus(t_sdl *check, int line, int column);

/*
**	clear.c
*/

void					clear_screen(t_sdl *sdl);

/*
**	color.c
*/

uint32_t				convert_argb(unsigned int a, unsigned int r,
	unsigned int g, unsigned int b);

/*
**	draw.c
*/

void					put_pixels(t_sdl *sdl, uint32_t color, int x, int y);
void					draw_vertical_line(t_sdl *sdl, int x);
void					draw_faces(t_sdl *sdl, int tex_x, double step, int x);
void					draw(t_sdl *sdl);
void					draw_sky_ground(t_sdl *sdl);

/*
**	exit_bmp.c
*/

int						exit8bit(t_bmp *bmp);

/*
**	exit.c
*/

int						free_tpars(t_sdl *map, int size);
void					free_image(t_sdl *sdl);
void					free_weapons(t_weapons *wp);

/*
**	fps.c
*/

int						fps_limit_delay(t_sdl *sdl);
void					fps_counter(t_sdl *sdl);
void					fps_limit(t_sdl *sdl);

/*
**	ft_parser.c
*/

int						ft_parser(int fd, t_sdl *sdl);
int						create_map(char *str, t_sdl *sdl);
void					stock_in_map(char *str, t_sdl *sdl);
int						file_valid_name(char *file, char *ref);

/*
**	hud.c
*/

void					fps_display(t_sdl *sdl);

/*
**	huit_bits.c
*/

uint32_t				convert_8bitscolor(char r, char g, char b);
void					format_data8bit(char *tmp, t_bmp *bmp);
int						create_palette(char *tmp, t_bmp *bmp);

/*
**	init.c
*/

bool					init_weapons (t_weapons *wp);
bool					init_wall (t_sdl *sdl);
int						init_texture (t_sdl *sdl);
int						init_sdl(t_sdl *sdl);
void					init_variables(t_sdl *sdl);
void					init_raycast(t_sdl *sdl, int x);

/*
**	key_event.c
*/

void					event(t_sdl *sdl);
void					vertical_deplacement(t_sdl *sdl);
void					horizontal_deplacement(t_sdl *sdl);

/*
**	main.c
*/

int						main(int argc, char **argv);

/*
**	menu.c
*/

int						init_menu(t_sdl *sdl);
void					display_menu(t_sdl *sdl, t_bmp *img);
void					displat_menu_text(t_sdl *sdl);
void					draw_wepaon(t_sdl *sdl, t_weapons *img);

/*
**	raycast.c
*/

void					raycast(t_sdl *sdl);
void					find_line_height(t_sdl *sdl);
void					ray_lenght(t_sdl *sdl);
void					side_hit(t_sdl *sdl);
void					ray_direction_distance(t_sdl *sdl);

#endif

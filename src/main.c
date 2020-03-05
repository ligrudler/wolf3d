/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2020/03/05 12:46:14 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

/*
**                 #######################################
**                 ############### init_sdl ##############
**                 #######################################
** Initialize all graphics :
** 1) Create the windows
** 2) Load all textures
** 3) Load icons
*/

int		init_sdl(t_sdl *sdl)
{
	if ((SDL_Init(SDL_INIT_VIDEO) < 0) || (!(sdl->fenetre =
		SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_SHOWN))) ||
		!(sdl->screen = SDL_GetWindowSurface(sdl->fenetre)))
	{
		ft_putendl("Error Unable to initialize SDL");
		return (0);
	}
	ft_putendl("Window...[Created]");
	if (!(init_texture(sdl)))
		return (0);
	sdl->menu = true;
	if (sdl->icon)
		SDL_SetWindowIcon(sdl->fenetre, sdl->icon);
	return (1);
}

/*
**                 #######################################
**                 ############## event_loop #############
**                 #######################################
** Main event loop,
** sdl->counter : is for fps display (display 1 frames / 10)
** event to get inputs
** fps_limit to limit the tearing of the image
** draw is all display function
*/

void	event_loop(t_sdl *sdl)
{
	sdl->counter++;
	event(sdl);
	fps_limit(sdl);
	draw(sdl);
}

/*
**                 #######################################
**                 ############# exit_program ############
**                 #######################################
** Free all allocations and exit properly the programm
*/

int		exit_programm(t_sdl *sdl)
{
	ft_putendl("Screen...[free]");
	if (sdl->screen)
		SDL_FreeSurface((sdl)->screen);
	ft_putendl("Window...[free]");
	if (sdl->icon)
		SDL_FreeSurface((sdl)->icon);
	if (sdl->fenetre)
		SDL_DestroyWindow(sdl->fenetre);
	if (sdl->str)
		free(sdl->str);
	TTF_CloseFont(sdl->ttf.police1);
	TTF_CloseFont(sdl->ttf.police2);
	TTF_Quit();
	SDL_Quit();
	ft_putendl("Images...[free]");
	free_image(sdl);
	ft_putendl("Maps...[free]");
	free_tpars(sdl, sdl->pars.nb_lin);
	free(sdl->weapons);
	free(sdl);
	return (0);
}

/*
**                 #######################################
**                 ################# main ################
**                 #######################################
** 						Main function of wolf3d
*/

int		main(int argc, char **argv)
{
	int		fd;
	t_sdl	*sdl;

	if (argc == 2 && file_valid_name(argv[1], ".w3d"))
	{
		if (!(sdl = (t_sdl *)malloc(sizeof(t_sdl))))
			return (0);
		ft_bzero(sdl, sizeof(t_sdl));
		fd = open(argv[1], O_RDONLY);
		if (!(ft_parser(fd, sdl)) || !(init_sdl(sdl)) || ((TTF_Init() == -1)))
			return (exit_programm(sdl));
		init_variables(sdl);
		init_menu(sdl);
		ft_bzero((sdl)->key, SDL_NUM_SCANCODES);
		while (!(sdl->end))
			event_loop(sdl);
		exit_programm(sdl);
		return (0);
	}
	ft_putendl("Error main argv");
	return (0);
}

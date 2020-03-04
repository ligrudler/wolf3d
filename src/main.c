/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2020/03/04 18:57:52 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

// fonction pour initialiser les textures

int exit_programm(t_sdl *sdl)
{
		ft_putendl("screen...[free]");
		if (sdl->screen)
			SDL_FreeSurface((sdl)->screen);
		ft_putendl("window...[free]");
		if (sdl->icon)
			SDL_FreeSurface((sdl)->icon);
		if (sdl->fenetre)
			SDL_DestroyWindow(sdl->fenetre);
		TTF_CloseFont(sdl->ttf.police1);
		TTF_CloseFont(sdl->ttf.police2);
		TTF_Quit();
		SDL_Quit();
		ft_putendl("images...[free]");
		free_image (sdl);
		ft_putendl("map...[free]");
		free_tpars(sdl, sdl->pars.nb_lin);
		free(sdl->weapons);
		free(sdl);
	//	while (1);
		return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	t_sdl *sdl;

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
		{
			sdl->counter++;
			event(sdl);
			fps_limit(sdl);
			draw(sdl);
		}
		exit_programm(sdl);
	//	while(1);
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2020/03/03 15:42:34 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

// fonction pour initialiser les textures
// Penser a virer les printfs

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
		if (!(ft_parser(fd, sdl)))
			return (0);
		init_sdl(sdl);
		if (TTF_Init() == -1)
			return (0);
		init_variables(sdl);
		printf("end initialization\n");
		init_menu(sdl);
		ft_bzero((sdl)->key, SDL_NUM_SCANCODES);
		while (!(sdl->end))
		{
			sdl->counter++;
			event(sdl);
			fps_limit(sdl);
			draw(sdl);
		}
		ft_putendl("free screen\n");
		SDL_FreeSurface((sdl)->screen);
		ft_putendl("free fenetre\n");
		SDL_FreeSurface((sdl)->icon);
		SDL_DestroyWindow(sdl->fenetre);

		TTF_CloseFont(sdl->police);
		TTF_Quit();

		SDL_Quit();
		ft_putendl("free image\n");
		free_image (sdl);
		ft_putendl("free pars\n");
		free_tpars(sdl, sdl->pars.nb_lin);
		free(sdl->weapons);
		free(sdl);
		return (0);
	}

	ft_putstr("ERROR, MAIN ARGV"); //temp

	return (0);

}

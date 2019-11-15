/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2019/11/15 18:07:28 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	
	#include "Includes/wolf3d.h"
	#include "/Volumes/Storage/goinfre/qlouisia/wolf/lib/SDL2-2.0.10/include/SDL.h"

int beautifull_window(){
		SDL_Window *fenetre;
	   SDL_Event evenements;
	   int terminer = 0 ;
	   SDL_Renderer *renderer;
	   SDL_Point    point[800];
	   int i;
	   i = 0;
	   
	   // Initialisation de la SDL
	   
	   if(SDL_Init(SDL_INIT_VIDEO) < 0)
	   {
		   SDL_Quit();	
		   return (-1);
	   }
	   
	   
	   // Création de la fenêtre

	   fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	   if(fenetre == 0)
	   {
		   SDL_Quit();

		   return -1;
	   }
	   
	   if (!(renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_SOFTWARE)))
	  ft_error();
   SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
   while (i < 800)
   {
	  point[i].x = i;
	  point[i].y = 400;
	  i++;
   }
   SDL_RenderDrawPoints(renderer, point, 800);
  SDL_RenderPresent(renderer);
	   // On quitte la SDL
	   // Boucle principale
	   
	   while(!terminer)
	   {
	   SDL_WaitEvent(&evenements);
		   
	   if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
		   terminer = 1;
	   }
	   

	   
	   SDL_DestroyWindow(fenetre);
	   SDL_Quit();
	   return (0);
	}


int		main(int argc, char **argv)
{
	int fd;
	t_pars pars;
	int i = 0;
	int j = 0;
	beautifull_window();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_parser(fd, &pars);
		while (j < pars.nb_lin) // Test parsing
		{
			i = 0;
			while (i < pars.nb_col)
			{
				printf("%d", pars.map[j][i]);
				i++;
			}
			printf("%c", '\n');
			j++;
		}
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp
	
	    return 0;
	}

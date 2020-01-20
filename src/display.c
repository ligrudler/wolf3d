
#include "../Includes/wolf3d.h"
// need to delete
void draw_picture(t_sdl* sdl)
{
	SDL_Surface* image = SDL_LoadBMP("d:\\Dev\\health.bmp");
	if (image)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl->renderer, image);
		if (texture)
		{
			
			SDL_Rect dstrect = { 5, 5, 320, 240 };
			SDL_RenderCopy(sdl->renderer, texture, NULL, &dstrect);
			SDL_RenderPresent(sdl->renderer);
		}
		else
			printf("error text\n");
	}
	else
		printf("echec de chargement du sprite (%s)\n", SDL_GetError());
}
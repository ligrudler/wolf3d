#ifndef BMP_PARSER_H
# define BMP_PARSER_H
#include <stdint.h>

# define PATH "./ressources/wol.bmp"
# define BUFFSIZE 54 + 256 * 4

typedef struct	s_bmpfiles
{
	int size;
	uint16_t width;
	uint16_t height;
	int bpp;
	int BPP;
	int px_data_offset;
	int header_size;
	int nb_color_palette;
	int compression;
	int image_size;
	int important_color_nb;
	uint32_t *palette;
	uint32_t *data;
}				t_bmp;

int create_palette(char *tmp, t_bmp *bmp);
void format_data8bit(char *tmp, t_bmp *bmp);
int exit8bit(t_bmp *bmp);
#endif
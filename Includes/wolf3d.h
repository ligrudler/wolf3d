/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:43:42 by grudler           #+#    #+#             */
/*   Updated: 2019/11/15 12:26:32 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h> // pour printf
# include "SDL2/SDL.h"

# define BUFF_SIZE 10
# define WINX 800
# define WINY 800


typedef struct	s_pars
{
	int **map;
	int x_map;
	int y_map;
	int	nb_col;
	int	nb_lin;
}		t_pars;

int		ft_parser(int fd, t_pars *pars);

#endif

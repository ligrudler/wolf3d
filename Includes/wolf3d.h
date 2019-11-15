/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:43:42 by grudler           #+#    #+#             */
/*   Updated: 2019/11/15 11:43:51 by lgrudler         ###   ########.fr       */
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


typedef struct	s_mlx
{
	int **map;
	int x_map;
	int y_map;
	int	nb_col;
	int	nb_lin;
}		t_mlx;

int		ft_parser(int fd, t_mlx *mlx);

#endif

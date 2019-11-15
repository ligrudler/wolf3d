/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2019/11/15 11:36:04 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/wolf3d.h"

int		main(int argc, char **argv)
{
	int fd;
	t_mlx mlx;
	int i = 0;
	int j = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_parser(fd, &mlx);
		while (j < mlx.nb_lin) // Test parsing
		{
			i = 0;
			while (i < mlx.nb_col)
			{
				printf("%d", mlx.map[j][i]);
				i++;
			}
			printf("%c", '\n');
			j++;
		}
		return (0);
	}
	ft_putstr("ERROR, MAIN ARGV"); //temp
	return (0);
}

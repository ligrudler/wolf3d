/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:51:44 by grudler           #+#    #+#             */
/*   Updated: 2019/11/15 12:26:27 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/wolf3d.h"

int		init_window()

int		main(int argc, char **argv)
{
	int fd;
	t_pars pars;
	int i = 0;
	int j = 0;

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
	return (0);
}

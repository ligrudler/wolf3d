/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:01:22 by grudler           #+#    #+#             */
/*   Updated: 2019/11/15 12:26:27 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/wolf3d.h"

int		check_column_line(char *str, t_pars *pars)
{
	int i;
	int tmp;
	int check; // permet de gerer si la map finie par pls \n

	i = -1;
	tmp = 0;
	pars->nb_col = 0;
	pars->nb_lin = 0;
	while (str[++i])
	{
		tmp = pars->nb_col;
		pars->nb_col = 0;
		while (str[i] && str[i] != '\n')
		{
			if (ft_isdigit(str[i]))
			{
				pars->nb_col++;
				check = 1;
			}
			i++;
		}
		if (check == 1 && tmp != 0 && tmp != pars->nb_col) // pour l'instant ne gere que les map avec le meme nombre de colonne
			return (0);
		else if (check == 1)
		{
			pars->nb_lin++;
			check = 0;
		}
		else if (check == 0)
			pars->nb_col = tmp;
	}
	return (1);
}

void	stock_in_map(char *str, t_pars *pars)
{
	int i;

	pars->x_map = 0; // jai fais dans le sens x en abcisse donc nb colonne et y en ordonnee dc nb ligne
	pars->y_map = 0;
	i = 0;

	while (pars->y_map < pars->nb_lin && str[i])
	{
		pars->x_map = 0;
		while (pars->x_map < pars->nb_col && str[i])
		{
			if (ft_isdigit(str[i]))
			{
				pars->map[pars->y_map][pars->x_map] = ft_atoi(&str[i]);
				pars->x_map++;
			}
			i++;
		}
		pars->y_map++;
		i++;
	}
}

int		create_map(char *str, t_pars *pars) // il faudrait penser a bien tout free (str ex) dans les retour erreur de malloc
{
	int i;

	i = 0;
	if (check_column_line(str, pars) == 0)
	{
		ft_putstr("ERROR NB COLONNE");
		ft_error();
	}
	if(!(pars->map = (int**)malloc(sizeof(int*) * pars->nb_lin)))
		return (0);
	while (i < pars->nb_lin)
	{
		if(!(pars->map[i] = (int*)malloc(sizeof(int) * pars->nb_col)))
			return (0);
		i++;
	}
	stock_in_map(str, pars);
	return (1);
}

int		ft_parser(int fd, t_pars *pars)
{
	char	buff[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		ret;

	str = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin_gnl(tmp, buff);
		free(tmp);
	}
	if (str == NULL || ret <= -1)
	{
		free(str);
		ft_putstr("STRING NULL\n");
		ft_error();
	}
	create_map(str, pars);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:54:12 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/20 20:39:28 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

char			***move_tetr_put_letter(char ***tab)           //malloc lastructure t_piece
{
	t_piece		piec;

	piec.i = 0;
	while (tab[piec.i])
	{
		piec.r = 0;
		piec.x = first_c(tab[piec.i], '#');
		piec.y = first_r(tab[piec.i], '#');
		while (piec.r < 4)
		{
			piec.c = 0;
			while (piec.c < 4)
			{
				if (tab[piec.i][piec.r][piec.c] == '#')
				{
					tab[piec.i][piec.r][piec.c] = '.';
					tab[piec.i][piec.r - piec.y][piec.c - piec.x] = piec.i + 65;
				}
				piec.c++;
			}
			piec.r++;
		}
		piec.i++;
	}
	return (tab);
}

char		***parsing(int ac, char **av, char ***tab)
{
	int		fd;
	int		i;

	i = 0;
	tab = NULL;
	if (ac == 2)                      //peut gagner place en mettant cette condition dans main
	{
		tab = init_big_tab(tab);
		fd = open(av[1], O_RDONLY);
		if (read_file(fd, tab) == 0)
		{
			while (tab[i])
			{
				if (check_valid_form(tab[i]) == 0)
					i++;
				else
					return (NULL);
  			}
			tab = move_tetr_put_letter(tab);
		}
		else
			return (NULL);
		close(fd);
	}
	return (tab);
}
/*
int			ft_error_file(int ac, char **av, char ***tab)
{

	if (ac != 2)
		return (-1);
	if (read_file(fd, tab) == -1 || read_one(fd) == -1)
		return (-1);
//	if (init_big_tab(tab) == NULL)
//		return (-2);
	
}*/

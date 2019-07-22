/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:16:08 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/22 23:04:22 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		return_error(char ***tab, char **map)
{
	free_map(map);
	free_tab(tab);
	ft_putstr("error");
	ft_putchar('\n');
}

char		**remalloc_map(char **map, int size)
{
	int		y;

	y = 0;
	if (!map)
		return (NULL);
	free_map(map);
	if (!(map = malloc_map(size)))
		return (NULL);
	return (map);

}

void		execute_final(char ***tab, char **map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	print_tab(map);
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_strdel(&tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	(tab) ? free(tab) : 0;
	k = 0;
	while (map && map[k])
	{
		ft_strdel(&map[k]);
		k++;
	}
	(map) ? free(map) : 0;
}

int			main(int ac, char **av)
{
	char	***tab;
	char	**map;
	int		size;

	map = NULL;
	tab = parsing(ac, av, NULL);
	size = ft_approx_sqrt(count_tetris(tab) * 4);
	if (ac != 2 || tab == NULL)
	{
		return_error(tab, map);
		return (0);
	}
	if (!(map = malloc_map(size)))
		return (-1);
	while  (check_map(tab, map) == -1)
		if (!(map = remalloc_map(map, ++size)))
			return (-1);;
	print_tab(map);
	free_tab(tab);
	free_map(map);
	return (0);
}

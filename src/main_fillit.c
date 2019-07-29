/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:16:08 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/29 17:37:16 by ccarole          ###   ########.fr       */
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
	print_tab(map);
	free_tab(tab);
	free_map(map);
}

int			main(int ac, char **av)
{
	char	***tab;
	char	**map;
	int		size;

	map = NULL;
	tab = NULL;
//	size = ft_approx_sqrt(count_tetris(tab) * 4);
//	printf("size = %d\n", size);
	if (ac != 2)
	{
		ft_putstr_fd("Usage: use at least one file and just one\n", 1);
		return (0);
	}
	tab = parsing(av, tab);
	size = ft_approx_sqrt(count_tetris(tab) * 4);
	printf("size = %d\n", size);
	if (tab == NULL)
	{
		return_error(tab, map);
		return (0);
	}
	printf("size 2  = %d\n", size);
	if (!(map = malloc_map(size)))
		handle_error(tab, map);
	while (check_map(tab, map) == -1)
	{
		printf("entre la\n");
		if (!(map = remalloc_map(map, ++size)))
			handle_error(tab, map);
	}
	printf("size 3  = %d\n", size);
	execute_final(tab, map);
	return (0);
}

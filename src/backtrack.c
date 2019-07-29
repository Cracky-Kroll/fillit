/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/29 17:58:02 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_approx_sqrt(int nb)
{
	int		a;

	a = 1;
	while (a * a < nb)
		a++;
	return (a);
}

char		**malloc_map(int size)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	if (!(map = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		if (!(map[y] = (char*)ft_memalloc(sizeof(char) * (size + 1))))
			return (NULL);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	return (map);
}

int			c_ref(char **tab)
{
	int		c;

	c = 0;
	while (tab[0][c] == '.' && tab[0][c] != '\0')
		c++;
	return (c);
}

void		new_x_y_in_check_map(int *x, int *y)
{
	*x = 0;
	*y = *y + 1;
}

int			check_map(char ***tab, char **map)
{
	int		int_t[3];

	ft_memset(int_t, 0, 12);
	while (int_t[0] < count_tetris(tab))
	{
//		printf("CHECK 1: len = %d, i = %d, count_tetris(tab) = %d, x = %d, y = %d\n", len_map(map), int_t[0], count_tetris(tab), int_t[1], int_t[2]);
		if (can_place(map, tab[int_t[0]], int_t[1], int_t[2]) == 0)
		{
//		printf("CHECK - can place : len = %d, i = %d, x = %d, y = %d\n", len_map(map), int_t[0], int_t[1], int_t[2]);
			put_in_map(tab[int_t[0]++], map, int_t[1], int_t[2]);
			int_t[1] = 0;
			int_t[2] = 0;
		}
		else if (int_t[1] < len_map(map) - 1)
		{
//		printf("CHECK else 1: len = %d, i = %d, x = %d, y = %d\n", len_map(map), int_t[0], int_t[1], int_t[2]);
			int_t[1]++;
		}
		else if (int_t[2] < len_map(map) - 1)
		{
//			printf("CHECK else 2: len = %d, i = %d, x = %d, y = %d\n", len_map(map), int_t[0], int_t[1], int_t[2]);
			new_x_y_in_check_map(&int_t[1], &int_t[2]);
		}
		else
		{
//		printf("CHECK final : len = %d, i = %d, x = %d, y = %d\n", len_map(map), int_t[0], int_t[1], int_t[2]);
			int_t[0]--;
			if (int_t[0] < 0)
				return (-1);
//			print_tab(map);
//			printf("\n");
//		printf("CHECK final apres : i = %d, x = %d, y = %d\n", int_t[0], int_t[1], int_t[2]);
			remove_piece(map, int_t[0], &int_t[1], &int_t[2]);
//		printf("CHECK final apres : i = %d, x = %d, y = %d\n", int_t[0], int_t[1], int_t[2]);
		}
	}
	return (0);
}

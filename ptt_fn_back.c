/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptt_fn_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:16:25 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/17 09:42:42 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			len_map(char **map)
{
	int		n;

	n = 0;
	while (map[0][n] != '\0')
	{
		n++;
	}
	return (n);
}

int			can_place(char **map, char **tab, int x, int y)
{
	int		l;
	int		r;
	int		c;
//	t_map	m;

	r = 0;
	l = c_ref(tab);
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (tab[r][c] != '.' && (y + r > len_map(map) - 1 || x + c - l > len_map(map) - 1))
				return (-1);
			if (tab[r][c] != '.' && map[y + r][x + c - l] != '.')
				return (-1);
			printf("can_place :: c = %d, r = %d, m.y = %d, m.x = %d\n", c, r, y, x);
			c++;
		}
		r++;
	}
	return (0);
}

void		put_in_map(char **tab, char **map, int x, int y)
{
	int		l;
	int		r;
	int		c;
	int		h;   // nb de hachtag poses
//	t_map	m;

	h = 0;
	r = 0;
	l = c_ref(tab);
	while (r < 4 || h < 4)
	{
		c = 0;
		printf("put_in_map :: r = %d, c = %d, h = %d, l = %d, *x = %d, *y = %d, len_map(map) = %d\n", r, c, h, l, x, y, len_map(map));
		while (c < 4) // || h < 4)
		{
			if (tab[r][c] != '.' && tab[r][c] != '\0' && map[y + r][x + c - l] == '.')
			{
				printf("put in map ::tab [r] = %d, [c] = %d, y = %d, x = %d, l = %d, map [ y + r] = %d, [x + c - l] = %d, letter = %c\n", r, c, y, x, l, (y + r), (x + c - l), tab[r][c]);
				map[y + r][x + c - l] = tab[r][c];
				h++;
			}
			c++;
		}
		r++;
	}
}

void		remove_piece(char **map, int i, int  *x, int *y)
{
	int		count;
	int		j;
	int		z;

	j = 0;
	z = 0;
	count = 0;
	while (j < len_map(map))
	{
		z = 0;
		printf("j = %d, z = %d, (i + 65) = %c\n", j, z, i + 65);
		while (z < len_map(map))
		{
			if (map[j][z] == i + 65)
			{
					print_tab(map);
					printf("map[j][z] = %c\n", map[j][z]);
				map[j][z] = '.';
					printf("map[j][z] = %c\n", map[j][z]);
					print_tab(map);
				count++;
				if (count == 1)
				{
					if (z + 1 < len_map(map))
						*x = z + 1;
					else
					{
						*x = 0;
						*y = j + 1;
					}
				}
			}
			z++;
		}
		j++;
	}
}

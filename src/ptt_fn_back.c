/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptt_fn_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:16:25 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/29 17:57:44 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			can_place(char **map, char **tab, int x, int y)
{
	int		l;
	int		r;
	int		c;

	r = 0;
	l = c_ref(tab);
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (tab[r][c] != '.' && (y + r > len_map(map) - 1
						|| x + c - l > len_map(map) - 1))
				return (-1);
			if (tab[r][c] != '.' && map[y + r][x + c - l] != '.')
				return (-1);
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
	int		h;

	h = 0;
	r = 0;
	l = c_ref(tab);
	while (r < 4 || h < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (tab[r][c] != '.' && tab[r][c] != '\0'
					&& map[y + r][x + c - l] == '.')
			{
				map[y + r][x + c - l] = tab[r][c];
				h++;
			}
			c++;
		}
		r++;
	}
}

void		new_x_y_remove1(int j, int z, int *x, int *y)
{
	*x = z + 1;
	*y = j;
}

void		new_x_y_remove2(int j, int *x, int *y)
{
	*x = 0;
	*y = j + 1;
}

void		remove_piece(char **map, int i, int *x, int *y)
{
	int		count;
	int		j;
	int		z;

	j = 0;
	count = 0;
	while (j < len_map(map) && count < 4)
	{
		z = 0;
		while (z < len_map(map) && count < 4)
		{
			if (map[j][z] == i + 65)
			{
				map[j][z] = '.';
				count++;
				if (count == 1 && z + 1 < len_map(map))
				{
//					printf("REMOVE 1 avant :count = %d, *x = %d, *y = %d, z = %d, z+1 = %d, j = %d, j + 1 = %d\n", count, *x, *y, z, z + 1, j, j + 1);
//					*x = z + 1;
					new_x_y_remove1(j, z, &*x, &*y);
//					printf("REMOVE 1 apres : *x = %d, *y = %d, z = %d, z+1 = %d, j = %d, j + 1 = %d\n",*x, *y, z, z + 1, j, j + 1);
				}
				else if (count == 1 && z + 1 == len_map(map))
				{
//					printf("REMOVE 2 avant : count = %d, *x = %d, *y = %d, z = %d, z+1 = %d, j = %d, j + 1 = %d\n", count, *x, *y, z, z + 1, j, j + 1);
					new_x_y_remove2(j, &*x, &*y);
//					printf("REMOVE 2 : apres  *x = %d, *y = %d, z = %d, z+1 = %d, j = %d, j + 1 = %d\n", *x, *y, z, z + 1, j, j + 1);
				}
			}
			z++;
		}
		j++;
	}
}

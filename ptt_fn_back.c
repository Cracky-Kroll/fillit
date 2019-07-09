/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptt_fn_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:16:25 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/09 21:27:13 by ccarole          ###   ########.fr       */
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

int			can_place(char **map, char **tab)
{
	int		l;
	int		r;
	int		c;
	t_map	m;

	r = 0;
	l = c_ref(tab);
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (tab[r][c] != '.' && map[m.y + r][m.x + c - l] != '.')
				return (-1);
			if (tab[r][c] != '.' && (m.y + r > len_map(map) - 1 || m.x + c - l > len_map(map)))
				return (-1);
			c++;
		}
		r++;
	}
	return (0);
}

void		put_in_map(char **tab, char **map)
{
	int		l;
	int		r;
	int		c;
	int		h;   // nb de hachtag poses
	t_map	m;

	h = 0;
	r = 0;
	l = c_ref(tab);
	while (r < 4 || h == 4)
	{
		c = 0;
		while (c < 4 || h == 4)
		{
			if (tab[r][c] != '.' && map[m.y + r][m.x + c - l] == '.')
			{
				map[m.y + r][m.x + c - l] = tab[r][c];
				h++;
			}
			c++;
		}
		r++;
	}
}

void		remove_piece(char **map, int i, int  *x, int *y)
{

	*x = 0;
	*y = 0;
	while (*y < len_map(map))
	{
		*x = 0;
		printf("y = %d, x = %d, (i + 65) = %c\n", *y, *x, i + 65);
		while (*x < len_map(map))
		{
			if (map[*y][*x] == i + 65)
			{
					print_tab(map);
					printf("map[y][c] = %c\n", map[*y][*x]);
				map[*y][*x] = '.';
					printf("map[y][c] = %c\n", map[y][x]);
					print_tab(map);
			}
			*x++;
		}
		*y++;
	}
}

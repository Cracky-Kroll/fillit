/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/19 18:00:05 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>      // a supprime en plus des printf !!!!!!!!!

int	count_tetris(char ***tab);

char	**malloc_map(char ***tab, int nb_p)
{
	int		size;
	char	**map;
	int		i;

	nb_p = count_tetris(tab);
	size = ft_sqrt(nb_p * 4);
	if (!(map = (char**)malloc(sizeof (char*) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		i++;
	}
	return (map);
}

char		**new_map(char ***tab, int nb_p)
{
	char	**map;
	int		x;
	int		y;

	nb_p = count_tetris(tab);
	x = 0;
	y = 0;
	map = malloc_map(tab, nb_p);
	while (map)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

void		remove_piece(char **map, int i)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map)
	{
		x = 0;
		while (map[y][x] != (i + 65) && map[y][x] != '\0')
			x++;
		if (map[y][x] == (i + 65))
		{
			map[y][x] = '.';
			x++;
		}
		if (map[y][x] == '\0')
			y++;
	}
}

char		**check_map(char ***tab)
{
	char	**map;    // pr map
	int		x_start;
	int		y_start;
	int		x;
	int		y;

	int		i;        //pour tab - trouver ou initialiser variables 
	int		r;
	int		c;
	int		w;

	w = count_tetris(tab);
	//	if (map[y][x] != '.')
	//		x++;
	while (w > 0)
	{
		while (map[y_start][x_start] != '.' && map[x_start][y_start] != '\0')
		{
			x_start++;
			if (map[y_start][x_start] == '\0' && map[y_start + 1][0] != '\0')
			{
				x_start = 0;
				y_start++;
			}
		}
		while (tab[i][r][c] == '.')
			c++;
		while (r < 4 && c < 4)
		{
			x = x_start;
			y = y_start;
			if (tab[i][r][c] != '.' && tab[i][r][c] != '\0' && map[y][x] == '.')
			{
				map[y][x] = i + 65;
				c++;
				x++;
			}
			if (tab[i][r][c] == '\0' && r < 4)
			{
				r++;
				x = x - c;
				c = 0;
				y++;
			}
			if (r == 4 && c == 4)
			{
				w--;
				i++;
			}
			if ((tab[i][r][c] != '.' && tab[i][r][c] != '\0') && (map[y][x] == '\0' || map[y][x] != '.'))
			{
				remove_piece(map, i);
				if (map[y][x_start + 1] != '\0')
					x_start = x_start + 1;
				else if (map[y][x_start + 1] == '\0' && map[y_start + 1][0] != '\0')
				{
					x_start = 0;
					y_start = y_start + 1;
				}
				if (map[y][x_start + 1] == '\0' && map[y_start + 1][0] == '\0')
				{
					free(map);
					map = new_map(tab, count_tetris(tab) + 1);
				}
			}
		}
	}
	return (map);
}















char		**backtrack(char ***tab)
{
	int		nb_p;			// --->> mettre en structure
	int		round;           // compte nb de fois ou doit agrandir la map
	int		stop;            //fn s arrete quand toutes les pueces sont posees avec bonne condition


	nb_p = count_tetris(tab) + round;    //au debut round = 0, pr pv faire en recursive

}

char		form_of_tet(char ***tab)
{

	while (tab[i][r][c] == '.')
		c++;
}

void		put_in_map(char ***tab)
{
	if (tab[i][r][c] == '.')
	{
		c++;
	}
	if (tab[i][r][c] >= 'A' && tab[i][r][c] <= 'Z')
	{
		map[y][x] = tab[i][r][c];
		x++;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/18 19:05:42 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>      // a supprime en plus des printf !!!!!!!!!

int	count_tetris(char ***tab);

char	**malloc_map(char ***tab)
{
	int		size;
	char	**map;
	int		i;
	int		nb_p;

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

char	**new_map(char ***tab, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map = malloc_map(tab);
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

int			check_map(char ***tab)
{
	char	**map;    // pr map
	int		x;
	int		y;
	int		i;        //pour tab - trouver ou initialiser variables 
	int		r;
	int		c;

//	if (map[y][x] != '.')
//		x++;
	if (map[y][x] == '.')
	{
		while (tab[i][r][c] == '.')
			c++;
		map[y][x] = i + 65;                      // en recursive pour la suite
		if (tab[i][r][c] != '.' && tab[i][r][c] != '\0' && map[y][x] == '.')
				map[y][x] = i + 65;
		if (tab[i][r][c + 1] != '.' && tab[i][r][c + 1] != '\0' && map[y][x + 1] == '.')
				map[y][x + 1] = i + 65;
		if (tab[i][r][c + 2] != '.' && tab[i][r][c + 2] != '\0' && map[y][x + 2] == '.')
				map[y][x + 2] = i + 65;
		if (tab[i][r][c + 3] != '.' && tab[i][r][c + 3] != '\0' && map[y][x + 3] == '.')
				map[y][x + 3] = i + 65;
		if (tab[i][r][c + 4] != '.' && tab[i][r][c + 4] != '\0' && map[y][x + 4] == '.')
				map[y][x + 4] = i + 65;          // oui, check a droite, si non check desous.- si oui check a droite -> si oui encore a droite / si non a gauche / si moindre erreurs on remplace tous les i + 65 de la map par des points et on check a partir de x + 1 / si pb a partir de  y + 1 / 
		if (tab[i][r][c + 1] != '.' && tab[i][r][c] != '\0' && (map[y][x + 1] == '\0' || map[y][x + 1] != '.'))
				map[y][x] == '.';             // pareil qu'au dessus 

	}



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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/18 18:13:28 by ccarole          ###   ########.fr       */
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

int			check_map(char ***tab)
{

	if (map[y][x] != '.')
		x++;
	if (map[y][x] == '.')
	{
		while (tab[i][r][c] == '.')
			c++;
		map[y][x] = i + 65;
		if (tab[i][r][c + 1] != '.' && tab[i][r][c + 1] != '\0' && map[y][x + 1] == '.')
				map[y][x + 1] = i + 65;
		if (tab[i][r][c + 2] != '.' && tab[i][r][c + 2] != '\0' && map[y][x + 2] == '.')
				map[y][x + 2] = i + 65;
		if (tab[i][r][c + 3] != '.' && tab[i][r][c + 3] != '\0' && map[y][x + 3] == '.')
				map[y][x + 3] = i + 65;
		if (tab[i][r][c + 4] != '.' && tab[i][r][c + 4] != '\0' && map[y][x + 4] == '.')
				map[y][x + 4] = i + 65;
		if (tab[i][r][c + 1] != '.' && tab[i][r][c] != '\0' && (map[y][x + 1] == '\0' || map[y][x + 1] != '.'))
				map[y][x] == '.';
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


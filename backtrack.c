/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/18 15:15:07 by ccarole          ###   ########.fr       */
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/22 22:52:25 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>      // a supprime en plus des printf !!!!!!!!!

int			ft_approx_sqrt(int nb)  //calcul taille map minimum en arrondissant la racine carre
{
	int		a;

	a = 1;
	while (a * a < nb)
		a++;
	return (a);

}

char	**malloc_map(int size)			//structure t_map
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

int			c_ref(char **tab)        // pour touver premier caractere dans le tableau au raw 0
{
	int		c;

	c = 0;
	while (tab[0][c] == '.' && tab[0][c] != '\0')
		c++;
	return (c);
}

int		check_map(char ***tab, char **map)
{
	int	int_t[3];
/*	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;*/
	ft_memset(int_t, 0, 12);
	while (int_t[0] < count_tetris(tab))
	{
		if (can_place(map, tab[int_t[0]], int_t[1], int_t[2]) == 0)
		{
			put_in_map(tab[int_t[0]++], map, int_t[1], int_t[2]);
			int_t[1] = 0;
			int_t[2] = 0;
		}
		else if (int_t[1] < len_map(map) - 1)
			int_t[1]++;
		else if (int_t[2] < len_map(map) - 1)// && (int_t[1] = 0))
		{
			int_t[1] = 0;
			int_t[2]++;
		}
		else
		{
			int_t[0]--;
			if (int_t[0] < 0)
				return (-1);
			remove_piece(map, int_t[0], &int_t[1], &int_t[2]);
		}
	}
	return (0);
}
/*								dans fichier main.c
int		main(int ac, char **av)
{
	char	***tab;
	char	**map;
	int		size;

	tab = NULL;
	tab = parsing(ac, av, tab);
	size = ft_approx_sqrt(count_tetris(tab) * 4);
	printf("MAIN :: size = %d, count_tetris = %d\n", size, count_tetris(tab));
	map = malloc_map(size);
	printf("MAIN ; MAP APRES 1ER MALLOC\n");
	print_tab(map);
	printf("MAIN :: test1, ac = %d\n", ac);
	//faire fonction d'erreur
	if (tab == NULL)                       // free ici ou plus tot ?
		printf("Piece invalide :( %s%d\n", __FILE__, __LINE__);
	printf("MAIN :: test3, \n");
	while  (check_map(tab, map) == -1)
	{
		printf("MAIN :: REMALLOC MAP\n");
		free(map);
		size++;
		if (!(map = malloc_map(size)))
			return (-1);
	}
	printf("MAIN : CHECK MAP = 0 :: print tab(map)\n");
	print_tab(map);
	printf("main :: test4, \n");
//	print_tab(map);
//	free(tab);
//	free(map);
	return (0);
}*/

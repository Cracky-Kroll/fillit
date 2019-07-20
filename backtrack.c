/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/20 17:14:08 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>      // a supprime en plus des printf !!!!!!!!!

int			ft_approx_sqrt(int nb)  //calcul taille map minimum en arrondissant la racine carre
{
	int		a;

	a = 1;
	printf("ft_approx_sqrt- nb = %d\n", nb);
	while (a * a < nb)
		a++;
	printf("ft_approx_sqrt---a = %d\n", a);
	fflush(stdout);
	return (a);

}

char	**malloc_map(int size)
{
	t_map	m;

	m.y = 0;
	m.x = 0;
//	printf("test_malloc_map_00, m.y = %d, size = %d\n", m.y, size);
	if (!(m.map = (char**)malloc(sizeof (char*) * size + 1)))
		return (NULL);
//	printf("test_malloc_map, m.y = %d, size = %d\n", m.y, size);
//	fflush(stdout);
	while (m.y < size)
	{
		if (!(m.map[m.y] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		m.x = 0;
		while (m.x < size)
		{
			m.map[m.y][m.x] = '.';
			m.x++;
//			printf("map[m.y][m.x], m.y = %d, m.x = %d\n ", m.y, m.x);
		}
		m.map[m.y][m.x] = '\0';
		m.y++;
//		printf("test_malloc_map_dans boucle, m.y = %d, m.x back zero = %d, (size + 1) = %d\n ", m.y, m.x, (size + 1));
	}
	m.map[m.y] = NULL;
//	printf("m.y_fin_malloc_map = %d, m.x = %d\n ", m.y, m.x);
//	print_tab(m.map);
	return (m.map);
}

int			c_ref(char **tab)        // pour touver premier caractere dans le tableau au raw 0
{
	int		c;

	c = 0;
	while (tab[0][c] == '.' && tab[0][c] != '\0')
		c++;
//	printf("c_ref = %d\n", c);
	return (c);
}

int		check_map(char ***tab, char **map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < count_tetris(tab))
	{
//		printf("check_map : debut while i = %d, count_tetris(tab) = %d\n", i, count_tetris(tab));
		if (can_place(map, tab[i], x, y) == 0)
		{
//			printf("check_map AVANT PUT:: i = %d, x = %d, y = %d\n", i, x, y);
			put_in_map(tab[i], map, x, y);
			i++;
			x = 0;
			y = 0;
//			printf("check_map : APRES PUT: i = %d, x = %d, y = %d, count_tetris = %d\n", i, x, y, count_tetris(tab));
		}
		else if (x < len_map(map) - 1)
		{
//			printf("CHECK : ELSE IF ; x = %d < len - 1 = %d\n", x, len_map(map) - 1);
			x++;
		}
		else if (y < len_map(map) - 1)
		{
			x = 0;
			y++;
		}
		else
		{
			i--;
			if (i < 0)
				return (-1);
//			printf("CHECK MAP // i A REMOVE = %d, x = %d, y = %d\n", i, x, y);
			remove_piece(map, i, &x, &y);
//			printf("CHECK MAP APRES REMOVE / X = %d, Y = %d\n", x, y);
		}
	}

	printf("sort check_map");
//	print_tab(map);
//	printf("sort check_map");
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

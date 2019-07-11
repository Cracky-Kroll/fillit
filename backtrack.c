/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/11 18:04:35 by ccarole          ###   ########.fr       */
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

//	nb_p = count_tetris(tab);
//	m.size = ft_approx_sqrt(nb_p * 4);
	m.y = 0;
	m.x = 0;
	printf("test_malloc_map_00, m.y = %d, size = %d\n", m.y, size);
	if (!(m.map = (char**)malloc(sizeof (char*) * size + 1)))
		return (NULL);
	printf("test_malloc_map, m.y = %d, size = %d\n", m.y, size);
	fflush(stdout);
	while (m.y < size)
	{
		if (!(m.map[m.y] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		m.x = 0;
		while (m.x < size)
		{
			m.map[m.y][m.x] = '.';
			m.x++;
			printf("map[m.y][m.x], m.y = %d, m.x = %d\n ", m.y, m.x);
		}
		m.map[m.y][m.x] = '\0';
		m.y++;
		printf("test_malloc_map_dans boucle, m.y = %d, m.x back zero = %d, (size + 1) = %d\n ", m.y, m.x, (size + 1));
	}
	m.map[m.y] = NULL;
	printf("m.y_fin_malloc_map = %d, m.x = %d\n ", m.y, m.x);
	return (m.map);
}

int			c_ref(char **tab)        // pour touver premier caractere dans le tableau au raw 0
{
	int		c;

	c = 0;
	while (tab[0][c] == '.' && tab[0][c] != '\0')
		c++;
	printf("c_ref = %d\n", c);
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
		if (can_place(map, tab[i], x, y) == 0)
		{
//			x = 0;
//			y = 0;
			put_in_map(tab[i], map, x, y);
			printf("check_map :: i = %d, x = %d, y = %d\n", i, x, y);
			print_tab(map);
			x = 0;
			y = 0;
			i++;
		}
		else if (x < len_map(map) - 1)
			x++;
		else if (y < len_map(map) - 1)
		{
			x = 0;
			y++;
		}
		else
		{
			printf("CHECK MAP // i = %d\n", i);
			i--;
			if (i < 0)
				return (-1);
			printf("CHECK MAP // i A REMOVE = %d, x = %d, y = %d\n", i, x, y);
			remove_piece(map, i, &x, &y);
			printf("CHECK MAP APRES REMOVE / X = %d, Y = %d\n", x, y);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	***tab;
	int		i = 0;
	char	**map;
	int		size;

	tab = NULL;
	tab = parsing(ac, av, tab);
	size = ft_approx_sqrt(count_tetris(tab) * 4);
	printf("MAIN :: size = %d, count_tetris = %d\n", size, count_tetris(tab));
	map = malloc_map(size);
	print_tab(map);
	printf("MAIN :: test1, ac = %d\n", ac);
	if (tab == NULL)                       // free ici ou plus tot ?
		printf("Piece invalide :( %s%d\n", __FILE__, __LINE__);
//	else
//		while (tab[i])
//		{
//			print_tab(tab[i]);
//			i++;
//			printf("MAIN :: test2, i = %d\n", i);
//		}
	printf("MAIN :: test3, i = %d\n", i);
	if (check_map(tab, map) == -1)
	{
		printf("MAIN :: REMALLOC MAP\n");
		free(map);
		size++;
		map = malloc_map(size);
	}
	if (check_map(tab, map) == 0)
		print_tab(map);
	printf("main :: test4, i = %d\n", i);
	return (0);
}












/*
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
   }*/


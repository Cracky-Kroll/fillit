/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/20 17:58:23 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>      // a supprime en plus des printf !!!!!!!!!

int			ft_approx_sqrt(int nb)
{
	int		a;

	a = 1;
	printf("ft_approx_sqrt---a = %d, nb = %d\n", a, nb);
	if (nb > 26 || nb < 0)
		return (-1);
	while (a * a < nb)
		a++;
	printf("ft_approx_sqrt---a = %d\n", a);
	fflush(stdout);
	return (a);

}

char	**malloc_map(char ***tab, int nb_p)
{
	int		size;
	char	**map;
	int		i;
	int		j;

	nb_p = count_tetris(tab);
	size = ft_approx_sqrt(nb_p * 4);
	i = 0;
	j = 0;
	printf("test_malloc_map_00, i = %d, size = %d, nb tetri = %d\n", i, size, nb_p);
	if (!(map = (char**)malloc(sizeof (char*) * size + 1)))
		return (NULL);
	printf("test_malloc_map, i = %d, size = %d, nb tetri = %d\n", i, size, nb_p);
	fflush(stdout);
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
			printf("map[i][j], i = %d, j = %d\n ", i, j);
		}
		map[i][j] = '\0';
		i++;
		printf("test_malloc_map_dans boucle, i = %d, j back zero = %d, (size + 1) = %d\n ", i, j, (size + 1));
	}
	map[i] = NULL;
	printf("i_fin_malloc_map = %d, j = %d\n ", i, j);
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
		if (map[y][x] != (i + 65) && map[y][x] != '\0')
			x++;
		if (map[y][x] == (i + 65))
		{
			map[y][x] = '.';
			x++;
		}
		if (map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
	}
}

char		**check_map(char ***tab)
{
	char	**map = NULL;    // pr map
	int		x_start;
	int		y_start;
	int		x;
	int		y;
	int		size;

	int		i;        //pour tab - trouver ou initialiser variables 
	int		r;
	int		c;
	int		w;

	x_start = 0;
	y_start = 0;
	w = count_tetris(tab);
	size = count_tetris(tab);
	map = malloc_map(tab, size);
	print_tab(map);
	i = 0;
	r = 0;
	c = 0;
	printf("check_map_debut: i = %d, w = %d, size = %d\n ", i, w, size);
	while (w > 0)
	{
//		r = 0;
//	x_start = 0;
//	y_start = 0;
		printf("check_map_debut_while: i = %d, w = %d, size = %d, y_start = %d, x_start = %d\n ", i, w, size, y_start, x_start);
		while (map[y_start][x_start] != '.' && map[x_start][y_start] != '\0')
		{
			printf("check_map_debut_while_2: y_start = %d, x_start =  %d\n ", y_start, x_start);
			x_start++;
			if (map[y_start][x_start] == '\0' && map[y_start + 1][0] != '\0')
			{
				x_start = 0;
				y_start++;
			}
			printf("check_map_fin_while_2: y_start = %d, x_start =  %d\n ", y_start, x_start);
		}
		r = 0;
		printf("check_map_tab[i][r][c]: i = %d, r = %d, c = %d\n ", i, r, c);
		while (r < 4 && c < 4)
		{
			x = x_start;
			y = y_start;
			while (r < 4 && tab[i][r][c] != '\0')
			{
				if ((tab[i][r][c] != '.' && tab[i][r][c] != '\0') && (map[y][x] == '.' && map[y][x] != '\0'))
				{
					map[y][x] = i + 65;
					c++;
		//			let++;
					if (tab[i][r][c + 1] == i + 65)
						printf("entrela");x++;
				}
				else if (tab[i][r][c] == '.' && tab[i][r][c] != '\0')
				{
					c++;
//					x++;
				}
			printf("check_map_milieu_while_3: y = %d, x =  %d, c = %d, r = %d, i = %d\n ", y, x, c, r, i);
				if (c == 3 && r < 4)
				{
					r++;
					x = x_start;// -let -// first_i(tab[i], (i + 65));
					c = 0;
					y++;
			printf("check_map_milieu_change de rang: first_i(tab[i], (i + 65)) = %d, y = %d, x =  %d, c = %d, r = %d, i = %d, i + 65 = %c\n ",first_i(tab[i], (i + 65)),  y, x, c, r, i, (i + 65));
				}
			printf("check_map_fin_while_3: y = %d, x =  %d, c = %d, r = %d, i = %d\n ", y, x, c, r, i);
				print_tab(map);
			}
			if (r == 4)          //veut dire qu'on a pu aller au bout tetrimino et donc le placer
			{
				w--;
				i++;
			printf("check_map_fin_while_4_ r == 4: w = %d, y = %d, x =  %d, c = %d, r = %d, i = %d\n ", w, y, x, c, r, i);
			}
		}
//		r = 0;
//		c = 0;
		printf("sort de boucle\n");
	}
			if ((tab[i][r][c] != '.' && tab[i][r][c] != '\0') && (map[y][x] == '\0' || map[y][x] != '.')) //pb car i trop grand
			{
				remove_piece(map, i);
				if (map[y][x_start + 1] != '\0')
					x_start = x_start + 1;
				else if (map[y][x_start + 1] == '\0' && map[y_start + 1][0] != '\0')
				{
					x_start = 0;
					y_start = y_start + 1;
				}
				//doit check si piece se place pas remove_piece precedente et essaye 
				//de placer piece en cours ==> w++; sinon eleve encore piece precedente
				//
				if (map[y][x_start + 1] == '\0' && map[y_start + 1][0] == '\0')  //free map
				{
					free(map);
					size = size + 1;
					map = malloc_map(tab, size);
				}
			}
	return (map);
}


int		main(int ac, char **av)
{
	char	***tab;
	int		i = 0;
	char	**map;

	tab = NULL;
	tab = parsing(ac, av, tab);
	printf("test1, ac = %d\n", ac);
	if (tab == NULL)                       // free ici ou plus tot ?
		printf("Piece invalide :( %s%d\n", __FILE__, __LINE__);
	else
		while (tab[i])
		{
			print_tab(tab[i]);
			i++;
			printf("test2, i = %d\n", i);
		}
	printf("test3, i = %d\n", i);
	map = check_map(tab);
	printf("test4, i = %d\n", i);
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


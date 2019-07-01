/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:36:17 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/01 15:21:09 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>      // a supprime en plus des printf !!!!!!!!!

int			ft_approx_sqrt(int nb)  //calcul taille map minimum en arrondissant la racine carre
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
	t_map	m;

	nb_p = count_tetris(tab);
	m.size = ft_approx_sqrt(nb_p * 4);
	m.y = 0;
	m.x = 0;
	printf("test_malloc_map_00, m.y = %d, size = %d, nb tetri = %d\n", m.y, m.size, nb_p);
	if (!(m.map = (char**)malloc(sizeof (char*) * m.size + 1)))
		return (NULL);
	printf("test_malloc_map, m.y = %d, size = %d, nb tetri = %d\n", m.y, m.size, nb_p);
	fflush(stdout);
	while (m.y < m.size)
	{
		if (!(m.map[m.y] = (char*)malloc(sizeof(char) * m.size + 1)))
			return (NULL);
		m.x = 0;
		while (m.x < m.size)
		{
			m.map[m.y][m.x] = '.';
			m.x++;
			printf("map[m.y][m.x], m.y = %d, m.x = %d\n ", m.y, m.x);
		}
		m.map[m.y][m.x] = '\0';
		m.y++;
		printf("test_malloc_map_dans boucle, m.y = %d, m.x back zero = %d, (size + 1) = %d\n ", m.y, m.x, (m.size + 1));
	}
	m.map[m.y] = NULL;
	printf("m.y_fin_malloc_map = %d, m.x = %d\n ", m.y, m.x);
	return (m.map);
}

void		remove_piece(char **map, int i)
{
	int		x;
	int		y;
	int		map_size;

	map_size = ft_strlen(map[0]) - 1;
	x = 0;
	y = 0;
	while (y <= map_size)
	{
		printf("y = %d, x = %d, (i + 65) = %c\n", y, x, i + 65);
		if (map[y][x] == i + 65)
		{
			print_tab(map);
			printf("map[y][c] = %c\n", map[y][x]);
			map[y][x] = '.';
			printf("map[y][c] = %c\n", map[y][x]);
			print_tab(map);
			x++;
		}
		else if (map[y][x] != i + 65 && map[y][x] != '\0')
			x++;
		if (map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
	}
}

int			can_place(char **map)     // avec liste chainees
{
	if (map[tr0 + y][tc0 + x] == '.' && map[tr1 + y][tc1 + x] == '.'
			&& map[tr2 + y][tc2 + x] == '.' && map[tr3 + y][tc3 + x] == '.')
		return (0);
	return (-1);
}

/*
int			can_place(char **tab, char **map) //       je ne l'ai pas utilisee elle ne marche pas pour le moment.
{

	t_piece		t;
	t_map		m;

	map = m.map;
	t.r = 0;
	while (t.r < 4)
	{
		t.c = 0;
		while (t.c < 4)
		{
			if (((tab[t.r][t.c] <= 'Z') && (tab[t.r][t.c] >= 'A')) && (map[t.r + m.y][t.c + m.x] != '.'))
				return (-1);
			else
				t.c = t.c + 1;
		}
		t.r++;
	}
	return (0);
}

void		put_in_map(char **tab, char **map)       // pas utilisee non plus(encore)
{
	t_piece		t;
	t_map		m;

	map = m.map;
	t.r = -1;
	while (t.r < 4)
	{
		t.c = -1;
		while (t.c < 4)
		{
			if (((tab[t.r][t.c] <= 'Z') && (tab[t.r][t.c] >= 'A')) && (map[t.r + m.y][t.c + m.x] == '.'))
				m.map[t.r + m.y][t.c + m.x] = tab[t.r][t.c];
			else
				t.c = t.c + 1;;
		}
		t.r++;
	}
}*/
/*                                             //debut d'un autre essai de backtracking 
char		**backtrac(char ***tab)
{
	t_piece		p;
	t_map		m;
	p.w = count_tetris(tab);
	m.size = count_tetris(tab);
	m.map = malloc_map(tab, m.size);
	print_tab(m.map);
	m.x = 0;
	m.y = 0;
	while (count_tetris(tab) > 1)
	{
	printf("backtrac: i = %d, w = %d, size = %d\n ", p.i, p.w, m.size);
		if (can_place(tab[p.i], m.map) == 0)
		{
	printf("backtrac2: i = %d, w = %d, size = %d\n ", p.i, p.w, m.size);
			put_in_map(tab[p.i], m.map);
			p.i++;
			m.size--;
		}
		else if (can_place(tab[p.i], m.map) == -1 && m.x++ != '\0')
			m.x++;
		else if (can_place(tab[p.i], m.map) == -1 && m.x++ == '\0' && m.map[m.y++][0] != '\0')
			{
				m.x = 0;
				m.y++;
			}
		}
		return (m.map);
}*/

int			c_ref(char **tab)        // pour touver premier caractere dans le tableau au raw 0
{
	int		c;

	c = 0;
	while (tab[0][c] == '.' && tab[0][c] != '\0')
		c++;
	printf("c_ref = %d\n", c);
	return (c);
}

char		**check_map(char ***tab) // fonction sur laquelle je travail actuelement (il y en a dans tous les sens.) pour eviter de la faire partir dans une boucle infini, et comme la fonction remove_piece ne marche pas je le test avec le fichier 2_tetris.. j'essaye de trouver une logique dans l'ordre avant de faire la recurssive, apre normalement on pourra enleve pas mal d'etape. Comme j'ai essaye plusieurs pistes avec des retour en arriere j'ai mis beaucoup de chose en silencieux.
{
	char	**map = NULL;    // pr map
//	int		x_start;
//	int		y_start;
	int		x;
	int		y;
	int		size;

	int		i;        //pour tab - trouver ou initialiser variables 
	int		r;
	int		c;
	int		w;
//	int		j; // first_r
	int		l; // c_ref

	x = 0;
	y = 0;
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
	x = 0;
	y = 0;
		print_tab(tab[i]);
		
//		printf("check_map_debut_while: i = %d, w = %d, size = %d, y = %d, x = %d, first_c(tab[i], (i + 65)) = %d\n ", i, w, size, y, x, first_c(tab[i], (i + 65)));
/*		while (map[y_start][x_start] != '.' && map[x_start][y_start] != '\0')
		{
			printf("check_map_debut_while_2: y_start = %d, x_start =  %d\n ", y_start, x_start);
			x_start++;
			if (map[y_start][x_start] == '\0' && map[y_start + 1][0] != '\0')
			{
				x_start = 0;
				y_start++;
			}
			printf("check_map_fin_while_2: y_start = %d, x_start =  %d\n ", y_start, x_start);
		}*/
		r = 0;
		printf("check_map_tab[i][r][c]: i = %d, r = %d, c = %d\n ", i, r, c);
//			printf("check_map_milieu_while_2: y = %d, x =  %d, c = %d, r = %d, i = %d, first_r(tab[i]) = %d, first_c(tab[i])= %d\n ", y, x, c, r, i, first_r(tab[i], (i + 65)), first_c(tab[i]), (i + 65));
		while (map[y][x] != '.' && map[y][x] != '\0')
		{
			x++;
			if (map[y][x] == '\0' && map[y + 1][0] != '\0')
			{
				x = 0;
				y++;
			}
		}
//			printf("check_map_milieu_while_2: y = %d, x =  %d, c = %d, r = %d, i = %d, first_r(tab[i]) = %d, first_c(tab[i])= %d\n ", y, x, c, r, i, first_r(tab[i]), first_c(tab[i]));
//			fflush(stdout);
		while (r < 4 && c < 4)
		{
			while (r < 4 && tab[i][r][c] != '\0')
			{
//				j = first_r(tab[i], (i + 65));
				l = c_ref(tab[i]);
				if ((tab[i][r][c] != '.' && tab[i][r][c] != '\0')
						&& (map[y + r][x + c - l] == '.'))
				{
					map[y + r][x + c - l] = i + 65;
					c++;
					printf("lalalalalalalala####     c = %d, x = %d, y = %d\n", c, x, y);
					if (tab[i][r][c] == (i + 65) && map[y + r][x + c - l] != '.')
					{
					printf("lalalalalalalala\n");
					print_tab(map);
						remove_piece(map, i);
						print_tab(map);
						while (map[y][x] != '.' && map[y][x] != '\0')
						{
							x++;
							if (map[y][x] == '\0' && map[y + 1][0] != '\0')
							{
								x = 0;
								y++;
							}
						}
						r = 0;
						c = 0;
					}
		//			let++;
				}
				else if (tab[i][r][c] == '.' && c < 4)
					c++;
			printf("check_map_milieu_while_3: y = %d, x =  %d, c = %d, r = %d, i = %d\n ", y, x, c, r, i);
				if (c == 4 && r < 4)
				{
					r++;
//					x--;
					c = 0;
//					y = 0;
			printf("check_map_milieu_change de rang: c_ref(tab[i]) = %d, y = %d, x =  %d, c = %d, r = %d, i = %d, i + 65 = %c\n ",c_ref(tab[i]),  y, x, c, r, i, (i + 65));
				}
			printf("check_map_fin_while_3: y = %d, x =  %d, c = %d, r = %d, i = %d\n ", y, x, c, r, i);
				print_tab(map);
			}
			if (map[y][x] == '\0')
			{
				x = 0;
				y++;
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
/*			if ((tab[i][r][c] != '.' && tab[i][r][c] != '\0') && (map[y][x] == '\0' || map[y][x] != '.')) //pb car i trop grand
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
			}*/
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
	print_tab(map);
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


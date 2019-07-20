/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:16:08 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/20 18:30:27 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
/*      dans fichier parsing.c
char		***parsing(int ac, char **av, char ***tab)
{
	int		fd;
	int i = 0;

	tab = NULL;
	if (ac == 2)                      //peut gagner place en mettant cette condition dans main
	{
		tab = init_big_tab(tab);
		fd = open(av[1], O_RDONLY);
		if (read_file(fd, tab) == 0)
		{
			while (tab[i])
			{
				if (check_valid_form(tab[i]) == 0)
					i++;
				else
				{
					ft_strdel(&**tab);
					return (NULL);
				}
			}
			tab = move_tetr_put_letter(tab);
		}
		else
		{
			ft_strdel(&**tab);                 //free ici ou qund je l'appelle plus tard?
			return (NULL);
		}
		close(fd);
	}
	return (tab);
}*/

void		return_error(char ***tab, char **map)
{
	ft_strdel(map);
	if (tab)
		free(tab);
	ft_putstr("error");
	ft_putchar('\n');
}

char		**remalloc_map(char **map, int *size)
{
	ft_strdel(map);
	*size = *size + 1;
	if (!(map = malloc_map(*size)))
		return (NULL);
	return (map);

}

void		execute_final(char ***tab, char **map)
{
	print_tab(map);
	if (tab)
		free(tab);
	ft_strdel(map);
}

int		main(int ac, char **av)
{
	char	***tab;
	char	**map;
	int		size;

	tab = NULL;
	map = NULL;
	tab = parsing(ac, av, tab);
	size = ft_approx_sqrt(count_tetris(tab) * 4);
	if (ac != 2 || tab == NULL)
	{
		return_error(tab, map);
		return (0);
	}
	if (!(map = malloc_map(size)))
		return (-1);
	while  (check_map(tab, map) == -1)
		if (!(map = remalloc_map(map, &size)))
				return (-1);;
	execute_final(tab, map);
	return (0);
}

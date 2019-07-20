/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_fillit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:54:55 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/20 20:29:54 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


void	print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

char		***init_big_tab(char ***tab)
{
	if (!(tab = (char***)malloc(sizeof(char**) * 27)))
		return (NULL);
	return (tab);
}

int		read_one(int fd)
{
	char	buf[1];
	int		rd;

	if ((rd = read(fd, buf, 1)) == 1)
	{
		if (buf[0] == '\n')
			return (1);
		else
			return (-1);
	}
	else if (rd == 0)
		return (0);
	else
		return (-1);
}

int			check_valid_tetris(char *s)		//structure t_specif
{
	int		i;
	int		pt;
	int		hash;
	int		back_n;

	i = 0;
	pt = 0;
	hash = 0;
	back_n = 0;
	while (s[i])
	{
		if (s[i] == '.')
			pt++;
		else if (s[i] == '#')
			hash++;
		else if (s[i] == '\n' && (i == 4 || i == 9 || i == 14 || i == 19))
			back_n++;
		else
			return (-1);
		i++;
	}
	if (pt == 12 && hash == 4 && back_n == 4)
		return (0);
	return (-1);
}

int			error_read(char ***tab, char *tmp)
{
	printf("error_read test1, tmp = %s\n", tmp);
	print_tab(*tab);
	ft_strdel(&tmp);
	printf("error_read test2\n");
	if (tab)
	{
		printf("error_read test3\n");
		free(tab);
	}
	return (-1);
}

int			read_file(int fd, char ***tab)			//structure t_read
{
	t_read	r;

	r.x = 0;
	r.ret1 = 1;
	while ((r.ret = read(fd, r.buf, BUFF_SIZE)) > 0 && r.x < 26 && r.ret1 == 1)
	{
		if (r.ret < 20 || r.ret < 0)
			return (-1);
		r.buf[r.ret] = '\0';
		r.tmp = ft_strdup(r.buf);
		if (check_valid_tetris(r.tmp) == -1)
			return (error_read(tab, r.tmp));
		if(!(tab[r.x] = ft_strsplit(r.tmp, '\n')))
			return (error_read(tab, r.tmp));
		r.x++;
		ft_strdel(&r.tmp);
		if ((r.ret1 = read_one(fd)) == -1)
			return (-1);
	}
	if (r.ret != 0 || (r.ret == 0 && r.ret1 != 0))
		return (error_read(tab, r.tmp));
	tab[r.x] = NULL;
	return (0);
}
// fonction mise dans fichier move_tet
/*
int		check_valid_form(char **tab)
{
	t_form	fom;

	fom.col = 0;
	fom.raw = 0;
	fom.connex = 0;
	while (fom.raw < 4 && fom.col < 4)
	{
		if (tab[fom.raw][fom.col] == '.' && fom.col < 3)
			fom.col++;
		if (tab[fom.raw][fom.col] == '#' && fom.col <= 3 && fom.raw <= 3)
		{
			if (fom.col > 0 && tab[fom.raw][fom.col - 1] == '#')
				fom.connex++;
			if (fom.col < 3 && tab[fom.raw][fom.col + 1] == '#')
				fom.connex++;
			if (fom.raw > 0 && tab[fom.raw - 1][fom.col] == '#')
				fom.connex++;
			if (fom.raw < 3 && tab[fom.raw + 1][fom.col] == '#')
				fom.connex++;
		}
		if (fom.raw == 3 && fom.col == 3 && fom.connex >= 6 && fom.connex < 9)
			return (0);
		if (fom.raw == 3 && fom.col == 3 && (fom.connex < 6 || fom.connex > 8))
			return (-1);
		if (fom.col == 3 && fom.raw < 3)
		{
			fom.col = 0;
			fom.raw++;
		}
		else
			fom.col++;
	}
	return (-1);
}*/
// fonction dans fichier main_fillit.c: 
/*
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
				if (check_valid_form(tab[i]) == 0)// && i < count_tetris(*tab))
//				{
//				print_tab(tab[i]);
					i++;
//					printf("i = %d\n", i);
//				}
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
/*
int		main(int ac, char **av)
{
	char	***tab;
	int		i = 0;

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
	return (0);
}*/                                   //  main ok, ca fontionne ici


/*
int		main(int ac, char **av)
{
	char ***tab;
	int fd;
	int		i = 0;

	tab = NULL;
	if (ac == 2)
	{
		tab = init_big_tab(tab);
		fd = open(av[1], O_RDONLY);
		if (read_file(fd, tab) == 0)
		{
			while (tab[i])
			{
				if (check_valid_form(tab[i]) == 0)
				{	
				printf("i = %d, check_valid_form = %d\n", i, check_valid_form(tab[i]));
				print_tab(tab[i]);
				printf("|||||||||||||||||\n");
				i++;
				}
			}
			i = 0;
			tab = move_tetr_put_letter(tab);
			while (tab[i])
			{
				print_tab(tab[i]);
				printf("|||||||||||||||||\n");
				i++;
			}
		}
		else
			printf("Piece invalide :(\n");
		close(fd);
	}
	return (0);
}*/

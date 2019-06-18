/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_fillit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:54:55 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/13 23:02:47 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	***move_tetr_put_letter(char ***tab);
int		count_tetris(char ***tab);

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

int			check_valid_tetris(char *s)
{
	t_specif	spe;

	spe.i = 0;
	spe.pt = 0;
	spe.hash = 0;
	spe.back_n = 0;
	while (s[spe.i])
	{
		if (s[spe.i] == '.')
			spe.pt++;
		else if (s[spe.i] == '#')
			spe.hash++;
		else if (s[spe.i] == '\n' && (spe.i == 4 || spe.i == 9 || spe.i == 14
					|| spe.i == 19))
			spe.back_n++;
		else
			return (-1);
		spe.i++;
	}
	printf("pt = %d, hash = %d, back_n = %d\n", spe.pt, spe.hash, spe.back_n);
	if (spe.pt == 12 && spe.hash == 4 && spe.back_n == 4)
		return (0);
	return (-1);
}

int			read_file(int fd, char ***tab)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		x;
	int		ret1;

	x = 0;
	ret1 = 1;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && x < 26 && ret1 == 1)
	{
		printf("ret read = %d\n", ret);
		if (ret < 20 || ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strdup(buf);
		if (check_valid_tetris(tmp) == -1)
			return (-1);
		if(!(tab[x] = ft_strsplit(tmp, '\n')))
		{
			ft_strdel(&tmp);
			return (-1);
		}
		print_tab(tab[x]);
		x++;
		ft_strdel(&tmp);
		if ((ret1 = read_one(fd)) == -1)
			return (-1);
		printf("ret read_one = %d\n", ret1);
		//		if (ret == 0)
		//			break ;
	}
	if (ret != 0 || (ret == 0 && ret1 != 0))
	{
		ft_strdel(&**tab);                      //bonne ecriture ??
		return (-1);
	}
	tab[x] = NULL;
	return (0);
	// a terme free avant de return -1
}

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
}

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
				{
				print_tab(tab[i]);
					printf("suis la %d\n", __LINE__);
					fflush(stdout);
					i++;
					printf("i = %d\n", i);
				}
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
}

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
}


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

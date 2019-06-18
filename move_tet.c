/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:57:26 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/12 21:25:28 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		count_tetris(char ***tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		first_i(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 3 && i <= 3)
	{
		while (tab[j][i] == '.' && j < 3)
			j++;
		if (tab[j][i] == '#')
			return (i);
		if (j == 3)
		{
			j = 0;
			i++;
		}
	}
	return (0);
}

int		first_j(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3 && j <= 3)
	{
		while (tab[j][i] == '.' && i < 3)
			i++;
		if (tab[j][i] == '#')
			return (j);
		if (i == 3)
		{
			i = 0;
			j++;
		}
	}
	return (0);
}

char			***move_tetr_put_letter(char ***tab)
{
	t_piece		piec;

	piec.w = 0;
	while (tab[piec.w])
	{
		piec.i = 0;
		piec.j = 0;
		piec.x = first_i(tab[piec.w]);
		piec.y = first_j(tab[piec.w]);
		while (piec.i < 4 && piec.j < 4)
		{
			if (tab[piec.w][piec.j][piec.i] == '.' && piec.i < 3)
				piec.i++;
			if (tab[piec.w][piec.j][piec.i] == '#')
			{
				tab[piec.w][piec.j][piec.i] = '.';
				tab[piec.w][piec.j - piec.y][piec.i - piec.x] = piec.w + 65;
			}
			if (piec.i == 3 && piec.j < 3)
			{
				piec.i = 0;
				piec.j++;
			}
			else
				piec.i++;
		}
		piec.w++;
	}
	return (tab);
}

/*tab = move_tetr(tab);*/

/* dans fonction precedente

char	***letter(char ***tab)
{
	int w;
	int raw;
	int col;

	w = 0;
	while (tab[w])
	{
		raw = 0;
		col = 0;
		while (raw < 4 && col < 4)
		{
			if (tab[w][raw][col] == '.' && col < 3)
				col++;
			if (tab[w][raw][col] == '#')
				tab[w][raw][col] = w + 65;
			if (col == 3 && raw < 3)
			{
				col = 0;
				raw++;
			}
			else
				col++;
		}
		w++;
	}
	return (tab);
}*/

/*
char	**malloc_map(char ***tab)
{
	int		size;
	char	**map;
	int		i;
	int		nb_p;

	nb_p = count_tetris(tab)
	size =  ft_sqrt(nb_p * 4);
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

char	**move_t_in_tab(char **tab)
{

}*/



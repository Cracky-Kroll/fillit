/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:57:26 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/10 17:43:37 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		first_i(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 3 && i <= 3)
	{
		while (tab[j][i] == '.')
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
		while (tab[j][i] == '.')
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

char	***move_tetr(char ***tab)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	w;

	w = 0;
	while (tab)
	{
		i = 0;
		j = 0;
		x = first_i(*tab);
		y = first_j(*tab);
		while (i <= 3 && j <= 3)
		{
			while (tab[w][j][i] == '.')
				i++;
			if (tab[w][j][i] == '#')
			{
				tab[w][j][i] = '.';
				tab[w][j - y][i - x] = '#';
			}
			if (i == 3)
			{
				i = 0;
				j++;
			}
		}
		w++;
	}
	return (tab);
}

void	letter(char ***tab)
{
	int w;
	int raw;
	int col;

	w = 0;
	raw = 0;
	col = 0;
	while (***tab)
	{
		while (raw < 4)
		{
			if (tab[w][raw][col] == '.')
				col++;
			if (tab[w][raw][col] == '#')
			{
				tab[w][raw][col] = w + 65;
				col++;
			}
			if (col == 3)
			{
				col = 0;
				raw++;
			}
		}
		w++;
	}
}

/*
char	**malloc_map(int nb_p)
{
	int		size;
	char	**map;
	int		i;

	nb_p = 
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



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:57:26 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/28 12:30:53 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_count_connex(char **tab, int *col, int *raw)
{
	int		connex;

	connex = 0;
	if (*col > 0 && tab[*raw][*col - 1] == '#')
		connex++;
	if (*col < 3 && tab[*raw][*col + 1] == '#')
		connex++;
	if (*raw > 0 && tab[*raw - 1][*col] == '#')
		connex++;
	if (*raw < 3 && tab[*raw + 1][*col] == '#')
		connex++;
	return (connex);
}

int			check_valid_form(char **tab)
{
	int		raw;
	int		col;
	int		connex;

	raw = 0;
	connex = 0;
	while (raw < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tab[raw][col] == '.' && col < 3)
				col++;
			if (tab[raw][col] == '#' && col <= 3 && raw <= 3)
				connex = ft_count_connex(tab, &col, &raw) + connex;
			if (raw == 3 && col == 3 && connex >= 6 && connex < 9)
				return (0);
			if (raw == 3 && col == 3 && (connex < 6 || connex > 8))
				return (-1);
			col++;
		}
		raw++;
	}
	return (-1);
}

int			count_tetris(char ***tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

int			first_c(char **tab, char h)
{
	int		c;
	int		r;

	c = 0;
	r = 0;
	while ((r < 3) && (c <= 3))
	{
		if (tab[r][c] == '.' && r < 3)
			r++;
		if (tab[r][c] == h)
			return (c);
		if (r == 3)
		{
			r = 0;
			c++;
		}
	}
	return (0);
}

int			first_r(char **tab, char h)
{
	int		c;
	int		r;

	c = 0;
	r = 0;
	while ((c < 3) && (r <= 3))
	{
		if (tab[r][c] == '.' && c < 3)
			c++;
		if (tab[r][c] == h)
			return (r);
		if (c == 3)
		{
			c = 0;
			r++;
		}
	}
	return (0);
}

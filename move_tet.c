/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:57:26 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/05 14:31:47 by ccarole          ###   ########.fr       */
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

int		first_c(char **tab, char h)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	while ((r < 3) && (c <= 3))
	{
		if (tab[r][c] == '.' && r < 3)
			r++;
		if (tab[r][c] == h)
		{ printf("first_c = %d\n", c);
			return (c);
		}
		if (r == 3)
		{
			r = 0;
			c++;
		}
	}
	return (0);
}

int		first_r(char **tab, char h)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	while ((c < 3) && (r <= 3))
	{
		if (tab[r][c] == '.' && c < 3)
			c++;
		if (tab[r][c] == h)
		{printf("first_r = %d\n", r);
			return (r);
		}
		if (c == 3)
		{
			c = 0;
			r++;
		}
	}
	return (0);
}

char			***move_tetr_put_letter(char ***tab)
{
	t_piece		piec;

	piec.i = 0;
	while (tab[piec.i])
	{
		piec.c = 0;
		piec.r = 0;
		piec.x = first_c(tab[piec.i], '#');
		printf("move_tetr_put_letter : first_c = %d\n", piec.x);
		piec.y = first_r(tab[piec.i], '#');
		while (piec.c < 4 && piec.r < 4)
		{
			if (tab[piec.i][piec.r][piec.c] == '.' && piec.c < 3)
				piec.c++;
			if (tab[piec.i][piec.r][piec.c] == '#')
			{
				tab[piec.i][piec.r][piec.c] = '.';
				tab[piec.i][piec.r - piec.y][piec.c - piec.x] = piec.i + 65;
			}
			if (piec.c == 3 && piec.r < 3)
			{
				piec.c = 0;
				piec.r++;
			}
			else
				piec.c++;
		}
		piec.i++;
	}
	return (tab);
}

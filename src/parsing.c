/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:54:12 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/29 19:58:33 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

int				len_map(char **map)
{
	int			n;

	n = 0;
	while (map[0][n] != '\0')
		n++;
	return (n);
}

char			***move_tetr_put_letter(char ***tab)
{
	t_piece		piec;

	piec.i = 0;
	while (tab[piec.i])
	{
		piec.r = 0;
		piec.x = first_c(tab[piec.i], '#');
		piec.y = first_r(tab[piec.i], '#');
		while (piec.r < 4)
		{
			piec.c = 0;
			while (piec.c < 4)
			{
				if (tab[piec.i][piec.r][piec.c] == '#')
				{
					tab[piec.i][piec.r][piec.c] = '.';
					tab[piec.i][piec.r - piec.y][piec.c - piec.x] = piec.i + 65;
				}
				piec.c++;
			}
			piec.r++;
		}
		piec.i++;
	}
	return (tab);
}

char			***parsing(char **av, char ***tab)
{
	int			fd;
	int			i;

	i = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		handle_error(tab, NULL);
	if (!(tab = init_big_tab(tab)))
		return (NULL);
	if (read_file(fd, tab) == 0)
	{
		while (tab[i])
		{
			if (check_valid_form(tab[i]) == 0)
				i++;
			else
				return (NULL);
		}
		tab = move_tetr_put_letter(tab);
	}
	else
		return (NULL);
	close(fd);
	return (tab);
}

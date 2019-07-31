/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:47:25 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/31 19:13:39 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_tab(char ***tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_strdel(&tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	(tab) ? free(tab) : 0;
}

void		free_map(char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
	{
		ft_strdel(&map[i]);
		i++;
	}
	(map) ? free(map) : 0;
}

void		handle_error(char ***tab, char **map)
{
	free_tab(tab);
	free_map(map);
	ft_putstr_fd("An error occured.\n", 2);
	exit(EXIT_FAILURE);
}

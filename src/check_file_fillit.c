/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_fillit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:54:55 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/31 20:13:41 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		***init_big_tab(char ***tab)
{
	if (!(tab = (char***)ft_memalloc(sizeof(char**) * 27)))
		return (NULL);
	return (tab);
}

int			read_one(int fd)
{
	char	buf[1];
	int		read_return;

	if ((read_return = read(fd, buf, 1)) == 1)
		return ((buf[0] == '\n') ? 1 : -1);
	return ((read_return == 0) ? 0 : -1);
}

int			check_valid_tetris(char *s)
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
	return ((pt == 12 && hash == 4 && back_n == 4) ? 0 : -1);
}

int			error_read(char *tmp)
{
	ft_strdel(&tmp);
	return (-1);
}

int			read_file(int fd, char ***tab)
{
	t_read	r;

	r.x = 0;
	r.ret1 = 1;
	r.tmp = NULL;
	while ((r.ret = read(fd, r.buf, BUFF_SIZE)) > 0 && r.x < 26 && r.ret1 == 1)
	{
		if (r.ret < 20)
			return (-1);
		r.buf[r.ret] = '\0';
		if (!(r.tmp = ft_strdup(r.buf)))
			return (-1);
		if (check_valid_tetris(r.tmp) == -1)
			return (error_read(r.tmp));
		if (!(tab[r.x] = ft_strsplit(r.tmp, '\n')))
			return (error_read(r.tmp));
		r.x++;
		ft_strdel(&r.tmp);
		if ((r.ret1 = read_one(fd)) == -1)
			return (-1);
	}
	if (r.ret != 0 || (r.ret == 0 && r.ret1 != 0))
		return (-1);
	tab[r.x] = NULL;
	return (0);
}

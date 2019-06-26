/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:06:44 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/26 21:14:12 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF_SIZE 20
# define ERROR		-1

typedef struct	s_specif
{
	int			i;
	int			pt;
	int			hash;
	int			back_n;
}				t_specif;

typedef struct	s_form
{
	int			raw;
	int			col;
	int			connex;
	int			w;
}				t_form;

typedef struct	s_piece
{
	int			x;
	int			y;
	int			c;//i;
	int			r;//j;
	int			i;//w;
	int			w;     // nb de tetris
}				t_piece;

typedef struct	s_map
{
	char		**map;
	int			x;
	int			y;
	int			size;
}				t_map;

void			print_tab(char **tab);
char			***init_big_tab(char ***tab);
int				read_one(int fd);
int				check_valid_tetris(char *s);
int				read_file(int fd, char ***tab);
int				check_valid_form(char **tab);
char			***parsing(int ac, char **av, char ***tab);
int				count_tetris(char ***tab);
int				first_c(char **tab, char h);
int				first_r(char **tab, char h);
char			***move_tetr_put_letter(char ***tab);

#endif

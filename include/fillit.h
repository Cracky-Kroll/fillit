/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:06:44 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/22 20:58:11 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define BUFF_SIZE 20

typedef struct	s_read				//malloc la structure et free
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		x;
	int		ret1;
}				t_read;
/*
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
}				t_form;*/

typedef struct	s_piece				//malloc la structure et free
{
	int			x;
	int			y;
	int			c;//i;
	int			r;//j;
	int			i;//w;
	int			w;     // nb de tetris
}				t_piece;
/*
typedef struct	s_map
{
	char		**map;
	int			x;
	int			y;
	int			size;
}				t_map;*/

char			***init_big_tab(char ***tab);			//fn dans check_file_fillit.c
int				read_one(int fd);
int				check_valid_tetris(char *s);
int				error_read(char ****tab, char **tmp);
int				read_file(int fd, char ***tab);
int				ft_count_connex(char **tab, int *col, int *raw);		//fn dans move_tet.c
int				check_valid_form(char **tab);
int				count_tetris(char ***tab);
int				first_c(char **tab, char h);
int				first_r(char **tab, char h);
void			print_tab(char **tab);									//fn dans parsing.c
char			***move_tetr_put_letter(char ***tab);
char			***parsing(int ac, char **av, char ***tab);
int				ft_approx_sqrt(int nb);							 //fn dans backtrack.c
char			**malloc_map(int size);
int				c_ref(char **tab);
int				check_map(char ***tab, char **map);
int				len_map(char **map);					//fn dans ptt_fn_back.c
int				can_place(char **map, char **tab, int x, int y);
void			put_in_map(char **tab, char **map, int x, int y);
void			new_x_y(char **map, int z, int j, int *x, int *y);
void			remove_piece(char **map, int i, int  *x, int *y);
void			return_error(char ***tab, char **map);				//fn dans main_fillit.c
char			**remalloc_map(char **map, int size);
void			execute_final(char ***tab, char **map);
int				main(int ac, char **av);
void			handle_error(char ***tab, char **map);
void		free_map(char **map);
void		free_tab(char ***tab);

#endif

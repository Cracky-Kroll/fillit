/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:06:44 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/12 21:17:57 by ccarole          ###   ########.fr       */
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
	int			i;
	int			j;
	int			w;
}				t_piece;

#endif

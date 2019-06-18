# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarole <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 17:02:46 by ccarole           #+#    #+#              #
#    Updated: 2019/06/13 20:32:58 by ccarole          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	
SRCN	=	
SRCS	=	$(addprefix $(SRCP), $(SRCN))
CC		=	gcc
OBJP	=	obj/
SRCP	=	./
OBJ		=	$(addprefix $(OBJP), $(SRCN:.c=.o))
FLAGS	=	-Wall -Wextra -Werror -I includes/
ARRC	=	ar rc

all: $(NAME)

$(NAME): $(LIB) //$(OBJP) $(OBJ)
//	$(ARRC) $(NAME) $(OBJ)
//	ranlib $(NAME)

//$(OBJP):
//	mkdir $(OBJP)

//$(OBJP)%.o : $(SRCP)%.c
//	$(CC) $(FLAGS) -o $@ -c $<

$(LIB):
	make -C libft re

clean:
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

test:
	gcc -g main.c && ./a.out

.PHONY: all clean fclean re

NAME		=	fillit

CC			=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR		=	./src/
SRCS		=	$(addprefix $(SRC_DIR), $(SRC)
SRC			=	check_file_fillit.c     \
				move_tet.c              \
				parsing.c               \
				ptt_fn_back.c           \
				backtrack.c             \
				main_fillit.c

OBJ_DIR		=	./obj/
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))
OBJ			=	$(SRC:.c=.o)

INC_DIR     =	./include/
INCS        =	$(addprefix $(INC_DIR), $(INC))
INC         =	fillit.h

all:			$(NAME)

$(NAME):        $(OBJ_DIR) $(OBJS)
				@make -C libft/
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft/ -lft

$(OBJ_DIR)%.o:  $(SRC_DIR)%.c $(INCS)
		    	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR):
		    	@mkdir -p $(OBJ_DIR)
clean:
				@make clean -C libft/
	    		@rm -f $(OBJS)
	    		@rm -rf $(OBJ_DIR)

fclean: 		clean
				@make fclean -C libft/
		    	@rm -f $(NAME)

re:				fclean all

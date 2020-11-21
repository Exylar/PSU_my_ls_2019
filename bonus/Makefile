##
## EPITECH PROJECT, 2019
## CPool_Day13_2019
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/my_ls.c	\
		src/option.c	\
		src/file.c	\
		src/my_ls_l.c	\
		src/my_rec_ls.c	\
		src/folder.c	\
		src/symlink.c	\
		src/file_in_params.c	\
		src/display_file.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy
	make -C lib/my clean

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

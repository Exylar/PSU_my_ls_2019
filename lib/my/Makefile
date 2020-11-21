##
## EPITECH PROJECT, 2019
## CPool_Day010_2019
## File description:
## Makefile
##

SRC 	=	my_atoi.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_is_prime.c	\
		my_isneg.c	\
		my_nbr_to_str.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putnbr_base.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_show_word_array.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isnum_or_neg.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_str_to_word_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcmp_by_char.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_realloc.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ./../
	mkdir -p ../../include
	cp my.h ../../include/

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ./../../include/my.h
	rm -f ./../$(NAME)

re:	fclean all

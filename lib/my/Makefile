$1;5202;0c##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##
NAME	=	libmy.a

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_show_word_array.c	\
		my_sort_int_arrray.c	\
		my_strcat.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strncat.c	\
		my_strncpy.c	\
		my_swap.c	\
		sum_stdarg.c	\
		disp_stdarg.c	\
		my_printf.c	\
		my_print_printable.c	\
		my_put_nbr_base.c	\
		my_put_unbr.c	\
		my_memset.c	\
		int_to_str.c	\
		my_show_int_array.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I include/ -I./lib/my/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar cr $(NAME)  $(OBJ)
	cp my.h ../../include
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re:	fclean	all

debug: 	$(OBJ)
	ar cr $(NAME)  $(OBJ)
	cp my.h ../../include
	cp $(NAME) ../

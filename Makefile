##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/my_ls.c	\
		src/init_struct.c	\
		src/my_strdup.c	\
		src/check_ls.c	\
		src/ls_l.c	\
		src/concate_files.c	\
		src/ls_rmaj.c	\
		src/get_total.c	\
		src/ls_d.c	\
		src/set_list.c	\
		src/ls_t.c	\

TESTS	=	src/my_ls.c	\
		src/init_struct.c	\
		src/my_strdup.c	\
		src/check_ls.c	\
		src/ls_l.c	\
		src/concate_files.c	\
		src/ls_rmaj.c	\
		src/get_total.c	\
		src/ls_d.c	\
		src/set_list.c	\
		src/ls_t.c	\
		tests/test_my_ls.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	=	-W -Wall -g3

CPPFLAGS	=	-I include/

LIB	=	-L ./ -lmy

UNITFLAGS	=	-lcriterion --coverage

EXECTESTS	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ)	$(LIB)

tests_run:
	make -C lib/
	$(CC) $(TESTS) $(CFLAGS) $(CPPFLAGS) $(LIB) $(UNITFLAGS) -o $(EXECTESTS)
	./$(EXECTESTS) && gcovr --branches --exclude tests/

clean:
	make clean -C lib/
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	make fclean -C lib/
	rm -f $(NAME)
	rm -f $(EXECTESTS)

re:	fclean all

.PHONY:	all clean fclean re

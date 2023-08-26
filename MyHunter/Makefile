##
## EPITECH PROJECT, 2022
## Hunter
## File description:
## Makefile
##

NAME	=	my_hunter

SRC	=	menu.c	\
		sprite.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	 my_hunter

FLAGS	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
		cd ../..
		gcc *.c -o $(NAME) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY	:	all clean fclean re

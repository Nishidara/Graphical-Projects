##
## EPITECH PROJECT, 2023
## B-MUL-200-LYN-2-1-myrpg-elias.abassi
## File description:
## Makefile
##

SRC_LIB	=	lib/my_putstr2.c	\
			lib/my_strlen.c	\
			lib/my_strncmp.c

SRC_MENU	=	menu/menu.c	\
				menu/exit.c	\
				menu/check_menu.c

SRC_MUSIC	=	music/music.c	\

SRC_OPTIONS	=	option/options.c	\
				option/check_option.c	\
				option/soundoff_bigscreen.c	\
				option/soundoff_smallscreen.c	\
				option/soundon_bigscreen.c	\
				option/soundon_smallscreen.c

SRC_GAME	=	gameplay/play.c	\
				gameplay/gameplay.c	\
				independant.c	\
				gameplay/player.c	\
				gameplay/player2.c	\
				gameplay/interaction.c	\
				gameplay/pause.c	\
				gameplay/map.c	\
				gameplay/inventory.c

SRC_BONUS	=	bonus/hover.c	\
				bonus/pressed.c	\
				bonus/pressed2.c	\
				bonus/rolling_menu.c	\
				bonus/rpg.c	\

ALL_SRC	=	$(SRC_LIB) $(SRC_MENU) $(SRC_MUSIC) $(SRC_OPTIONS) $(SRC_GAME)

NAME	=	 my_rpg

CFLAGS = -I./include -Wall -Wextra -W -g3

CFLAGS_SFML	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):
		cd ../..
		gcc $(ALL_SRC) -o $(NAME) $(CFLAGS) $(CFLAGS_SFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f coding-style-reports.log

re: fclean all

.PHONY:	all clean fclean re

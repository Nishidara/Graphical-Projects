/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** close
*/

#include "../include/menu.h"

int check_close(Menu_t *Menu)
{
    while (sfRenderWindow_pollEvent(Menu->window, &Menu->event)) {
        if (Menu->event.type == sfEvtClosed) {
            sfRenderWindow_close(Menu->window);
            return 1;
        }
    }
    return 0;
}

int check_if_click(Menu_t *Menu, Option_t *Option, Game_t *Game)
{
    if (if_click_exit(Menu) == 1)
        return 1;
    if (if_click_play(Menu, Option, Game) == 1)
        return 1;
    if (if_click_options(Menu, Game, Option) == 1)
        return 1;
    return 0;
}

int check_menu(Menu_t *Menu, Option_t *Option, Game_t *Game)
{
    while (sfRenderWindow_pollEvent(Menu->window, &Menu->event)) {
        if (Menu->event.type == sfEvtClosed) {
            sfRenderWindow_close(Menu->window);
            return 1;
        }
        if (Menu->event.type == sfEvtMouseButtonPressed) {
            check_if_click(Menu, Option, Game);
        }
    }
    return 0;
}

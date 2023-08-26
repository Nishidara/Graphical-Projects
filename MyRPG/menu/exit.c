/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** exit
*/

#include "../include/menu.h"

int if_click_exit(Menu_t *Menu)
{
    if (Menu->event.mouseButton.x > 1080 && Menu->event.mouseButton.x < 1130 \
&& Menu->event.mouseButton.y > 710 && Menu->event.mouseButton.y < 760) {
        sfRenderWindow_close(Menu->window);
        return 1;
    }
    return 0;
}

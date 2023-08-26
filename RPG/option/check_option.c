/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** check_option
*/

#include "../include/menu.h"

int size_options(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    Game->volume = 0.0f;
    sfMusic_setVolume(Game->music, Game->volume);

    if (Menu->event.mouseButton.x > 980 && Menu->event.mouseButton.x \
< 1110 && Menu->event.mouseButton.y > 365 && Menu->event.mouseButton.y < 480) {
        nosound_small(Menu, Game, Option);
        return 1;
    } else if (Menu->event.mouseButton.x > 820 && Menu->event.mouseButton.x \
< 940 && Menu->event.mouseButton.y > 360 && Menu->event.mouseButton.y < 480) {
        Game->volume = 100.0f;
        sfMusic_setVolume(Game->music, Game->volume);
        sound_big(Menu, Option);
        return 1;
    }
    return 1;
}

int sound_options(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 980 && Menu->event.mouseButton.x \
< 1110 && Menu->event.mouseButton.y > 365 && Menu->event.mouseButton.y < 480) {
        sound_big(Menu, Option);
        return 1;
    } else if (Menu->event.mouseButton.x > 820 && Menu->event.mouseButton.x \
< 940 && Menu->event.mouseButton.y > 360 && Menu->event.mouseButton.y < 480) {
        Game->volume = 0.0f;
        sfMusic_setVolume(Game->music, Game->volume);
        nosound_big(Menu, Game, Option);
        return 1;
    }
    return 1;
}

int all_options(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    if (click_nosound_big(Menu, Game, Option) == 1) {
        if (size_options(Menu, Game, Option) == 1)
            return 1;
    return 1;
    }
    if (click_sound_small(Menu, Option) == 1) {
        if (sound_options(Menu, Game, Option) == 1)
            return 1;
    return 1;
    }
    return 1;
}

int check_bis(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    if (Menu->event.type == sfEvtClosed) {
        sfRenderWindow_close(Menu->window);
        return 1;
    }
    if (Menu->event.type == sfEvtMouseButtonPressed) {
        if (all_options(Menu, Game, Option) == 1)
            return 1;
    }
    return 1;
}

int check_option(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    while (sfRenderWindow_pollEvent(Menu->window, &Menu->event)) {
        if (check_bis(Menu, Game, Option) == 1)
            return 1;
    }
    return 0;
}

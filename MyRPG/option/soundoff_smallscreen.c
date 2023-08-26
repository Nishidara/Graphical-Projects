/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** soundoff_smallscrenn
*/

#include "../include/menu.h"

void create_sprite_3(Menu_t *Menu, Option_t *Option)
{
    Option->Tnosound_small = SFTCF("sprite/optionS/nosoundsmall.png", NULL);
    Option->Snosound_small = sfSprite_create();
    sfSprite_setTexture(Option->Snosound_small, Option->Tnosound_small, sfTrue);
    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
}

int exit_nosoundsmall(Menu_t* Menu, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 1080 && Menu->event.mouseButton.x < 1130 \
&& Menu->event.mouseButton.y > 710 && Menu->event.mouseButton.y < 760) {
        sfTexture_destroy(Option->Tnosound_small);
        sfSprite_destroy(Option->Snosound_small);
        return 1;
    }
    return 0;
}

int nosound_small(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    Game->volume = 0.0f;
    sfMusic_setVolume(Game->music, Game->volume);

    create_sprite_3(Menu, Option);
    sfRenderWindow_clear(Menu->window, sfBlack);
    sfSprite_setPosition(Option->Snosound_small, Option->options_pos);
    sfSprite_setScale(Option->Snosound_small, Option->options_size);
    sfRenderWindow_drawSprite(Menu->window, Menu->Sbackground2, NULL);
    sfRenderWindow_drawSprite(Menu->window, Option->Snosound_small, NULL);
    sfRenderWindow_display(Menu->window);
    if (exit_nosoundsmall(Menu, Option) == 1)
        return 1;
    return 0;
}

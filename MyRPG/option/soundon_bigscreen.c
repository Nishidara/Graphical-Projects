/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** soundon_bigscreen
*/

#include "../include/menu.h"

void create_sprite_4(Menu_t *Menu, Option_t *Option)
{
    Option->Tsound_big = SFTCF("sprite/optionS/soundbig.png", NULL);
    Option->Ssound_big = sfSprite_create();
    sfSprite_setTexture(Option->Ssound_big, Option->Tsound_big, sfTrue);
    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
}

int exit_soundbig(Menu_t* Menu, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 1080 && Menu->event.mouseButton.x < 1130 \
&& Menu->event.mouseButton.y > 710 && Menu->event.mouseButton.y < 760) {
        sfTexture_destroy(Option->Tsound_big);
        sfSprite_destroy(Option->Ssound_big);
        return 1;
    }
    return 0;
}

int sound_big(Menu_t *Menu, Option_t *Option)
{
    create_sprite_4(Menu, Option);
    sfRenderWindow_clear(Menu->window, sfBlack);
    sfSprite_setPosition(Option->Ssound_big, Option->options_pos);
    sfSprite_setScale(Option->Ssound_big, Option->options_size);
    sfRenderWindow_drawSprite(Menu->window, Menu->Sbackground2, NULL);
    sfRenderWindow_drawSprite(Menu->window, Option->Ssound_big, NULL);
    sfRenderWindow_display(Menu->window);
    if (exit_soundbig(Menu, Option) == 1)
        return 1;
    return 0;
}

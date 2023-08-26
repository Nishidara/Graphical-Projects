/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** soundon_smallscreen
*/

#include "../include/menu.h"

void create_sprite_5(Menu_t *Menu, Option_t *Option)
{
    Option->Tsound_small = SFTCF("sprite/optionS/soundsmall.png", NULL);
    Option->Ssound_small = sfSprite_create();
    sfSprite_setTexture(Option->Ssound_small, Option->Tsound_small, sfTrue);
    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
}

int exit_soundsmall(Menu_t* Menu, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 1080 && Menu->event.mouseButton.x < 1130 \
&& Menu->event.mouseButton.y > 710 && Menu->event.mouseButton.y < 760) {
        sfTexture_destroy(Option->Tsound_small);
        sfSprite_destroy(Option->Ssound_small);
        return 1;
    }
    return 0;
}

int sound_small(Menu_t *Menu, Option_t *Option)
{
    create_sprite_5(Menu, Option);
    sfRenderWindow_clear(Menu->window, sfBlack);
    sfSprite_setPosition(Option->Ssound_small, Option->options_pos);
    sfSprite_setScale(Option->Ssound_small, Option->options_size);
    sfRenderWindow_drawSprite(Menu->window, Menu->Sbackground2, NULL);
    sfRenderWindow_drawSprite(Menu->window, Option->Ssound_small, NULL);
    sfRenderWindow_display(Menu->window);
    if (exit_soundsmall(Menu, Option) == 1)
        return 1;
    return 0;
}

int click_sound_small(Menu_t *Menu, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 980 && Menu->event.mouseButton.x < 1110 \
&& Menu->event.mouseButton.y > 365 && Menu->event.mouseButton.y < 480) {
        if (Menu->event.type == sfEvtMouseButtonPressed) {
            sound_small(Menu, Option);
            return 1;
        }
    }
    return 0;
}

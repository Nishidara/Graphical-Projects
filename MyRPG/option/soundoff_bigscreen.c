/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** switch_option
*/

#include "../include/menu.h"

void create_sprite_2(Menu_t *Menu, Option_t *Option)
{
    Option->Tnosound_big = SFTCF("sprite/optionS/nosoundbig.png", NULL);
    Option->Snosound_big = sfSprite_create();
    sfSprite_setTexture(Option->Snosound_big, Option->Tnosound_big, sfTrue);
    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
}

int exit_nosoundbig(Menu_t* Menu, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 1080 && Menu->event.mouseButton.x < 1130 \
&& Menu->event.mouseButton.y > 710 && Menu->event.mouseButton.y < 760) {
        sfTexture_destroy(Option->Tnosound_big);
        sfSprite_destroy(Option->Snosound_big);
        return 1;
    }
    return 0;
}

int nosound_big(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    Game->volume = 0.0f;
    sfMusic_setVolume(Game->music, Game->volume);

    create_sprite_2(Menu, Option);
    sfRenderWindow_clear(Menu->window, sfBlack);
    sfSprite_setPosition(Option->Snosound_big, Option->options_pos);
    sfSprite_setScale(Option->Snosound_big, Option->options_size);
    sfRenderWindow_drawSprite(Menu->window, Menu->Sbackground2, NULL);
    sfRenderWindow_drawSprite(Menu->window, Option->Snosound_big, NULL);
    sfRenderWindow_display(Menu->window);
    if (exit_nosoundbig(Menu, Option) == 1)
        return 1;
    return 0;
}

int click_nosound_big(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 820 && Menu->event.mouseButton.x < 940 \
&& Menu->event.mouseButton.y > 360 && Menu->event.mouseButton.y < 480) {
        if (Menu->event.type == sfEvtMouseButtonPressed) {
            nosound_big(Menu, Game, Option);
            return 1;
        }
    }
    return 0;
}

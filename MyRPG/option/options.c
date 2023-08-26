/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** options
*/

#include "../include/menu.h"

void create_sprite_1(Menu_t *Menu, Option_t *Option)
{
    Menu->Tbackground2 = SFTCF("sprite/menuS/background.jpg", NULL);
    Menu->Sbackground2 = sfSprite_create();
    Option->Toptions = SFTCF("sprite/optionS/soundbig.png", NULL);
    Option->Soptions = sfSprite_create();

    sfSprite_setTexture(Menu->Sbackground2, Menu->Tbackground2, sfTrue);
    sfSprite_setTexture(Option->Soptions, Option->Toptions, sfTrue);
    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
}

void put_options(Menu_t *Menu, Option_t *Option)
{
    sfVector2f option_pos = {772.5, 283};
    Option->options_pos = option_pos;
    sfVector2f option_size = {1.5, 1.5};
    Option->options_size = option_size;

    sfSprite_setPosition(Option->Soptions, Option->options_pos);
    sfSprite_setScale(Option->Soptions, Option->options_size);
    sfRenderWindow_drawSprite(Menu->window, Menu->Sbackground2, NULL);
    sfRenderWindow_drawSprite(Menu->window, Option->Soptions, NULL);
}

int exit_options(Menu_t* Menu, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 1080 && Menu->event.mouseButton.x < 1130 \
&& Menu->event.mouseButton.y > 710 && Menu->event.mouseButton.y < 760) {
        sfTexture_destroy(Menu->Tbackground2);
        sfSprite_destroy(Menu->Sbackground2);
        sfTexture_destroy(Option->Toptions);
        sfSprite_destroy(Option->Soptions);
        return 1;
    }
    return 0;
}

int options(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    create_sprite_1(Menu, Option);
    while (sfRenderWindow_isOpen(Menu->window)) {
        sfRenderWindow_setKeyRepeatEnabled(Menu->window, sfTrue);
        sfRenderWindow_clear(Menu->window, sfBlack);
        put_options(Menu, Option);
        check_option(Menu, Game, Option);
        sfRenderWindow_display(Menu->window);
        if (exit_options(Menu, Option) == 1)
            return 1;
    }
    return 0;
}

int if_click_options(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 840 && Menu->event.mouseButton.x < 1080 \
&& Menu->event.mouseButton.y > 515 && Menu->event.mouseButton.y < 580) {
        options(Menu, Game, Option);
        return 1;
    }
    return 0;
}

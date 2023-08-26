/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** pause
*/

#include "../include/menu.h"
#include "../include/gamephase.h"

void create_sprite_6(Menu_t *Menu, Game_t *Game)
{
    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
    Game->Tbackground2 = SFTCF("sprite/mapS/backgroundspawn.jpg", NULL);
    Game->Sbackground2 = sfSprite_create();
    Game->Tspawn2 = SFTCF("sprite/mapS/spawn.png", NULL);
    Game->Sspawn2 = sfSprite_create();
    Game->Tpause = SFTCF("sprite/gameplayS/pause.png", NULL);
    Game->Spause = sfSprite_create();
    sfSprite_setTexture(Game->Sspawn2, Game->Tspawn2, sfTrue);
    sfSprite_setTexture(Game->Sbackground2, Game->Tbackground2, sfTrue);
    sfSprite_setTexture(Game->Spause, Game->Tpause, sfTrue);
}

void destroy_pause(Game_t *Game)
{
    sfTexture_destroy(Game->Tpause);
    sfSprite_destroy(Game->Spause);
    sfTexture_destroy(Game->Tbackground2);
    sfSprite_destroy(Game->Sbackground2);
    sfTexture_destroy(Game->Tspawn2);
    sfSprite_destroy(Game->Sspawn2);
}

int exit_pause(Menu_t *Menu, Game_t *Game)
{
    if (Menu->event.mouseButton.x > 1080 && Menu->event.mouseButton.x < 1130 \
&& Menu->event.mouseButton.y > 710 && Menu->event.mouseButton.y < 760) {
        destroy_pause(Game);
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        destroy_pause(Game);
        return 1;
    }
    return 0;
}

int game_pause(Menu_t *Menu, Option_t *Option, Game_t *Game)
{
    create_sprite_6(Menu, Game);
    while (sfRenderWindow_isOpen(Menu->window)) {
        sfRenderWindow_setKeyRepeatEnabled(Menu->window, sfFalse);
        sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
        sfRenderWindow_clear(Menu->window, sfBlack);
        check_close(Menu);
        if_click_pause_options(Menu, Game, Option);
        sfSprite_setPosition(Game->Spause, Menu->menu_pos);
        sfSprite_setScale(Game->Spause, Menu->menu_size);
        sfRenderWindow_drawSprite(Menu->window, Game->Sbackground2, NULL);
        sfRenderWindow_drawSprite(Menu->window, Game->Sspawn2, NULL);
        sfRenderWindow_drawSprite(Menu->window, Game->Spause, NULL);
        sfRenderWindow_display(Menu->window);
        if (exit_pause(Menu, Game) == 1)
            return 1;
    }
    return 0;
}

int if_click_pause_options(Menu_t *Menu, Game_t *Game, Option_t *Option)
{
    if (Menu->event.mouseButton.x > 842 && Menu->event.mouseButton.x < 935 \
&& Menu->event.mouseButton.y > 461 && Menu->event.mouseButton.y < 559) {
        if (Menu->event.type == sfEvtMouseButtonPressed) {
        options(Menu, Game, Option);
        return 1;
        }
    }
    return 0;
}

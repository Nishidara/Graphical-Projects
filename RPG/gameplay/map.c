/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** map
*/

#include "../include/menu.h"
#include "../include/gamephase.h"

void create_sprite_7(Menu_t *Menu, Game_t *Game)
{
    Game->Tmap = SFTCF("sprite/mapS/map.jpg", NULL);
    Game->Smap = sfSprite_create();

    sfSprite_setTexture(Game->Smap, Game->Tmap, sfTrue);
    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
}

void map(Menu_t *Menu, Option_t *Option, Game_t *Game, player_t *Player)
{
    create_sprite_7(Menu, Game);
    while (sfRenderWindow_isOpen(Menu->window)) {
        sfRenderWindow_setKeyRepeatEnabled(Menu->window, sfFalse);
        check_close(Menu);
        player(Menu, Player);
        esc_button(Menu, Option, Game, Player);
        inventory(Menu, Player);
        sfRenderWindow_clear(Menu->window, sfBlack);
        sfRenderWindow_drawSprite(Menu->window, Game->Smap, NULL);
        sfRenderWindow_display(Menu->window);
    }
    return;
}

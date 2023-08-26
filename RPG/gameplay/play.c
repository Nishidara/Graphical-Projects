/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** play
*/

#include "../include/menu.h"
#include "../include/hover.h"
#include "../include/gamephase.h"

void key_binds(Menu_t *Menu, Option_t *Option, Game_t *Game, player_t *Player)
{
    player(Menu, Player);
    key(Menu, Game, Player);
    door(Menu, Option, Game, Player);
    esc_button(Menu, Option, Game, Player);
    inventory(Menu, Player);
}

void create_spawn(Game_t *Game)
{
    Game->Tbackground = SFTCF("sprite/mapS/backgroundspawn.jpg", NULL);
    Game->Sbackground = sfSprite_create();
    Game->Tspawn = SFTCF("sprite/mapS/spawn.png", NULL);
    Game->Sspawn = sfSprite_create();
    sfSprite_setTexture(Game->Sspawn, Game->Tspawn, sfTrue);
    sfSprite_setTexture(Game->Sbackground, Game->Tbackground, sfTrue);
}

int play(Menu_t *Menu, Option_t *Option, Game_t *Game)
{
    hover_t *hover = malloc(sizeof(hover_t));
    player_t *Player = malloc(sizeof(player_t));
    Player->key = false;

    create_spawn(Game);
    set_player(Player);
    while (sfRenderWindow_isOpen(Menu->window)) {
        sfRenderWindow_setKeyRepeatEnabled(Menu->window, sfFalse);
        sfRenderWindow_setMouseCursorVisible(Menu->window, sfFalse);
        check_close(Menu);
        sfRenderWindow_clear(Menu->window, sfBlack);
        sfRenderWindow_drawSprite(Menu->window, Game->Sbackground, NULL);
        sfRenderWindow_drawSprite(Menu->window, Game->Sspawn, NULL);
        key_binds(Menu, Option, Game, Player);
        sfRenderWindow_display(Menu->window);
    }
    free(hover);
    return 0;
}

int if_click_play(Menu_t *Menu, Option_t *Option, Game_t *Game)
{
    if (Menu->event.mouseButton.x > 840 && Menu->event.mouseButton.x < 1080 \
&& Menu->event.mouseButton.y > 335 && Menu->event.mouseButton.y < 400) {
            play(Menu, Option, Game);
            return 1;
        }
    return 0;
}

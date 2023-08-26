/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** invetory
*/

#include "../include/menu.h"
#include "../include/gamephase.h"

void show_items(Menu_t *Menu, player_t *Player)
{
    if (Player->key == true)
        sfRenderWindow_drawSprite(Menu->window, Player->key_sprite, NULL);
}

void create_sprite_9(Game_t *Game)
{
    Game->Txp = SFTCF("sprite/gameplayS/+50xp.png", NULL);
    Game->Sxp = sfSprite_create();
    Game->Tlevel = SFTCF("sprite/gameplayS/gglevel1.png", NULL);
    Game->Slevel = sfSprite_create();
    sfSprite_setTexture(Game->Sxp, Game->Txp, sfTrue);
    sfSprite_setTexture(Game->Slevel, Game->Tlevel, sfTrue);
}

void leveling_up(Menu_t *Menu, Game_t *Game)
{
    sfVector2f xp_pos = {1000, 750};
    sfVector2f xp_size = {0.5, 0.5};

    create_sprite_9(Game);
    sfRenderWindow_setKeyRepeatEnabled(Menu->window, sfFalse);
    sfSprite_setPosition(Game->Sxp, xp_pos);
    sfSprite_setPosition(Game->Slevel, Menu->menu_pos);
    sfSprite_setScale(Game->Sxp, xp_size);
    sfSprite_setScale(Game->Slevel, xp_size);
    sfRenderWindow_drawSprite(Menu->window, Game->Sxp, NULL);
    sfRenderWindow_drawSprite(Menu->window, Game->Slevel, NULL);
    sfRenderWindow_display(Menu->window);
}

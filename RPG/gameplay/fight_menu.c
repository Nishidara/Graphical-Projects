/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** fight_menu
*/
#include "../include/gamephase.h"
#include "../include/menu.h"

void display_background(Menu_t *menu, gamephase_t *game)
{
    game->Tbackground = SFTCF("../sprite/fight_bgrnd.png", NULL);
    game->Sbackground = sfSprite_create();
    sfVector2f scale = {1.45, 1.60};
    sfVector2f pos = {75, 105};

    sfSprite_setTexture(game->Sbackground, game->Tbackground, sfTrue);
    sfSprite_setPosition(game->Sbackground, pos);
    sfSprite_setScale(game->Sbackground, scale);

    sfRenderWindow_drawSprite(menu->window, game->Sbackground, NULL);
}

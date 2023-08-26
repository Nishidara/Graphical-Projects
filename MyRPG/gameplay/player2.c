/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** player2
*/
#include "../include/menu.h"
#include "../include/gamephase.h"

int check_input(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && player->pos_y >= 150) {
        player->rect.top = 0;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && player->pos_y <= 735) {
        player->rect.top = 128;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && player->pos_x >= 300) {
        player->rect.top = 64;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && player->pos_x <= 1350) {
        player->rect.top = 192;
        return 1;
    }
    return 0;
}

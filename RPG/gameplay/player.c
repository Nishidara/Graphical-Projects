/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** player
*/
#include "../include/menu.h"
#include "../include/gamephase.h"

void get_input(player_t *player)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(player->clock));
    int distance = player->speed * time;

    if (sfKeyboard_isKeyPressed(sfKeyZ) && player->pos_y >= 150) {
        player->pos_y -= distance;
        player->rect.top = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && player->pos_y <= 735) {
        player->pos_y += distance;
        player->rect.top = 128;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && player->pos_x >= 300) {
        player->pos_x -= distance;
        player->rect.top = 64;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && player->pos_x <= 1350) {
        player->pos_x += distance;
        player->rect.top = 192;
    }
}

void set_player(player_t *player)
{
    player->pos_x = 800; player->pos_y = 730; player->speed = 15;
    player->Tplayer = SFTCF("sprite/gameplayS/walk_sprite.png", NULL);
    player->Splayer = sfSprite_create();
    sfVector2f scale = {1.4, 1.4};
    player->scale = scale;
    sfVector2f pos = {player->pos_x, player->pos_y};
    player->pos = pos;
    sfIntRect rect = {0, 0, 64, 64};
    player->rect = rect;
    player->clock = sfClock_create();
    player->frame_time = 0.1;

    sfSprite_setTexture(player->Splayer, player->Tplayer, sfTrue);
    sfSprite_setPosition(player->Splayer, player->pos);
    sfSprite_setScale(player->Splayer, player->scale);
    sfSprite_setTextureRect(player->Splayer, player->rect);
}

void anim_player(player_t *player)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(player->clock));

    if (time >= player->frame_time) {
        player->rect.left += player->rect.width;
        if (player->rect.left >= 576) {
            player->rect.left = 0;
        }
        sfSprite_setTextureRect(player->Splayer, player->rect);
        sfClock_restart(player->clock);
    }
}

void destroy_player(player_t *player)
{
    sfTexture_destroy(player->Tplayer);
    sfSprite_destroy(player->Splayer);
    sfClock_destroy(player->clock);
}

void player(Menu_t *menu, player_t *player)
{
    sfVector2f pos = {player->pos_x, player->pos_y};
    player->pos = pos;

    get_input(player);
    if (check_input(player) == 1) {
        anim_player(player);
    }
    sfSprite_setPosition(player->Splayer, player->pos);
    sfRenderWindow_drawSprite(menu->window, player->Splayer, NULL);
}

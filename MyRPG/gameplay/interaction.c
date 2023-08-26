/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** bed_key
*/
#include "../include/menu.h"
#include "../include/gamephase.h"

void inventory(Menu_t *Menu, player_t *Player)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        show_items(Menu, Player);
    }
}

void key(Menu_t *Menu, Game_t *Game, player_t *Player)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && Player->pos_x >= 1100) {
        if (Player->pos_x <= 1400 && Player->pos_y >= 650 &&
                                            Player->pos_y <= 730) {
            Player->key_texture = SFTCF("sprite/gameplayS/key.png", NULL);
            Player->key_sprite = sfSprite_create();
            sfVector2f scale = {0.2, 0.2};
            sfVector2f pos = {1470, -50};

            sfSprite_setTexture(Player->key_sprite, Player->key_texture,
                                                                    sfTrue);
            sfSprite_setPosition(Player->key_sprite, pos);
            sfSprite_setScale(Player->key_sprite, scale);
            sfRenderWindow_drawSprite(Menu->window, Player->key_sprite, NULL);
            leveling_up(Menu, Game);
            Player->key = true;
        }
    }
}

void door(Menu_t *Menu, Option_t *Option, Game_t *Game, player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && player->pos_x >= 450) {
        if (player->pos_x <= 600 && player->pos_y >= 0 &&
                                player->pos_y <= 150 && player->key == true) {
            map(Menu, Option, Game, player);
        }
    }
}

void esc_button(Menu_t *Menu, Option_t *Option, Game_t *Game, player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (game_pause(Menu, Option, Game) == 0) {
            sfClock_restart(player->clock);
        }
    }
}

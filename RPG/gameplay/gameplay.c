/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** gameplay
*/
#include "../include/menu.h"
#include "../include/gamephase.h"

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

void display_fight_red(Menu_t *Menu, gamephase_t *game)
{
    game->Tred_box = SFTCF("../sprite/text_bubble_red.png", NULL);
    game->Sred_box = sfSprite_create();
    game->Tesc_button = SFTCF("../sprite/gameplayS/running_stickman.png", NULL);
    game->Sesc_button = sfSprite_create();
    sfVector2f scale = {1.45, 1.60};
    sfVector2f pos = {75, 105};

    sfSprite_setTexture(game->Sred_box, game->Tred_box, sfTrue);
    sfSprite_setPosition(game->Sred_box, pos);
    sfSprite_setScale(game->Sred_box, scale);

    sfSprite_setTexture(game->Sesc_button, game->Tesc_button, sfTrue);
    sfSprite_setPosition(game->Sesc_button, pos);
    sfSprite_setScale(game->Sesc_button, scale);

    sfRenderWindow_drawSprite(Menu->window, game->Sred_box, NULL);
    sfRenderWindow_drawSprite(Menu->window, game->Sesc_button, NULL);
}

void display_fight_red2(Menu_t *Menu, gamephase_t *game)
{
    game->Tred_atck = SFTCF("../sprite/gameplayS/rubis_sword", NULL);
    game->Sred_atck = sfSprite_create();
    game->Tred_spell = SFTCF("../sprite/gameplayS/red_fireball", NULL);
    game->Sred_spell = sfSprite_create();
    sfVector2f scale = {1.45, 1.60};
    sfVector2f pos = {75, 105};

    sfSprite_setTexture(game->Sred_atck, game->Tred_atck, sfTrue);
    sfSprite_setPosition(game->Sred_atck, pos);
    sfSprite_setScale(game->Sred_atck, scale);
    sfSprite_setTexture(game->Sred_spell, game->Tred_spell, sfTrue);
    sfSprite_setPosition(game->Sred_spell, pos);
    sfSprite_setScale(game->Sred_spell, scale);

    sfRenderWindow_drawSprite(Menu->window, game->Sred_atck, NULL);
    sfRenderWindow_drawSprite(Menu->window, game->Sred_spell, NULL);
}

void gamephase(Menu_t *Menu)
{
    gamephase_t *game = malloc(sizeof(gamephase_t));

    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
    while (sfRenderWindow_isOpen(Menu->window)) {
        check_close(Menu);
        sfRenderWindow_clear(Menu->window, sfBlack);
        display_background(Menu, game);
        display_fight_red(Menu, game);
        display_fight_red2(Menu, game);
        sfRenderWindow_display(Menu->window);
        sfRenderWindow_setKeyRepeatEnabled(Menu->window, sfFalse);
    }
}

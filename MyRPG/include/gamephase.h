/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** gamephase
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdbool.h>
#include "menu.h"

#ifndef GAMEPHASE_H_
    #define GAMEPHASE_H_

    #define SFRWCREATE sfRenderWindow_create
    #define SFTCF sfTexture_createFromFile

    typedef struct gamephase {
        sfTexture *Tbackground;
        sfSprite *Sbackground;
        sfTexture *Tesc_button;
        sfSprite *Sesc_button;

        sfTexture *Tred_box;
        sfSprite *Sred_box;
        sfTexture *Tred_atck;
        sfSprite *Sred_atck;
        sfTexture *Tred_spell;
        sfSprite *Sred_spell;

        sfTexture *Tblue_box;
        sfSprite *Sblue_box;
        sfTexture *Tblue_atck;
        sfSprite *Sblue_atck;
        sfTexture *Tblue_spell;
        sfSprite *Sblue_spell;
    } gamephase_t;

    typedef struct player {

        sfTexture *Tplayer;
        sfSprite *Splayer;
        sfIntRect rect;
        sfVector2f scale;
        sfVector2f pos;
        sfClock *clock;
        sfTexture *key_texture;
        sfSprite *key_sprite;

        float frame_time;
        int pos_x;
        int pos_y;
        int speed;

        bool key;

    } player_t;

    int check_input(player_t *);
    void key_binds(Menu_t *, Option_t *, Game_t *, player_t *);
    void leveling_up(Menu_t *Menu, Game_t *Game);
    void key(Menu_t *, Game_t *, player_t *);
    void door(Menu_t *, Option_t *, Game_t *, player_t *);
    void inventory(Menu_t *, player_t *);
    void show_items(Menu_t *, player_t *);

    void esc_button(Menu_t *, Option_t *, Game_t *, player_t *);
    int game_pause(Menu_t *, Option_t *, Game_t *);
    int if_click_pause_options(Menu_t *, Game_t *, Option_t *);

    void set_player(player_t *);
    void player(Menu_t *, player_t *);

    void map(Menu_t *, Option_t *, Game_t *, player_t *);

    void destroy_game(Game_t *, player_t *);
    void destroy_player(player_t *);

#endif /* !GAMEPHASE_H_ */

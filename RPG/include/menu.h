/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

    int my_putstr2(char *str);
    int my_strlen(char *str);
    int my_strncmp(char const *s1, char const *s2, int nb);

    #define SFRWCR sfRenderWindow_create
    #define SFTCF sfTexture_createFromFile
    #define SFSC sfSprite_create

    typedef struct Menu {
        sfRenderWindow *window;
        sfTexture *Tbackground;
        sfSprite *Sbackground;
        sfVector2f menu_pos;
        sfVector2f menu_size;
        sfTexture *Tmenu;
        sfSprite *Smenu;
        sfTexture *Tbackground2;
        sfSprite *Sbackground2;
        sfClock *clock;
        sfClock *clock2;
        sfTime time;
        float seconds;
        sfTime time2;
        float seconds2;
        sfEvent event;
    } Menu_t;

    typedef struct Option {
        sfTexture *Toptions;
        sfSprite *Soptions;
        sfVector2f options_pos;
        sfVector2f options_size;
        sfTexture *Tnosound_big;
        sfSprite *Snosound_big;
        sfTexture *Tnosound_small;
        sfSprite *Snosound_small;
        sfTexture *Tsound_big;
        sfSprite *Ssound_big;
        sfTexture *Tsound_small;
        sfSprite *Ssound_small;
        sfEvent evnt;
    } Option_t;

    typedef struct Game {
        sfRenderWindow *wndw;
        sfTexture *Tbackground;
        sfSprite *Sbackground;
        sfTexture *Tspawn;
        sfSprite *Sspawn;
        sfTexture *Tbackground2;
        sfSprite *Sbackground2;
        sfTexture *Tspawn2;
        sfSprite *Sspawn2;
        sfTexture *Tpause;
        sfSprite *Spause;
        sfTexture *Tmap;
        sfSprite *Smap;
        sfTexture *Tlevel;
        sfSprite *Slevel;
        sfTexture *Txp;
        sfSprite *Sxp;
        float volume;
        sfMusic* music;
        sfEvent evnt;
    } Game_t;

    void start_music(Game_t *);
    void put_menu(Menu_t *);
    int check_menu(Menu_t *, Option_t *, Game_t *);

    int check_close(Menu_t *);
    int if_click_play(Menu_t *, Option_t *, Game_t *);
    int if_click_options(Menu_t *, Game_t *, Option_t *);

    int options(Menu_t *Menu, Game_t *Game, Option_t *Option);
    int check_option(Menu_t *, Game_t *, Option_t *);
    int exit_options(Menu_t* , Option_t *);
    int click_nosound_big(Menu_t *, Game_t *, Option_t *);
    int nosound_big(Menu_t *, Game_t *, Option_t *);
    int nosound_small(Menu_t *, Game_t *, Option_t *);
    int sound_big(Menu_t *, Option_t *);
    int click_sound_small(Menu_t *, Option_t *);
    int sound_small(Menu_t *, Option_t *);

    int if_click_exit(Menu_t* );
    void destroy_menu(Menu_t *);
    void dash_h(void);

#endif /* !MENU_H_ */

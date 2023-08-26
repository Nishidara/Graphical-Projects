/*
** EPITECH PROJECT, 2022
** Hunter
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
        #include <SFML/Audio.h>
        #include <SFML/Graphics.h>
        #include <SFML/System/Export.h>
        #include <SFML/System/Time.h>
        #include <time.h>
        #include <SFML/System/Types.h>
        #include <stdlib.h>

        typedef struct display {
            sfRenderWindow* window;
            sfTexture* texture_back;
            sfSprite* sprite_back;
            sfTexture* texture_bow;
            sfSprite* sprite_bow;
            sfTexture* texture_link;
            sfSprite* sprite_link;
            sfTexture* texture_menu;
            sfSprite* sprite_menu;
            sfTexture* texture_start;
            sfSprite* sprite_start;
            sfTexture* texture_target;
            sfSprite* sprite_target;
            sfIntRect rect_link;
            sfClock* clock;
            sfClock* clock2;
            sfTime time;
            float seconds;
            sfTime time2;
            float seconds2;
            sfEvent event;
            sfVector2f link_pos;
        } display_t;

        typedef struct sound {
            sfMusic* music;
        } sound_t;

        int spawn_link (display_t *display, sfCursor* cursor, sfVideoMode mode);
        int if_click_start(display_t *display, sfVideoMode mode);
        void move_rect(display_t *display, int offset, int max_value);
        int shoot(display_t *display, sfCursor* cursor, sfVideoMode mode);
        int destroy (display_t *display, sfCursor* cursor);
        int start(display_t *display, sfCursor* cursor, sfVideoMode mode);
        int bow (display_t *display);
        int dash_h (display_t display);
        int my_putstr(char *str);

#endif /* !MY_HUNTER_H_ */

/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** hover
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

#ifndef HOVER_H_
    #define HOVER_H_

    typedef struct pressed {
        int black;
        int blue;
        int red;
        int green;
        int yellow;
        int pen;
        int eraser;
        int file;
        int color;
        int tool;
    } pressed_t;

    typedef struct hover {
        sfVector2f pos_black;
        sfVector2f pos_blue;
        sfVector2f pos_red;
        sfVector2f pos_green;
        sfVector2f pos_yellow;
        sfVector2f pos_pen;
        sfVector2f pos_eraser;
        sfVector2f pos_file;
        sfVector2f pos_color;
        sfVector2f pos_tool;
    } hover_t;

    void display_colors(sfRenderWindow *, hover_t *);
    void display_button(sfRenderWindow *, hover_t *);
    void interface(Menu_t *, hover_t *);
    void is_hover_button(sfVector2f pos);
    void is_hover(sfVector2f pos);
    void is_pressed(sfVector2f pos);
    void is_pressed2(sfVector2f pos);
    void display_file(sfRenderWindow *window, hover_t *);
    void set_pressed_zero(pressed_t *pressed);
    sfVector2f *fill_pos_list(hover_t *hover);
    void display_pressed(Menu_t *, pressed_t *, hover_t *);
    int click_file(Menu_t *, sfVector2f, pressed_t *);
    void display_roll_menu(sfRenderWindow *, hover_t *);

#endif /* !HOVER_H_ */

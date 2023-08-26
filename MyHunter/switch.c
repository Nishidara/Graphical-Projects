/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-elias.abassi
** File description:
** switch
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_hunter.h"

int if_click_start(display_t *display, sfVideoMode mode)
{
    sfCursor* cursor = sfCursor_createFromSystem(sfCursorCross);

    sfVector2i mouse = sfMouse_getPosition((sfWindow*) display->window);
    if (mouse.x > 750 && mouse.x < 1150 && mouse.y > 595 && mouse.y < 725)
        if (display->event.type == sfEvtMouseButtonPressed)
            start(display, cursor, mode);
}

void move_rect(display_t *display, int offset, int max_value)
{
    display->rect_link.left += offset;
    if (display->rect_link.left == max_value)
        display->rect_link.left = 0;
}

int destroy (display_t *display, sfCursor *cursor)
{
    sfCursor_destroy(cursor);
    sfSprite_destroy(display->sprite_menu);
    sfTexture_destroy(display->texture_menu);
    sfSprite_destroy(display->sprite_start);
    sfTexture_destroy(display->texture_start);
    sfSprite_destroy(display->sprite_back);
    sfTexture_destroy(display->texture_back);
    sfSprite_destroy(display->sprite_link);
    sfTexture_destroy(display->texture_link);
    sfClock_destroy(display->clock);
    sfClock_destroy(display->clock2);
    sfRenderWindow_destroy(display->window);
}

int dash_h (display_t display)
{
    my_putstr("rules \n");
}

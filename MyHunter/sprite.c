/*
** EPITECH PROJECT, 2022
** Hunter
** File description:
** sprite
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

int link_move(display_t *display)
{
display->link_pos = sfSprite_getPosition(display->sprite_link);
display->time2 = sfClock_getElapsedTime(display->clock2);
display->seconds2 = display->time2.microseconds / 1000000.0;
if (display->seconds2 > 0.005) {
    display->link_pos.x = (unsigned) (display->link_pos.x + 3) % (1820 - 100);
    display->link_pos.y = (unsigned) (display->link_pos.y + 3) % (980 - 100);
    sfClock_restart(display->clock2);
}
    sfSprite_setPosition(display->sprite_link, display->link_pos);
}

int move_sprite(display_t *display)
{
    display->rect_link.top = 735;
    display->rect_link.width = 90;
    display->rect_link.height = 100;
    display->time = sfClock_getElapsedTime(display->clock);
    display->seconds = display->time.microseconds / 1000000.0;
    if (display->seconds > 0.1) {
        move_rect(display, 97, 485);
        sfClock_restart(display->clock);
    }
    sfSprite_setTextureRect(display->sprite_link, display->rect_link);
}

int link_close(display_t *display)
{
    while (sfRenderWindow_pollEvent(display->window, &display->event)) {
            if (display->event.type == sfEvtClosed)
                sfRenderWindow_close(display->window);
        }
}

int spawn_link2(display_t *display, sfCursor* cursor, sfVideoMode mode)
{
    link_close(display);
    bow(display);
    sfRenderWindow_clear(display->window, sfBlack);
    sfRenderWindow_drawSprite(display->window, display->sprite_back, NULL);
    sfRenderWindow_drawSprite(display->window, display->sprite_link, NULL);
    sfRenderWindow_drawSprite(display->window, display->sprite_bow, NULL);
}

int spawn_link (display_t *display, sfCursor* cursor, sfVideoMode mode)
{
    display->texture_link =
    sfTexture_createFromFile("./sprite/link_sprite.png", NULL);
    sfVector2f bow_pos = {400, 980};
    sfVector2f bow_size = {0.5, 0.5};
    display->clock = sfClock_create();
    display->clock2 = sfClock_create();
    display->rect_link.left = 0;
    display->sprite_link = sfSprite_create();
    sfSprite_setTexture(display->sprite_link, display->texture_link, sfTrue);

    while (sfRenderWindow_isOpen(display->window)) {
        spawn_link2(display, cursor, mode);
        sfSprite_setScale(display->sprite_bow, bow_size);
        sfSprite_setPosition(display->sprite_bow, bow_pos);
        move_sprite(display);
        link_move(display);
        shoot(display, cursor, mode);
        sfRenderWindow_display(display->window);
    }
}

/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-elias.abassi
** File description:
** shoot_balle_dans_la_tete
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

int bow(display_t *display)
{
    display->texture_bow = sfTexture_createFromFile("./sprite/bow.png", NULL);

    display->sprite_bow = sfSprite_create();
    sfSprite_setTexture(display->sprite_bow, display->texture_bow, sfTrue);
}

int shoot(display_t *display, sfCursor* cursor, sfVideoMode mode)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow*) display->window);
    sfVector2i link_pos = {-90, -100};

if (display->event.type == sfEvtMouseButtonPressed)
    if (mouse.x > display->link_pos.x && mouse.x < display->link_pos.x + 100
    && mouse.y > display->link_pos.y && mouse.y < display->link_pos.y + 110){
        sfSprite_destroy(display->sprite_link);
        spawn_link(display, cursor, mode);
    }else {
        printf("raté !\n");
    }
}

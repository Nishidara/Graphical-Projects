/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** hover
*/

#include "include/menu.h"
#include "include/hover.h"

// void place_hover_sprite(paint_t *paint, sfVector2f pos)
// {
//     sfTexture *texture = SFCF("sprite/contour_button.png", NULL);
//     sfSprite *sprite = sfSprite_create();
//     sfVector2f scale = {1, 0.85};
//     sfVector2f position = {pos.x, pos.y};
//     sfSprite_setTexture(sprite, texture, sfTrue);
//     sfSprite_setPosition(sprite, position);
//     sfSprite_setScale(sprite, scale);

//     sfRenderWindow_drawSprite(paint->window, sprite, NULL);
// }

// void is_hover_button(paint_t *paint, sfVector2f pos)
// {
//     sfVector2i mouse_hov = sfMouse_getPosition((sfWindow *)paint->window);
//     if (mouse_hov.x > pos.x && mouse_hov.x < (pos.x + 200)) {
//         if (mouse_hov.y > pos.y && mouse_hov.y < (pos.y + 80)) {
//             place_hover_sprite(paint, pos);
//         }
//     }
// }

// void place_hover_sprite2(paint_t *paint, sfVector2f pos)
// {
//     sfTexture *texture = SFCF("sprite/contour.png", NULL);
//     sfSprite *sprite = sfSprite_create();
//     sfVector2f scale = {0.6, 0.6};
//     sfVector2f position = {pos.x - 6, pos.y - 6};
//     sfSprite_setTexture(sprite, texture, sfTrue);
//     sfSprite_setPosition(sprite, position);
//     sfSprite_setScale(sprite, scale);

//     sfRenderWindow_drawSprite(paint->window, sprite, NULL);
// }

// void is_hover(paint_t *paint, sfVector2f pos)
// {
//     sfVector2i mouse_hov = sfMouse_getPosition((sfWindow *)paint->window);
//     if (mouse_hov.x > pos.x && mouse_hov.x < (pos.x + 180)) {
//         if (mouse_hov.y > pos.y && mouse_hov.y < (pos.y + 65)) {
//             place_hover_sprite2(paint, pos);
//         }
//     }
// }

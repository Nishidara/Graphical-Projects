/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-elias.abassi
** File description:
** menu_back
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include "include/my_hunter.h"

int start_close(display_t *display)
{
    while (sfRenderWindow_pollEvent(display->window, &display->event)) {
            if (display->event.type == sfEvtClosed)
                sfRenderWindow_close(display->window);
        }
}

int start(display_t *display, sfCursor* cursor, sfVideoMode mode)
{
    sfRenderWindow_setMouseCursorVisible (display->window, sfFalse);
    display->texture_back = sfTexture_createFromFile("./sprite/back.png", NULL);
    sfRenderWindow_setMouseCursor(display->window, cursor);

    if (!display->texture_back)
    return EXIT_FAILURE;

    display->sprite_back = sfSprite_create();
    sfSprite_setTexture(display->sprite_back, display->texture_back, sfTrue);

    while (sfRenderWindow_isOpen(display->window)) {
        start_close(display);
        sfRenderWindow_clear(display->window, sfBlack);
        sfRenderWindow_display(display->window);
        spawn_link(display, cursor, mode);
        sfRenderWindow_setKeyRepeatEnabled(display->window, sfFalse);
    }
}

int create_menu(display_t *display)
{
sfVideoMode mode = {1920, 1800, 32};
sfVector2f start_pos = {740, 575};
sfVector2f start_size = {0.5, 0.5};

    display->window =
    sfRenderWindow_create(mode, "SFMLwindow", sfResize | sfClose, NULL);
    if (!display->window)
    return EXIT_FAILURE;

    sfRenderWindow_setMouseCursorVisible (display->window, sfTrue);
    display->texture_menu = sfTexture_createFromFile("sprite/back.jpg", NULL);
    display->texture_start = sfTexture_createFromFile("sprite/start.png", NULL);

    if (!display->texture_menu)
    return EXIT_FAILURE;

    display->sprite_menu = sfSprite_create();
    sfSprite_setTexture(display->sprite_menu, display->texture_menu, sfTrue);
    display->sprite_start = sfSprite_create();
    sfSprite_setTexture(display->sprite_start, display->texture_start, sfTrue);
}

int menu_close(display_t *display)
{
    while (sfRenderWindow_pollEvent(display->window, &display->event)) {
            if (display->event.type == sfEvtClosed)
                sfRenderWindow_close(display->window);
        }
}

int main(int ac, char **av, sfCursor* cursor, sfVideoMode mode)
{
display_t display;
sfVector2f start_pos = {740, 575};
sfVector2f start_size = {0.5, 0.5};

if (ac == 1){
    create_menu(&display);
    while (sfRenderWindow_isOpen(display.window)) {
        menu_close(&display);
        sfRenderWindow_clear(display.window, sfBlack);
        sfRenderWindow_drawSprite(display.window, display.sprite_menu, NULL);
        sfRenderWindow_drawSprite(display.window, display.sprite_start, NULL);
        sfSprite_setScale(display.sprite_start, start_size);
        sfSprite_setPosition(display.sprite_start, start_pos);
        sfRenderWindow_display(display.window);
        if_click_start(&display, mode);
    }
    destroy(&display, cursor);
} else if (av[1][0] == '-' && av[1][1] == 'h'){
    dash_h(display);
}
}

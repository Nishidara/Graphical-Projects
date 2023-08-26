/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** menu
*/

#include "../include/menu.h"

void create_menu(Menu_t *Menu)
{
    sfVideoMode mode = {1920, 1080, 32};

    Menu->window =
    sfRenderWindow_create(mode, "MyRpg", sfResize | sfClose, NULL);

    Menu->Tbackground = SFTCF("sprite/menuS/background.jpg", NULL);
    Menu->Sbackground = sfSprite_create();
    Menu->Tmenu = SFTCF("sprite/menuS/menufirst.png", NULL);
    Menu->Smenu = sfSprite_create();
    sfSprite_setTexture(Menu->Sbackground, Menu->Tbackground, sfTrue);
    sfSprite_setTexture(Menu->Smenu, Menu->Tmenu, sfTrue);
    sfRenderWindow_setMouseCursorVisible(Menu->window, sfTrue);
}

void put_menu(Menu_t *Menu)
{
    sfVector2f menu_pos = {772.5, 283};
    Menu->menu_pos = menu_pos;
    sfVector2f menu_size = {1.5, 1.5};
    Menu->menu_size = menu_size;

    sfSprite_setScale(Menu->Smenu, Menu->menu_size);
    sfSprite_setPosition(Menu->Smenu, Menu->menu_pos);
    sfRenderWindow_drawSprite(Menu->window, Menu->Sbackground, NULL);
    sfRenderWindow_drawSprite(Menu->window, Menu->Smenu, NULL);
}

int main(int ac, char **av)
{
    Menu_t Menu;
    Option_t Option;
    Game_t Game;

    if (ac == 1) {
        start_music(&Game);
        create_menu(&Menu);
        while (sfRenderWindow_isOpen(Menu.window)) {
            check_menu(&Menu, &Option, &Game);
            put_menu(&Menu);
            sfRenderWindow_display(Menu.window);
        }
        destroy_menu(&Menu);
        sfRenderWindow_destroy(Menu.window);
    } else if (my_strncmp(av[1], "-h", 2) == 0) {
        dash_h();
    }
    return 0;
}

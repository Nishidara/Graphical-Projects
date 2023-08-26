/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** independant
*/

#include "include/menu.h"
#include "include/gamephase.h"

void dash_h(void)
{
    my_putstr2("             <----------->\n\tBienvenue dans notre");
    my_putstr2(" RPG maison ! \nPour lancer le jeu taper simplement './my_rpg");
    my_putstr2("'. \nDans notre RPG toutes les touches par défaut sont");
    my_putstr2(" les mêmes que les autres RPGs. C'est à dire z,q,s,d et e po");
    my_putstr2("ur intéragir.\ntout vous sera expliquer au lancement du jeu.");
    my_putstr2(" \n\t\t Enjoy !\n             <----------->\n");
}

void destroy_game(Game_t *Game, player_t *player)
{
    sfTexture_destroy(Game->Tbackground);
    sfSprite_destroy(Game->Sbackground);
    sfTexture_destroy(Game->Tspawn);
    sfSprite_destroy(Game->Sspawn);
    sfTexture_destroy(Game->Txp);
    sfSprite_destroy(Game->Sxp);
    sfTexture_destroy(Game->Tlevel);
    sfSprite_destroy(Game->Slevel);
    sfMusic_destroy(Game->music);
    destroy_player(player);
}

void destroy_menu(Menu_t *Menu)
{
    sfTexture_destroy(Menu->Tbackground);
    sfSprite_destroy(Menu->Sbackground);
    sfTexture_destroy(Menu->Tmenu);
    sfSprite_destroy(Menu->Smenu);
}

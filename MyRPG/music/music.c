/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-elias.abassi
** File description:
** music
*/

#include "../include/menu.h"

void start_music(Game_t *Game)
{
    Game->music = sfMusic_createFromFile("music/rpgmusic.ogg");
    sfMusic_setLoop(Game->music, sfTrue);
    sfMusic_play(Game->music);

    Game->volume = 100.0f;
    sfMusic_setVolume(Game->music, Game->volume);
}

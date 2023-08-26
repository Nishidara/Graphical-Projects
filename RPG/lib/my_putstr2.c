/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-guylain.soubrier
** File description:
** my_putstr2
*/

#include <unistd.h>

int my_strlen(char *str);

int my_putstr2(char *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

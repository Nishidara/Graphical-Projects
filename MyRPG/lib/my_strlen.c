/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-guylain.soubrier
** File description:
** my_strlen
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int a = 0;
    while (str[a] != '\0') {
        a++;
    }
    return (a);
}

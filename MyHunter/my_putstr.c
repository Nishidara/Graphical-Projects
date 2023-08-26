/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-elias.abassi
** File description:
** my_putstr
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c);

int my_putstr(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return 0;
}

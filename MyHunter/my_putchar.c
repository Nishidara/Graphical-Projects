/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-elias.abassi
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

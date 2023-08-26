/*
** EPITECH PROJECT, 2022
** Jour6
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int nb)
{
    int a = 0;

    while (s1[a] != '\0' && a != nb) {
        if (s1[a] != s2[a]) {
            return (s2[a] - s1[a]);
        }
        a++;
    }
    a--;
    return (s1[a] - s2[a]);
}

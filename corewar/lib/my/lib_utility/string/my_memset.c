/*
** EPITECH PROJECT, 2021
** my_memset
** File description:
** my_memset
*/

#include "macro_and_define.h"

void *my_memset(void *s, int c, size_t n)
{
    char *ss = s;

    while (n) {
        *ss = (unsigned char) c;
        ss++;
        n--;
    }
    return s;
}
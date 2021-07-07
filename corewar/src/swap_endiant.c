/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** swap_endiant
*/

#include "swap.h"

int swap_endian_color(int color)
{
    union storage new = {color};
    char temp;

    temp = new.int_str[0];
    new.int_str[0] = new.int_str[3];
    new.int_str[3] = temp;
    temp = new.int_str[2];
    new.int_str[2] = new.int_str[1];
    new.int_str[1] = temp;
    return new.ARGB;
}
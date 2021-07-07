/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** byte_array_fonc
*/

#include "war/war_fonc.h"
#include "instruction_tab.h"

unsigned char *get_byte_array(int number, unsigned char bytes[])
{
    bytes[0] = (number >> 24) & 0xFF;
    bytes[1] = (number >> 16) & 0xFF;
    bytes[2] = (number >> 8) & 0xFF;
    bytes[3] = number & 0xFF;
    return bytes;
}
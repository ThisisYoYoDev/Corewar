/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** print_memory
*/

#include "lib_prototype.h"
#include "vm_struct.h"
#include "war/war_fonc.h"

void print_memory(unsigned char *memory, UNUSED char *proprio)
{
    for (int i = 0; i < MEM_SIZE; i += 1) {
        if (!(i % 32))
            my_printf("%-5X: ", i);
        my_printf("%.2X ", memory[i]);
        if (!((i + 1) % 32))
            write(1, "\n", 1);
    }
}
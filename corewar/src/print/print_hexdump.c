/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** print_hexdump
*/

#include "champ.h"
#include "lib_prototype.h"

void print_asm(char *buffer, unsigned int size)
{
    for (unsigned int i = 0; i < size; i += 1) {
        my_printf("%.2x ", (unsigned char)buffer[i]);
        if (!((i + 1) % 16))
            my_printf("\n");
    }
    my_printf("\n");
}

void print_header(headers_t *header)
{
    my_printf("%x\n", header->magic);
    print_asm(header->prog_name, PROG_NAME_LENGTH);
    my_printf("%x\n", header->prog_size);
    print_asm(header->comment, COMMENT_LENGTH);
}
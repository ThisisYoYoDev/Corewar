/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-nicolas.heude
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include "struct.h"
#include "champ.h"

void print_memory(unsigned char *memory, char *proprio);
void print_asm(char *buffer, unsigned int size);
void print_header(headers_t *header);
int  swap_endian_color(int color);
bool check_usage(int av, const char * const argv[]);

#endif /* !PROTOTYPE_H_ */

/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** grahical
*/

#include <ncurses.h>
#include "vm_struct.h"
#include "war/war_fonc.h"
#include "enable_lib.h"
#include "prototype.h"
#include "list.h"

void init_colors(void)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_CYAN, COLOR_CYAN);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
}

void display_character_with_color(int y, int x, vm_t *vm, int j)
{
    attron(COLOR_PAIR((int) vm->memory_proprio[j]));
    mvprintw(y, x, "%.2x", vm->memory[j]);
    attroff(COLOR_PAIR((int)vm->memory_proprio[j]));
}
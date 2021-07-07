/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** graphical
*/

#ifndef NCURSE_FONC_H_
#define NCURSE_FONC_H_

#include <ncurses.h>
#include "vm_struct.h"
#include "SFML/Audio.h"

#define WRITE_COREWAR_1 "    \
_____                                                       "

#define WRITE_COREWAR_2 " \
__|___  |__  _____  _____   ______  __  __  __  ____    _____  "

#define WRITE_COREWAR_3 "\
|   ___|    |/     \\|     | |   ___||  \\/  \\|  ||    \\  |     | "

#define WRITE_COREWAR_4 "\
|   |__     ||     ||     \\ |   ___||     /\\   ||     \\ |     \\ "

#define WRITE_COREWAR_5 "\
|______|  __|\\_____/|__|\\__\\|______||____/  \\__||__|\\__\\|__|\\__\\"

#define WRITE_COREWAR_6 "   \
|_____|                                                      "

void graphical_war_loop(vm_t *vm);
void init_colors(void);
void display_character_with_color(int y, int x, vm_t *vm, int j);
WINDOW *init_window(void);
void display_map(vm_t *vm, WINDOW *window);
sfMusic *init_theme(void);

#endif /* !NCURSE_FONC_H_ */
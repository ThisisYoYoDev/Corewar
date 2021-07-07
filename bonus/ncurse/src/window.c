/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** window_foncs
*/

#include <stddef.h>
#include <ncurses.h>
#include <stdio.h>
#include "vm_struct.h"
#include "war/war_fonc.h"
#include "enable_lib.h"
#include "prototype.h"
#include "list.h"
#include "ncurse_fonc.h"
#include "SFML/Audio.h"

WINDOW *init_window(void)
{
    WINDOW *window = initscr();

    window = newwin(66, 96 * 3 + 3, 0, COLS / 2 - (96 * 3 + 3) / 2);
    cbreak();
    noecho();
    timeout(1);
    curs_set(FALSE);
    clear();
    return window;
}

static void display_params(int y, vm_t *vm)
{
    mvprintw(y + 2, 20, "total cycles: %d", vm->total_cycles);
    mvprintw(y + 3, 20, "cycle_to_die:                                      ");
    mvprintw(y + 3, 20, "cycle_to_die: %d", vm->cycle_to_die);
    if (vm->last_alive) {
        mvprintw(y + 4, 20, "last champ who said live: %s",
            "                                                               ");
        mvprintw(y + 4, 20, "last champ who said live: %s",
            vm->last_alive->data.header.prog_name);
    }
    mvprintw(y + 6, 120, "%s", "\n      ___           ___           ___           ___           ___           ___           ___     \n     /\\__\\         /\\  \\         /\\  \\         /\\__\\         /\\  \\         /\\  \\         /\\  \\    \n    /:/  /        /::\\  \\       /::\\  \\       /:/ _/_       _\\:\\  \\       /::\\  \\       /::\\  \\   \n   /:/  /        /:/\\:\\  \\     /:/\\:\\__\\     /:/ /\\__\\     /\\ \\:\\  \\     /:/\\:\\  \\     /:/\\:\\__\\  \n  /:/  /  ___   /:/  \\:\\  \\   /:/ /:/  /    /:/ /:/ _/_   _\\:\\ \\:\\  \\   /:/ /::\\  \\   /:/ /:/  /  \n /:/__/  /\\__\\ /:/__/ \\:\\__\\ /:/_/:/__/___ /:/_/:/ /\\__\\ /\\ \\:\\ \\:\\__\\ /:/_/:/\\:\\__\\ /:/_/:/__/___\n \\:\\  \\ /:/  / \\:\\  \\ /:/  / \\:\\/:::::/  / \\:\\/:/ /:/  / \\:\\ \\:\\/:/  / \\:\\/:/  \\/__/ \\:\\/:::::/  /\n  \\:\\  /:/  /   \\:\\  /:/  /   \\::/~~/~~~~   \\::/_/:/  /   \\:\\ \\::/  /   \\::/__/       \\::/~~/~~~~ \n   \\:\\/:/  /     \\:\\/:/  /     \\:\\~~\\        \\:\\/:/  /     \\:\\/:/  /     \\:\\  \\        \\:\\~~\\     \n    \\::/  /       \\::/  /       \\:\\__\\        \\::/  /       \\::/  /       \\:\\__\\        \\:\\__\\    \n     \\/__/         \\/__/         \\/__/         \\/__/         \\/__/         \\/__/         \\/__/    \n");
}

void display_map(vm_t *vm, UNUSED WINDOW *window)
{
    int j = 0;
    int y = 3;

    for (; y <= 64; y += 1) {
        j += 1;
        for (int x = 4; x < 96 * 2 + 95; x += 1) {
            x += 1;
            display_character_with_color(y, x, vm, j);
            x += 1;
            j += 1;
        }
    }
    display_params(y, vm);
    refresh();
    usleep(100);
}